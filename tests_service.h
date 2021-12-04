//
// Created by danila on 30.11.21.
//

#ifndef COURSE_TEST_TESTS_SERVICE_H
#define COURSE_TEST_TESTS_SERVICE_H
#include <string>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include "Question_Many_Variants.h"
#include "sqlite3.h"
#include "Service.h"
#include "tables_service.h"
#include "questions_service.h"
#include "Test.h"

using namespace std;

void tests_menu(const User& user);
void createTestsTable();
vector<Test> get_tests(int user_id);
void delete_test(int user_id);
void add_test(const User& user);
int add_test_to_table(const string& topic, int count, int user_id);
//void add_questions_to_table(const )

#endif //COURSE_TEST_TESTS_SERVICE_H
