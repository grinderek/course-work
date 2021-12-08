//
// Created by danila on 28.11.21.
//

#ifndef COURSE_TEST_USER_H
#define COURSE_TEST_USER_H
#include <string>
#include "SqlGateway.h"
using namespace std;

class User {
private:
    int id;
    string name;
    int role;
    int group_id;

public:
    User();
    User(const int& id, const string& name, const int& role);
    User(const User& user);

    string getName();
    void setName(string s);

    int getRole();
    void setRole(int rl);

    int getID() const;
    void setID(int id);

    void setGroupID(int ide);
    int getGroupID() const;

    void get_data(sqlite3_stmt *stmt);
};


#endif //COURSE_TEST_USER_H
