//
// Created by danila on 28.11.21.
//

#include "User.h"

User::User() {
    this->name = "...";
    this->role = -1;
}

User::User(const string& name, const int& role) {
    this->name = name;
    this->role = role;
}

string User::getName() {
    return this->name;
}

