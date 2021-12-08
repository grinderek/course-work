//
// Created by danila on 8.12.21.
//

#ifndef COURSE_TEST_STUDENT_H
#define COURSE_TEST_STUDENT_H
#include "User.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student : public User{
public:
    Student(const int& id, const string& name, const int& role, const int& group_id);
};


#endif //COURSE_TEST_STUDENT_H
