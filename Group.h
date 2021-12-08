//
// Created by danila on 5.12.21.
//

#ifndef COURSE_TEST_GROUP_H
#define COURSE_TEST_GROUP_H
#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>
#include "User.h"

using namespace std;

class Group {
private:
    int id;
    string number_of_group;
    vector<User> users;
public:
    Group();
    Group(const Group& group);
    ~Group(){};

    void setID(int ide);
    void setNumber(string number);
    string getNumber();
    int getID() const;

    void get_data(sqlite3_stmt *stmt);
};


#endif //COURSE_TEST_GROUP_H
