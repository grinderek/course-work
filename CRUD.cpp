//
// Created by danila on 28.11.21.
//
#include "CRUD.h"

int add_user(int role, int group_id) {
    string full_name;
    cout << "Введите ФИО" << endl;
    full_name = getString();

    string login;
    cout << "Введите логин" << endl;
    login = getString();

    string password;
    cout << "Введите пароль" << endl;
    password = getString();

    role = 2;

    string sql = "INSERT INTO USERS (FULL_NAME, LOGIN, PASSWORD, ROLE, GROUP_ID) VALUES ("
                 + quotesql(full_name) + ","
                 + quotesql(login) + ","
                 + quotesql(password) + ","
                 + to_string(role) + ","
                 + to_string(group_id) + ");";

    int id = SQLOperation(sql);
    return id;
}

User login() {
    SqlGateway DB;

    string login;
    cout << "Введите логин" << endl;
    login = getString();

    string password;
    cout << "Введите пароль" << endl;
    password = getString();

    string sql = "SELECT * FROM USERS WHERE "
                 "LOGIN = " + quotesql(login) +
                 " AND PASSWORD = " + quotesql(password) + ";";

    auto ans = DB.getData<User>(sql);
    if (!ans.empty()) {
        return ans[0];
    } else {
        return {};
    }
}