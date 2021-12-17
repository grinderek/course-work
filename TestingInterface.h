//
// Created by danila on 5.12.21.
//

#ifndef COURSE_TEST_TESTINGINTERFACE_H
#define COURSE_TEST_TESTINGINTERFACE_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Group.h"
#include "User.h"
#include "Test.h"

class TestingInterface{
public:
    static void testing_menu(int user_id, int group_id);
    static void show_results(int user_id);
};

#endif //COURSE_TEST_TESTINGINTERFACE_H
