//
// Created by danila on 8.12.21.
//

#ifndef COURSE_TEST_STUDENT_H
#define COURSE_TEST_STUDENT_H
#include "User.h"
#include <iostream>
#include <string>
#include "Guest.h"
#include "testing_service.h"
#include <vector>

using namespace std;

class User;
class Student : public User {
public:
    Student(const int& id, const string& name, const int& role, const int& group_id);
    Student(const Student& student);

    vector<unique_ptr<User>> menu() override;
};


#endif //COURSE_TEST_STUDENT_H
