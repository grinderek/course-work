//
// Created by danila on 28.11.21.
//

#ifndef COURSE_TEST_AUTHORIZATION_H
#define COURSE_TEST_AUTHORIZATION_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <memory>
#include "Service.h"
#include "User.h"
#include "SqlGateway.h"
#include "Student.h"
#include "Teacher.h"
#include "Guest.h"

using namespace std;

class User;
class Authorization {
public:
    static int add_user(int role = 0, int group_id = -1);
    static vector<unique_ptr<User>> login();
};

#endif //COURSE_TEST_AUTHORIZATION_H
