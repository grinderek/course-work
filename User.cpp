//
// Created by danila on 28.11.21.
//

#include "User.h"

#include <utility>

User::User() {
    this->user_id = -1;
    this->name = "...";
    this->group_id = -1;
    this->role = -1;
}

User::User(const int& id, const string& name, const int& role, const int& group_id) {
    this->user_id = id;
    this->name = name;
    this->role = role;
    this->group_id = group_id;
}

/*User::User(const User &user) {
    this->user_id = user.user_id;
    this->name = user.name;
    this->role = user.role;
    this->group_id = user.group_id;
}*/

string User::getName() {
    return this->name;
}

void User::setName(string s) {
    this->name = std::move(s);
}

int User::getRole() const {
    return this->role;
}

void User::setRole(int rl) {
    this->role = rl;
}

int User::getID() const {
    return this->user_id;
}

void User::setID(int ident) {
    this->user_id = ident;
}

void User::setGroupID(int ide) {
    this->group_id = ide;
}

int User::getGroupID() const {
    return this->group_id;
}

void User::get_data(sqlite3_stmt *stmt) {
    this->user_id = sqlite3_column_int(stmt, 0);
    this->name = string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
    this->role = sqlite3_column_int(stmt, 4);
    this->group_id = sqlite3_column_int(stmt, 5);
}

vector<unique_ptr<User>> User::menu() {}

void User::change() {
    SqlGateway DB;

    cout << this->getName() << endl;
    cout << "1 - Изменить ФИО" << endl;
    cout << "0 - Выход" << endl;
    int op_men = getInt(0, 1);
    if (op_men == 0) {
        return;
    }

    cout << "Введите новое ФИО" << endl;
    string full_name = getString();
    cout << "Вы уверены, что хотите сохранить изменения?" << endl;
    cout << "1 - Да" << endl;
    cout << "2 - Нет" << endl;
    op_men = getInt(1, 2);
    if (op_men == 1) {
        DB.SQLOperation("UPDATE USERS SET FULL_NAME = "
                        + quotesql(full_name) + "WHERE ID = "
                        + to_string(this->user_id) + ";");
        return;
    }
}

/*
istream &operator>>(istream &in, User &user) {
    return in;
}
*/

