//
// Created by danila on 28.11.21.
//
#include "Authorization.h"

int Authorization::add_user(int role, int group_id) {
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

    string secret_password = "No one gonna know";
    if (role == 2) {
        cout << "Введите секретный пароль для регистрации" << endl;
        if (getString() != secret_password) {
            cout << "Неверный секретный пароль" << endl;
            return -1;
        }
    }

    string sql = "INSERT INTO USERS (FULL_NAME, LOGIN, PASSWORD, ROLE, GROUP_ID) VALUES ("
                 + quotesql(full_name) + ","
                 + quotesql(login) + ","
                 + quotesql(password) + ","
                 + to_string(role) + ","
                 + to_string(group_id) + ");";

    cout << "Пользователь успешно зарегестрирован" << endl;
    int id = DB.SQLOperation(sql);
    return id;
}


vector<unique_ptr<User>> Authorization::login() {
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

    vector<unique_ptr<User>> user;
    auto ans = DB.getData<User>(sql);
    if (!ans.empty()) {
        cout << "Здравствуйте, " << ans[0].getName() << endl;
        if (ans[0].getRole() == 1) {
            user.emplace_back(new Student(ans[0].getID(), ans[0].getName(), ans[0].getRole(), ans[0].getGroupID()));
        } else {
            user.emplace_back(new Teacher(ans[0].getID(), ans[0].getName(), ans[0].getRole(), ans[0].getGroupID()));
        }
    } else {
        cout << "Такого пользователя не существует" << endl;
        user.emplace_back(new Guest);
    }

    return user;
}