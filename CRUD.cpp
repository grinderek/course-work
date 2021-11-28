//
// Created by danila on 28.11.21.
//
#include "CRUD.h"

void add_user() {
    string full_name;
    cout << "Введите ФИО" << endl;
    full_name = getString();

    string login;
    cout << "Введите логин" << endl;
    login = getString();

    string password;
    cout << "Введите пароль" << endl;
    password = getString();

    int role;
    cout << "Введите роль" << endl;
    cout << "1 - Студент" << endl;
    cout << "2 - Преподователь" << endl;
    role = getInt(1, 2);

    sqlite3* DB;

    string sql = "INSERT INTO USERS (FULL_NAME, LOGIN, PASSWORD, ROLE) VALUES ("
                 + quotesql(full_name) + ","
                 + quotesql(login) + ","
                 + quotesql(password) + ","
                 + to_string(role) + ");";

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
        sqlite3_close(DB);
    }
    catch (const exception & e)
    {
        cerr << e.what();
    }
}