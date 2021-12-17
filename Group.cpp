//
// Created by danila on 5.12.21.
//

#include "Group.h"

Group::Group() {
    this->group_id = -1;
    this->number_of_group = "...";
    this->users.clear();
}

Group::Group(const Group &group) {
    this->group_id = group.group_id;
    this->users = group.users;
    this->number_of_group = group.number_of_group;
}

string Group::getName() {
    return this->number_of_group;
}

int Group::getID() const {
    return this->group_id;
}

void Group::get_data(sqlite3_stmt *stmt) {
    this->group_id = sqlite3_column_int(stmt, 0);
    this->number_of_group = string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
}

istream &operator>>(istream &in, Group &group) {
    cout << "Введите номер группы" << endl;
    group.number_of_group = getString();

    return in;
}

void Group::change() {
    SqlGateway DB;

    cout << *this << endl;
    string sql = "SELECT * FROM USERS WHERE GROUP_ID = " + to_string(this->group_id);
    auto users = DB.getData<User>(sql);
    cout << "Что вы хотите изменить?" << endl;
    cout << "1 - Номер группы" << endl;
    cout << "2 - Данные студентов" << endl;
    cout << "0 - Выход" << endl;

    int op_men = getInt(0, 2);
    if (op_men == 0) {
        return;
    }
    if (op_men == 1) {
        cout << "Введите новый номер группы" << endl;
        string number = getString();
        cout << "Вы уверены, что хотите сохранить изменения?" << endl;
        cout << "1 - Да" << endl;
        cout << "2 - Нет" << endl;
        op_men = getInt(1, 2);
        if (op_men == 1) {
            DB.SQLOperation("UPDATE GROUPS SET NUMBER_OF_GROUP = "
                            + quotesql(number) + "WHERE ID = "
                            + to_string(this->group_id) + ";");
            return;
        }
    }

    cout << "Студенты группы " << this->number_of_group << endl;
    for (int i = 0; i < users.size(); i++) {
        cout << i + 1 << " - " << users[i].getName() << endl;
    }
    cout << "Выберите номер студента, которого хотите изменить(0 для выхода)" << endl;
    int user_id = getInt(0, users.size());

    if (user_id == 0) {
        return;
    }

    users[--user_id].change();
}

ostream &operator<<(ostream &out, const Group &group) {
    out << "Номер группы - " << group.number_of_group << endl;
    int i = 1;
    for (auto student : group.users) {
        out << "№ " << i++ << " - ";
        out << student.getName() << endl;
    }

    return out;
}


