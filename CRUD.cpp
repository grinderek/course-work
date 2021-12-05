//
// Created by danila on 28.11.21.
//
#include "CRUD.h"

int add_user(int role) {
    string full_name;
    cout << "Введите ФИО" << endl;
    full_name = getString();

    string login;
    cout << "Введите логин" << endl;
    login = getString();

    string password;
    cout << "Введите пароль" << endl;
    password = getString();

    if (role == 0) {
        cout << "Введите роль" << endl;
        cout << "1 - Студент" << endl;
        cout << "2 - Преподователь" << endl;
        role = getInt(1, 2);
    }

    string sql = "INSERT INTO USERS (FULL_NAME, LOGIN, PASSWORD, ROLE) VALUES ("
                 + quotesql(full_name) + ","
                 + quotesql(login) + ","
                 + quotesql(password) + ","
                 + to_string(role) + ");";

    int id = SQLOperation(sql);
    return id;
}

User login() {
    string login;
    cout << "Введите логин" << endl;
    login = getString();

    string password;
    cout << "Введите пароль" << endl;
    password = getString();

    return authenticate(login, password);
}