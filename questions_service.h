//
// Created by danila on 2.12.21.
//

#ifndef COURSE_TEST_QUESTIONS_SERVICE_H
#define COURSE_TEST_QUESTIONS_SERVICE_H
#include "Question_Many_Variants.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sqlite3.h>
#include "Test.h"

using namespace std;

int add_questions_to_table(vector<Question_Many_Variants> questions, int test_id);
void changeQuestions(vector<Question_Many_Variants> questions);
#endif //COURSE_TEST_QUESTIONS_SERVICE_H
