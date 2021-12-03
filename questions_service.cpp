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
                     + quotesql(answer) + ","
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