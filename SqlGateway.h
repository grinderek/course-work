//
// Created by danila on 3.12.21.
//

#ifndef COURSE_TEST_SQLGATEWAY_H
#define COURSE_TEST_SQLGATEWAY_H
#include <sqlite3.h>
#include <iostream>
#include <string>

using namespace std;

class SqlGateway {
    sqlite3 *DB;
};


#endif //COURSE_TEST_SQLGATEWAY_H
