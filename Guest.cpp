//
// Created by danila on 9.12.21.
//

#include "Guest.h"

vector<unique_ptr<User>> Guest::menu() {
    vector<unique_ptr<User>> user;
    user.emplace_back(new Guest);
    cout << "Введите номер вашего действия" << endl;
    cout << "1 - Войти в систему" << endl;
    cout << "2 - Зарегистрироваться(для учителей)" << endl;
    cout << "0 - Выйти" << endl;
    int op_men = getInt(0, 2);
    switch (op_men) {
        case 0:
            cout << "До свидания!" << endl;
            exit(0);
        case 1:
            user = login();
            break;
        case 2:
            add_user(1);
            break;
        default:
            cout << "Что-то пошло не так" << endl;
    }

    return user;
}
