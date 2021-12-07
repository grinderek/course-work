//
// Created by danila on 3.12.21.
//

#ifndef COURSE_TEST_SQLGATEWAY_H
#define COURSE_TEST_SQLGATEWAY_H
#include <sqlite3.h>
#include <iostream>
#include <string>
#include <vector>
#include "Question_Many_Variants.h"
#include "Test.h"
#include "JustInt.h"

using namespace std;

class SqlGateway {
private:
    const char *name;
    sqlite3 *DB;
public:
    SqlGateway();

    int SQLOperation(const string& sql);
    void createUsersTable();
    void createQuestionsTable();
    void createAnswersTable();
    void createCorrectAnswerTable();
    void createGroupTable();
    void createTestsTable();
    void createGroupTestsTable();
    void createUsersTestsTable();

    template<class T>
    vector<T> getData(string sql);
};


#endif //COURSE_TEST_SQLGATEWAY_H
