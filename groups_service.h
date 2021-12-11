//
// Created by danila on 30.11.21.
//

#ifndef COURSE_TEST_GROUPS_SERVICE_H
#define COURSE_TEST_GROUPS_SERVICE_H
#include <iostream>
#include <string>
#include <vector>
#include "CRUD.h"
#include "Service.h"
#include "User.h"
#include "Test.h"
#include "Group.h"

using namespace std;

void groups_menu();
vector<Group> get_groups();
void add_group();
void show_group();
void change_group();
void delete_group();
#endif //COURSE_TEST_GROUPS_SERVICE_H
