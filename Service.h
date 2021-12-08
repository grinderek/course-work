//
// Created by danila on 28.11.21.
//

#ifndef COURSE_TEST_SERVICE_H
#define COURSE_TEST_SERVICE_H
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <map>
#include "User.h"
#include "sqlite3.h"

using namespace std;

int getInt(int begin, int end);
string getString();
string quotesql(const string& s);;

#endif //COURSE_TEST_SERVICE_H
