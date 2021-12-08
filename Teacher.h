//
// Created by danila on 8.12.21.
//

#ifndef COURSE_TEST_TEACHER_H
#define COURSE_TEST_TEACHER_H
#include "User.h"
#include "tests_service.h"
#include "groups_service.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Teacher : public User {
public:
    Teacher(const int &id, const string &name, const int &role, const int &group_id) : User(id, name, role,
                                                                                            group_id) {};

    void menu() {
        cout << "1 - Тесты" << endl;
        cout << "2 - Группы" << endl;
        cout << "0 - Выход" << endl;
        int op_men = getInt(0, 2);

        switch (op_men) {
            case 0:
                return;
                break;
            case 1:
               // tests_menu(dynamic_cast<User *>(this));
                break;
            case 2:
               // groups_menu(this);
                break;
            default:
                cout << "Что-то пошло не так" << endl;
        }
    }
};


#endif //COURSE_TEST_TEACHER_H
