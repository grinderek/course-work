//
// Created by danila on 5.12.21.
//

#include "testing_service.h"

int testing(vector<Question_Many_Variants> questions) {
    int current = 0, right_answer = 0, all = questions.size();
    while(!questions.empty()) {
        cout << questions[current] << endl;
        auto answers = questions[current].getAnswers();
        int sz = answers.size();
        int correct_answer = questions[current].getCorrectAnswer();

        /*int x = 0;
        if (current > 0) {
            x++;
            cout << sz + x << " - " << "Следующий вопрос" << endl;
            if (current == sz - 1) {
                x++;
                cout << sz + x << " - " << "Предыдущий вопрос" << endl;
            }
        }*/

        int ans = getInt(1, sz);
        auto it = answers.begin() + ans - 1;

        ans = it->get_id();
        cout << ans << " " << it->get_text() << " " << correct_answer << endl;

        if (ans == correct_answer) {
            right_answer++;
        }

        questions.erase(questions.begin());
    }

    return round(10.0 * right_answer / all );
}

void testing_menu(int user_id, int group_id) {
    SqlGateway DB;
    string sql = "SELECT * FROM TESTS t"
                 " LEFT JOIN GROUP_TESTS g ON t.ID = g.TEST_ID"
                 " WHERE g.GROUP_ID = " + to_string(group_id);
    auto tests = DB.getData<Test>(sql);

    for (int i = 0; i < tests.size(); i++) {
        cout << "Тест №" << i + 1 << endl;
        cout << "Тема теста - " << tests[i].getName() << endl;
    }

    cout << "Выберите номер теста, который хотите пройти(0 для выхода)" << endl;
    int test_id = getInt(0, tests.size());

    if (test_id == 0) {
        return;
    } else {
        test_id--;
        Test test = tests[test_id];
        string sql = "SELECT * FROM QUESTIONS WHERE TEST_ID = " + to_string(test.getID());
        test.setQuestions(DB.getData<Question_Many_Variants>(sql));

        for (auto question : test.getQuestions()) {
            sql = "SELECT * FROM ANSWERS WHERE QUESTION_ID = " + to_string(question.getID());
            question.setAnswers(DB.getData<Answer>(sql));
            sql = "SELECT * FROM CORRECT_ANSWERS WHERE QUESTION_ID = " + to_string(question.getID());
            question.setCorrectAnswer(DB.getData<JustInt>(sql)[0].getVal());
        }

        int result = testing(test.getQuestions());
        DB.SQLOperation("INSERT INTO USERS_TESTS (MARK, USER_ID, TEST_ID) VALUES ("
                     + to_string(result) + ", "
                     + to_string(user_id) + ", "
                     + to_string(test.getID()) + ");");
        return;
    }
}

void show_results(int user_id) {
    SqlGateway DB;

    string sql = "SELECT * FROM TESTS t"
                 " LEFT JOIN USERS_TESTS g ON t.ID = g.TEST_ID"
                 " WHERE g.USER_ID = " + to_string(user_id);

    auto tests = DB.getData<Test>(sql);
    for (int i = 0; i < tests.size(); i++) {
        cout << "Тест №" << i + 1 << endl;
        cout << "Тема теста - " << tests[i].getName() << endl;
        sql = "SELECT MARK FROM USERS_TESTS WHERE "
              "USER_ID = " + to_string(user_id) +
              " AND TEST_ID = " + to_string(tests[i].getID()) + ";";
        int mark = DB.getData<JustInt>(sql)[0].getVal();
        cout << "Оценка - " << mark << endl;
    }
}