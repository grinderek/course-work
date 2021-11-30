//
// Created by danila on 28.11.21.
//

#ifndef COURSE_TEST_USER_H
#define COURSE_TEST_USER_H
#include <string>
using namespace std;

class User {
private:
    string name;
    int role;

public:
    User();
    User(const string& name, const int& role);

    string getName();
    void setName(string s);

    int getRole();
    void setRole(int rl);
};


#endif //COURSE_TEST_USER_H
