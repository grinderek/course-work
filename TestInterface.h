//
// Created by danila on 30.11.21.
//

#ifndef COURSE_TEST_TESTINTERFACE_H
#define COURSE_TEST_TESTINTERFACE_H
#include <string>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include "Question.h"
#include "sqlite3.h"
#include "Service.h"
#include "GroupInterface.h"
#include "Interface.h"
#include "Test.h"

using namespace std;

class TestInterface {
public:
    static void tests_menu(int user_id);
    static vector<Test> show_tests(int user_id);
    static void add_test(int user_id);
};

#endif //COURSE_TEST_TESTINTERFACE_H
