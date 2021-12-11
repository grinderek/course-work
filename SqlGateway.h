//
// Created by danila on 3.12.21.
//

#ifndef COURSE_TEST_SQLGATEWAY_H
#define COURSE_TEST_SQLGATEWAY_H
#include <sqlite3.h>
#include <iostream>
#include <string>
#include <vector>
#include "Question.h"
#include "Test.h"
#include "JustInt.h"
#include "Group.h"
#include "User.h"

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
    void createCorrectAnswersTable();
    void createGroupsTable();
    void createTestsTable();
    void createGroupTestsTable();
    void createUsersTestsTable();

    template<class T>
    vector<T> getData(string sql);
};


#endif //COURSE_TEST_SQLGATEWAY_H
