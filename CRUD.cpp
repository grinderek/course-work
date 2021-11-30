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

    insertUserTable(full_name, login, password, role);
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