//
// Created by danila on 30.11.21.
//

#ifndef COURSE_TEST_GROUPINTERFACE_H
#define COURSE_TEST_GROUPINTERFACE_H
#include <iostream>
#include <string>
#include <vector>
#include "Authorization.h"
#include "Service.h"
#include "User.h"
#include "Test.h"
#include "Group.h"

using namespace std;

class GroupInterface{
public:
    static void groups_menu();
    static void add_group();
    static void show_group();
    static void change_group();
    static void delete_group();
};

#endif //COURSE_TEST_GROUPINTERFACE_H
