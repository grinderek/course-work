//
// Created by danila on 7.12.21.
//

#ifndef COURSE_TEST_JUSTINT_H
#define COURSE_TEST_JUSTINT_H
#include "SqlGateway.h"
#include <iostream>

using namespace std;

class JustInt {
private:
    int val;
public:
    void setVal(int x);
    int getVal();

    void get_data(sqlite3_stmt *stmt);
};


#endif //COURSE_TEST_JUSTINT_H
