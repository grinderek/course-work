//
// Created by danila on 2.12.21.
//

#ifndef COURSE_TEST_QUESTIONS_SERVICE_H
#define COURSE_TEST_QUESTIONS_SERVICE_H
#include "Question_Many_Variants.h"
#include <string>
#include <iostream>
#include <vector>
#include <sqlite3.h>

using namespace std;

int add_questions_to_table(vector<Question_Many_Variants> questions, int test_id);
int add_answers_to_table(Question_Many_Variants question, int question_id);
int add_correctAnswer_to_table(int answer_id, int question_id);
#endif //COURSE_TEST_QUESTIONS_SERVICE_H
