//
// Created by danila on 5.12.21.
//

#include "testing_service.h"

vector <Test> getTests(User user, string sql) {
    sqlite3 *DB;

    try
    {
        int exit = 0;
        exit = sqlite3_open("test.db", &DB);
        cout << exit << " " << sql << endl;
        char* messageError;
        vector<Test> tests;
        sqlite3_stmt *stmt;
        exit = sqlite3_prepare_v2(DB, sql.c_str(), sql.length(), &stmt, nullptr);

        if (exit != SQLITE_OK) {
            cerr << "Error Authenticate" << endl;
        }
        else {
            while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) {
                Test test;
                test.setID(sqlite3_column_int(stmt, 0));
                test.setName(string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
                tests.push_back(test);
            }
        }
        sqlite3_finalize(stmt);
        sqlite3_close(DB);

        return tests;
    }
    catch (const exception & e)
    {
        cerr << e.what();
        return {};
    }
}

double testing(vector<Question_Many_Variants> questions) {
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
        auto it = answers.begin();
        while (ans - 1 > 0) {
            it++;
            ans--;
        }

        ans = it->first;
        cout << ans << " " << it->second << endl;

        if (ans == correct_answer) {
            right_answer++;
        }

        questions.erase(questions.begin());
    }

    return 1.0 * right_answer / all;
}

void testing_menu(User user) {
    string sql = "SELECT * FROM TESTS t"
                 " LEFT JOIN GROUP_TESTS g ON t.ID = g.TEST_ID"
                 " WHERE g.GROUP_ID = " + to_string(user.getGroupID());
    auto tests = getTests(user, sql);

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
        test.setQuestions(getQuestions(test.getID()));

        for (auto question : test.getQuestions()) {
            question.setAnswers(getAnswers(question.getID()));
            question.setCorrectAnswer(getCorrectAnswer(question.getID()));
        }

        int result = round(testing(test.getQuestions()) * 10);
        SQLOperation("INSERT INTO USERS_TESTS (MARK, USER_ID, TEST_ID) VALUES ("
                     + to_string(result) + ", "
                     + to_string(user.getID()) + ", "
                     + to_string(test.getID()) + ");");
        return;
    }
}

int getMark(Test test, User user) {
    sqlite3 *DB;
    string sql = "SELECT MARK FROM USERS_TESTS WHERE "
                 "USER_ID = " + to_string(user.getID()) +
                 " AND TEST_ID = " + to_string(test.getID()) + ";";
    try
    {
        int exit = 0;
        exit = sqlite3_open("test.db", &DB);
        cout << exit << " " << sql << endl;
        char* messageError;
        int mark;
        sqlite3_stmt *stmt;
        exit = sqlite3_prepare_v2(DB, sql.c_str(), sql.length(), &stmt, nullptr);

        if (exit != SQLITE_OK) {
            cerr << "Error Authenticate" << endl;
        }
        else {
            while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) {
                mark = sqlite3_column_int(stmt, 0);
            }
        }
        sqlite3_finalize(stmt);
        sqlite3_close(DB);

        return mark;
    }
    catch (const exception & e)
    {
        cerr << e.what();
        return 0;
    }

    return 0;
}

void show_results(User user) {
    string sql = "SELECT * FROM TESTS t"
                 " LEFT JOIN USERS_TESTS g ON t.ID = g.TEST_ID"
                 " WHERE g.USER_ID = " + to_string(user.getID());

    auto tests = getTests(user, sql);
    for (int i = 0; i < tests.size(); i++) {
        cout << "Тест №" << i + 1 << endl;
        cout << "Тема теста - " << tests[i].getName() << endl;
        int mark = getMark(tests[i], user);
        cout << "Оценка - " << mark << endl;
    }
}