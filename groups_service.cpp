//
// Created by danila on 5.12.21.
//

#include "groups_service.h"

void groups_menu(User user) {
    cout << "1 - Создать группу" << endl;
    cout << "2 - Просмотреть группу" << endl;
    cout << "3 - Редактировать группу" << endl;
    cout << "4 - Удалить группу" << endl;
    cout << "0 - Выход" << endl;

    int op_men = getInt(0, 4);
    switch (op_men) {
        case 0:
            return;
        case 1:
            add_group();
            break;
        case 2:
            //show_group();
            break;
        case 3:
            //change_group();
            break;
        case 4:
            //delete_group();
            break;
        default:
            cout << "Что-то не так" << endl;
    }
}

void add_group() {
    cout << "Введите номер группы" << endl;
    string number = getString();
    int group_id = SQLOperation("INSERT INTO GROUPS (NUMBER_OF_GROUP) VALUES ("
                                + quotesql(number) + ");");

    while(true) {
        cout << "Добавить учащегося в группу?" << endl;
        cout << "1 - Да\n2 - Нет" << endl;
        int op_men = getInt(1, 2);
        switch (op_men) {
            case 1: {
                int user_id = add_user(1);
                if (user_id != 0) {
                    SQLOperation("INSERT INTO GROUPS_USERS (GROUP_ID, USER_ID) VALUES ("
                                 + to_string(group_id) + ", "
                                 + to_string(user_id) + ");");
                }
            }
                break;
            case 2:
                return;
            default:
                cout << "Что-то пошло не так" << endl;
        }
    }
}

void show_group() {
    
}
