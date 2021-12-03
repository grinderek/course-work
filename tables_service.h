//
// Created by danila on 1.12.21.
//

#ifndef COURSE_TEST_TABLES_SERVICE_H
#define COURSE_TEST_TABLES_SERVICE_H
#include <iostream>
#include <string>
#include <sqlite3.h>

using namespace std;

int SQLOperation(const string& sql);
void createQuestionsTable();
void createAnswersTable();
void createCorrectAnswerTable();
#endif //COURSE_TEST_TABLES_SERVICE_H
