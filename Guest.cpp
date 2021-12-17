//
// Created by danila on 9.12.21.
//

#include "Guest.h"

vector<unique_ptr<User>> Guest::menu() {
    vector<unique_ptr<User>> user;
    user.emplace_back(new Guest);
    cout << "1 - Войти в систему" << endl;
    cout << "2 - Зарегистрироваться(для преподавателей)" << endl;
    cout << "0 - Выйти" << endl;
    int op_men = getInt(0, 2);
    switch (op_men) {
        case 0:
            cout << "До свидания!" << endl;
            exit(0);
        case 1:
            user = Authorization::login();
            break;
        case 2:
            Authorization::add_user(2);
            break;
        default:
            cout << "Что-то пошло не так" << endl;
    }

    return user;
}
