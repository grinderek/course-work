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
}