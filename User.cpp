//
// Created by danila on 28.11.21.
//

#include "User.h"

User::User() {
    this->name = "...";
    this->role = -1;
}

User::User(const int& id, const string& name, const int& role) {
    this->id = id;
    this->name = name;
    this->role = role;
}

User::User(const User &user) {
    this->id = user.id;
    this->name = user.name;
    this->role = user.role;
}

string User::getName() {
    return this->name;
}

void User::setName(string s) {
    this->name = s;
}

int User::getRole() {
    return this->role;
}

void User::setRole(int rl) {
    this->role = rl;
}

int User::getID() const {
    return this->id;
}

void User::setID(int ident) {
    this->id = ident;
}

