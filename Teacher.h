//
// Created by danila on 8.12.21.
//

#ifndef COURSE_TEST_TEACHER_H
#define COURSE_TEST_TEACHER_H
#include "User.h"
#include "TestInterface.h"
#include "GroupInterface.h"
#include "Guest.h"
#include <iostream>
#include <string>
#include <vector>
#include "Service.h"

using namespace std;

class User;
class Teacher : public User {
public:
    Teacher(const int &id, const string &name, const int &role, const int &group_id) : User(id, name, role,
                                                                                            group_id) {};
    vector<unique_ptr<User>> menu();
};


#endif //COURSE_TEST_TEACHER_H
