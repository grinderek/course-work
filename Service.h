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
#include "tables_service.h"
#include "User.h"
#include "sqlite3.h"

using namespace std;

int getInt(int begin, int end);
string getString();
string getStrInt();
void createUsersTable();
void insertUserTable(const string& full_name, const string& login, const string& password, int role );
User authenticate(const string& login, const string& password);
string quotesql(const string& s);;

#endif //COURSE_TEST_SERVICE_H
