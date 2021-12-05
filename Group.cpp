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

int Group::getID() {
    return this->id;
}

