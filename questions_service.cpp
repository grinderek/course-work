//
// Created by danila on 2.12.21.
//

#include "questions_service.h"

int add_correctAnswer_to_table(int answer_id, int question_id) {
    SqlGateway DB;
    string sql = "INSERT INTO CORRECT_ANSWERS (ANSWER_ID, QUESTION_ID) VALUES ("
                 + to_string(answer_id) + ","
                 + to_string(question_id) + ");";

    int id = DB.SQLOperation(sql);

    return id;
}

int add_answers_to_table(Question question, int question_id) {
    SqlGateway DB;
    int num = 0;
    for (auto answer : question.getAnswers()) {
        string sql = "INSERT INTO ANSWERS (TEXT_OF_ANSWER, QUESTION_ID) VALUES ("
                     + quotesql(answer.get_text()) + ","
                     + to_string(question_id) + ");";

        int id = DB.SQLOperation(sql);

        if (num == question.getCorrectAnswer()) {
            add_correctAnswer_to_table(id, question_id);
            num = -2e9;

        }

        num++;
    }
}

int add_questions_to_table(vector<Question> questions, int test_id) {
    SqlGateway DB;
    for (auto question : questions) {
        string sql = "INSERT INTO QUESTIONS (TEXT_OF_QUESTION, TEST_ID) VALUES ("
                     + quotesql(question.getQuestion()) + ","
                     + to_string(test_id) + ");";

        int id = DB.SQLOperation(sql);
        add_answers_to_table(question, id);
    }
}

void showQuestions(vector<Question> questions) {
    int i = 1;
    for (auto question : questions) {
        cout << "Вопрос №" << i++ << endl;
        cout << question << endl;
    }
}

void changeAnswers(Question question) {
    SqlGateway DB;
    string sql = "SELECT * FROM ANSWERS WHERE QUESTION_ID = " + to_string(question.getID());
    int j = 1;
    auto answers = DB.getData<Answer>(sql);
    map <int, int> ids;
    map <int, int> rev_ids;
    for ( auto answer : answers) {
        ids[answer.get_id()] = j;
        rev_ids[j - 1] = answer.get_id();
        cout << j++ << " - " << answer.get_text() << endl;
    }

    cout << "Правильный ответ - " << ids[question.getCorrectAnswer()] << endl;

    while (true) {
        cout << "Введите номер ответа, который хотите изменить(0 для выхода)" << endl;
        int id = getInt(0, j - 1);

        if (id == 0) {
            return;
        } else {
            id--;
            cout << answers[rev_ids[id]].get_text() << endl;
            cout << "Что вы хотите изменить?" << endl;
            cout << "1 - Текст ответа" << endl;
            cout << "0 - Выход" << endl;
            int op_menu = getInt(0, 1);

            switch (op_menu) {
                case 0:
                    continue;
                case 1: {
                    cout << "Введите новый ответ" << endl;
                    string text = getString();
                    cout << "Вы уверены, что хотите сохраните изменения?" << endl;
                    cout << "1 - Да" << endl;
                    cout << "2 - Нет" << endl;
                    int x = getInt(1, 2);
                    if (x == 1) {
                        string sql = "PRAGMA foreign_keys = ON;\n"
                                     "UPDATE ANSWERS SET TEXT_OF_ANSWER = " + quotesql(text) + " WHERE ID = " +
                                     to_string(rev_ids[id]) + ";\nPRAGMA foreign_keys = OFF;";
                        DB.SQLOperation(sql);
                        break;
                    } else {
                        continue;
                    }
                }
                    break;
                default:
                    cout << "Что-то пошло не так" << endl;
            }
        }
    }
}


void changeQuestions(vector<Question> questions) {
    SqlGateway DB;
    showQuestions(questions);

    while (true) {
        cout << "Введите номер вопроса, который хотите изменить(0 для выхода)" << endl;
        int id = getInt(0, questions.size());

        if (id == 0) {
            return;
        } else {
            id--;
            cout << questions[id] << endl;
            cout << "Что вы хотите изменить?" << endl;
            cout << "1 - Текст вопроса" << endl;
            cout << "2 - Ответы" << endl;
            cout << "0 - Выход" << endl;
            int op_menu = getInt(0, 2);

            switch (op_menu) {
                case 0:
                    continue;
                case 1: {
                    cout << "Введите новый вопрос" << endl;
                    string text = getString();
                    cout << "Вы уверены, что хотите сохраните изменения?" << endl;
                    cout << "1 - Да" << endl;
                    cout << "2 - Нет" << endl;
                    int x = getInt(1, 2);
                    if (x == 1) {
                        string sql = "PRAGMA foreign_keys = ON;\n"
                                     "UPDATE QUESTIONS SET TEXT_OF_QUESTION = " + quotesql(text) + " WHERE ID = " +
                                     to_string(questions[id].getID()) + ";\nPRAGMA foreign_keys = OFF;";
                        DB.SQLOperation(sql);
                        break;
                    } else {
                        continue;
                    }
                }
                    break;
                case 2:
                    changeAnswers(questions[id]);
                    break;
                default:
                    cout << "Что-то пошло не так" << endl;
            }
        }
    }
}