//
// Created by danila on 28.11.21.
//

#ifndef COURSE_TEST_CRUD_H
#define COURSE_TEST_CRUD_H
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
int add_user(int role = 0, int group_id = -1);
vector<unique_ptr<User>> login();

#endif //COURSE_TEST_CRUD_H
