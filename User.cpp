//
// Created by danila on 28.11.21.
//

#include "User.h"

User::User() {
    this->name = "...";
    this->role = -1;
}

User::User(const int& id, const string& name, const int& role, const int& group_id) {
    this->id = id;
    this->name = name;
    this->role = role;
    this->group_id = group_id;
}

User::User(const User &user) {
    this->id = user.id;
    this->name = user.name;
    this->role = user.role;
    this->group_id = user.group_id;
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

void User::setGroupID(int ide) {
    this->group_id = ide;
}

int User::getGroupID() const {
    return this->group_id;
}

void User::get_data(sqlite3_stmt *stmt) {
    this->id = sqlite3_column_int(stmt, 0);
    this->name = string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
    this->role = sqlite3_column_int(stmt, 4);
    this->group_id = sqlite3_column_int(stmt, 5);
}

