//
// Created by danila on 9.12.21.
//

#ifndef COURSE_TEST_GUEST_H
#define COURSE_TEST_GUEST_H
#include "User.h"
#include "CRUD.h"

using namespace std;

class Guest : public User{
public:
    Guest() : User() {};
    vector<unique_ptr<User>> menu() override;
};


#endif //COURSE_TEST_GUEST_H
