//
// Created by danila on 8.12.21.
//

#include "Teacher.h"

vector<unique_ptr<User>> Teacher::menu() {
    cout << "1 - Тесты" << endl;
    cout << "2 - Группы" << endl;
    cout << "0 - Выход" << endl;
    int op_men = getInt(0, 2);

    vector<unique_ptr<User>> user;
    switch (op_men) {
        case 0:
            user.emplace_back(new Guest);
            return user;
            break;
        case 1:
            tests_menu(this->getID());
            break;
        case 2:
            groups_menu();
            break;
        default:
            cout << "Что-то пошло не так" << endl;
    }

    user.emplace_back(new Teacher(this->getID(), this->getName(), this->getRole(), this->getGroupID()));
    return user;

}
