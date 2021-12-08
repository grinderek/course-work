//
// Created by danila on 28.11.21.
//
#include "CRUD.h"

int add_user(int role, int group_id) {
    SqlGateway DB;
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

    int id = DB.SQLOperation(sql);
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
        cout << "Здравствуйте, " << ans[0].getName() << endl;
        User* user;
        /*if (ans[0].getRole() == 1) {
            return new Student(ans[0].getID(), ans[0].getName(), ans[0].getRole(), ans[0].getGroupID());
        } else {
            return new Teacher(ans[0].getID(), ans[0].getName(), ans[0].getRole(), ans[0].getGroupID());
        }*/
        return ans[0];
    } else {
        return {};
    }
}