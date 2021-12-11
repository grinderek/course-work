//
// Created by danila on 28.11.21.
//

#ifndef COURSE_TEST_USER_H
#define COURSE_TEST_USER_H
#include <string>
#include <memory>
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
    User(const int& id, const string& name, const int& role, const int& group_id);

    string getName();
    void setName(string s);

    int getRole();
    void setRole(int rl);

    int getID() const;
    void setID(int id);

    void setGroupID(int ide);
    int getGroupID() const;

    void get_data(sqlite3_stmt *stmt);

    virtual vector<unique_ptr<User>> menu();

    //friend istream& operator>> (istream &in, User &user);
};

//istream& operator>> (istream &in, User &user);

#endif //COURSE_TEST_USER_H
