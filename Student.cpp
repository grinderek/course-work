//
// Created by danila on 8.12.21.
//

#include "Student.h"

Student::Student(const int& id, const string& name, const int& role, const int& group_id) : User(id, name, role, group_id) {}
Student::Student(const Student &student) : User(student){}

vector <unique_ptr<User>> Student::menu() {
    cout << "1 - Пройти тест" << endl;
    cout << "2 - Просмотреть результаты тестов" << endl;
    cout << "0 - Выход" << endl;

    vector <unique_ptr<User>> user;
    int op_men = getInt(0, 2);

    switch (op_men) {
        case 0:
            user.emplace_back(new Guest);
            return user;
        case 1:
            TestingInterface::testing_menu(this->user_id, this->group_id);
            break;
        case 2:
            TestingInterface::show_results(this->user_id);
            break;
        default:
            cout << "Что-то пошло не так" << endl;
    }

    user.emplace_back(new Student(this->getID(), this->getName(), this->getRole(), this->getGroupID()));
    return user;
}
