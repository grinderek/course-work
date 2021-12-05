//
// Created by danila on 28.11.21.
//

#ifndef COURSE_TEST_CRUD_H
#define COURSE_TEST_CRUD_H
#include <iostream>
#include <string>
#include "Service.h"
#include "tables_service.h"
#include "User.h"
using namespace std;

int add_user(int role = 0, int group_id = -1);
User login();

#endif //COURSE_TEST_CRUD_H
