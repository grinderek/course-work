//
// Created by danila on 5.12.21.
//

#include "Group.h"

Group::Group() {
    this->id = -1;
    this->number_of_group = "...";
    this->users.clear();
}

Group::Group(const Group &group) {
    this->id = group.id;
    this->users = group.users;
    this->number_of_group = group.number_of_group;
}

void Group::setID(int ide) {
    this->id = ide;
}

void Group::setNumber(string number) {
    this->number_of_group = number;
}

string Group::getNumber() {
    return this->number_of_group;
}

int Group::getID() const {
    return this->id;
}

void Group::get_data(sqlite3_stmt *stmt) {
    this->id = sqlite3_column_int(stmt, 0);
    this->number_of_group = string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
}

