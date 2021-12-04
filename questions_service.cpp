//
// Created by danila on 2.12.21.
//

#include "questions_service.h"

int add_questions_to_table(vector<Question_Many_Variants> questions, int test_id) {
    for (auto question : questions) {
        sqlite3 *DB;

        string sql = "INSERT INTO QUESTIONS (TEXT_OF_QUESTION, TEST_ID) VALUES ("
                     + quotesql(question.getQuestion()) + ","
                     + to_string(test_id) + ");";

        int id = SQLOperation(sql);
        add_answers_to_table(question, id);
    }
}

int add_answers_to_table(Question_Many_Variants question, int question_id) {
    int num = 0;
    for (const auto& answer : question.getAnswers()) {
        string sql = "INSERT INTO ANSWERS (TEXT_OF_ANSWER, QUESTION_ID) VALUES ("
                     + quotesql(answer.second) + ","
                     + to_string(question_id) + ");";

        int id = SQLOperation(sql);

        if (num == question.getCorrectAnswer()) {
            add_correctAnswer_to_table(id, question_id);
            num = -2e9;

        }

        num++;
    }
}

int add_correctAnswer_to_table(int answer_id, int question_id) {
    string sql = "INSERT INTO CORRECT_ANSWERS (ANSWER_ID, QUESTION_ID) VALUES ("
                 + to_string(answer_id) + ","
                 + to_string(question_id) + ");";

    int id = SQLOperation(sql);

    return id;
}

vector<Question_Many_Variants> getQuestions(int test_id) {
    sqlite3 *DB;

    string sql = "SELECT * FROM QUESTIONS WHERE TEST_ID = " + to_string(test_id);

    try
    {
        int exit = 0;
        exit = sqlite3_open("test.db", &DB);
        cout << exit << " " << sql << endl;
        char* messageError;
        vector<Question_Many_Variants> questions;
        sqlite3_stmt *stmt;
        exit = sqlite3_prepare_v2(DB, sql.c_str(), sql.length(), &stmt, nullptr);

        if (exit != SQLITE_OK) {
            cerr << "Error Authenticate" << endl;
        }
        else {
            while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) {
                Question_Many_Variants question;
                question.setID(sqlite3_column_int(stmt, 0));
                question.setQuestionText(string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
                map <int, string> answers = getAnswers(question.getID());
                question.setAnswers(answers);
                int id_answer = getCorrectAnswer(question.getID());
                question.setCorrectAnswer(id_answer);
                questions.push_back(question);
            }
        }
        sqlite3_finalize(stmt);
        sqlite3_close(DB);

        return questions;
    }
    catch (const exception & e)
    {
        cerr << e.what();
        return {};
    }
}

map <int, string> getAnswers(int question_id) {
    sqlite3 *DB;

    string sql = "SELECT * FROM ANSWERS WHERE QUESTION_ID = " + to_string(question_id);

    try
    {
        int exit = 0;
        exit = sqlite3_open("test.db", &DB);
        cout << exit << " " << sql << endl;
        char* messageError;
        map <int, string> answers;
        sqlite3_stmt *stmt;
        exit = sqlite3_prepare_v2(DB, sql.c_str(), sql.length(), &stmt, nullptr);

        if (exit != SQLITE_OK) {
            cerr << "Error Authenticate" << endl;
        }
        else {
            while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) {
                answers[sqlite3_column_int(stmt, 0)] = string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
            }
        }
        sqlite3_finalize(stmt);
        sqlite3_close(DB);

        return answers;
    }
    catch (const exception & e)
    {
        cerr << e.what();
        return {};
    }
}

int getCorrectAnswer(int question_id) {
    sqlite3 *DB;

    string sql = "SELECT * FROM CORRECT_ANSWERS WHERE QUESTION_ID = " + to_string(question_id);

    try
    {
        int exit = 0;
        exit = sqlite3_open("test.db", &DB);
        cout << exit << " " << sql << endl;
        char* messageError;
        int correct_answer = 0;
        sqlite3_stmt *stmt;
        exit = sqlite3_prepare_v2(DB, sql.c_str(), sql.length(), &stmt, nullptr);

        if (exit != SQLITE_OK) {
            cerr << "Error Authenticate" << endl;
        }
        else {
            while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) {
                correct_answer = sqlite3_column_int(stmt, 1);
            }
        }
        sqlite3_finalize(stmt);
        sqlite3_close(DB);

        return correct_answer;
    }
    catch (const exception & e)
    {
        cerr << e.what();
        return {};
    }
}