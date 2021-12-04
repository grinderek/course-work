//
// Created by danila on 30.11.21.
//

#include "tests_service.h"

void tests_menu(const User& user) {
    cout << "1 - Добавить тест" << endl;
    cout << "2 - Показать результаты теста" << endl;
    cout << "3 - Редактировать тест" << endl;
    cout << "4 - Удалить тест" << endl;
    cout << "0 - Вернуться назад" << endl;
    int op_men = getInt(0, 4);
    switch (op_men) {
        case 0:
            return;
        case 1:
            add_test(user);
            break;
        case 4:
            delete_test(user.getID());
            break;
        default:
            cout << "Что-то не так" << endl;
    }
}

void createTestsTable() {
    SQLOperation("CREATE TABLE IF NOT EXISTS TESTS ("
                "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                "NAME_OF_TEST TEXT NOT NULL, "
                "NUMBER_OF_QUESTIONS INTEGER NOT NULL, "
                "USER_ID INTEGER, "
                "  CONSTRAINT fk_users\n"
                "    FOREIGN KEY (USER_ID)\n"
                "    REFERENCES USERS (ID)\n"
                "    ON DELETE CASCADE);");
}

void add_test(const User& user) {
    cout << "Введите тему теста" << endl;
    string topic = getString();
    cout << "Введите кол-во вопросов" << endl;
    int count = getInt(1, INT_MAX);

    vector<Question_Many_Variants> questions;
    for (int i = 1; i <= count; i++) {
        cout << "Вопрос №" << i << endl;
        Question_Many_Variants question;
        cin >> question;
        questions.push_back(question);
    }

    cout << "Введите номера групп, для которых хотите открыть тест, по одной в строке(-1 для остановки)" << endl;
    vector <string> numbers_of_groups;
    while (true) {
        string s;
        cin >> s;
        if (s != "-1") {
            numbers_of_groups.push_back(s);
        } else {
            break;
        }
    }

    int id = add_test_to_table(topic, count, user.getID());
    cout << id << endl;
    add_questions_to_table(questions, id);
}

int add_test_to_table(const string& topic, int count, int user_id) {
    sqlite3 *DB;

    string sql = "INSERT INTO TESTS (NAME_OF_TEST, NUMBER_OF_QUESTIONS, USER_ID) VALUES ("
                 + quotesql(topic) + ","
                 + to_string(count) + ","
                 + to_string(user_id) + ");";

    try
    {
        int exit = 0;
        exit = sqlite3_open("test.db", &DB);
        cout << exit << " " << sql << endl;
        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK) {
            cerr << "Error Create Table" << endl;
            sqlite3_free(messageError);
        }
        else
            cout << "Table created successfully" << endl;
        int id = sqlite3_last_insert_rowid(DB);
        sqlite3_close(DB);
        return id;
    }
    catch (const exception & e)
    {
        cerr << e.what();
    }

    return -1;
}

vector<Test> get_tests(int user_id) {
    string sql = "SELECT * FROM TESTS WHERE USER_ID = " + to_string(user_id);
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
                vector<Question_Many_Variants> questions = getQuestions(test.getID());
                test.setQuestions(questions);
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

vector<Test> show_tests(int user_id) {
    vector<Test> tests = get_tests(user_id);

    for (auto test : tests) {
        cout << test;
    }

    return tests;
}

void delete_test(int user_id) {
    auto tests = show_tests(user_id);

    while (true) {
        cout << "Введите ID теста, который хотите удалить(0 для выхода)" << endl;
        int id = getInt(0, INT_MAX);

        if (id == 0) {
            return;
        } else {
            if (find_if(tests.begin(), tests.end(), [id](Test x){
                return x.getID() == id;
            }) != tests.end()) {
                cout << "Вы уверены, что хотите удалить этот тест?" << endl;
                cout << "1 - Да" << endl;
                cout << "2 - Нет" << endl;
                int x = getInt(1, 2);
                if (x == 1) {
                    string sql = "PRAGMA foreign_keys = ON;\n"
                                 "DELETE FROM TESTS WHERE ID = " + to_string(id)
                                 + ";\nPRAGMA foreign_keys = OFF;";

                    SQLOperation(sql);
                    break;
                } else {
                    continue;
                }
            }
            else {
                cout << "Теста с таким ID не существует" << endl;
            }
        }
    }
}