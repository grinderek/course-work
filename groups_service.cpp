//
// Created by danila on 5.12.21.
//

#include "groups_service.h"

void groups_menu(User user) {
    cout << "1 - Создать группу" << endl;
    cout << "2 - Просмотреть группу" << endl;
    cout << "3 - Редактировать группу" << endl;
    cout << "4 - Удалить группу" << endl;
    cout << "0 - Выход" << endl;

    int op_men = getInt(0, 4);
    switch (op_men) {
        case 0:
            return;
        case 1:
            add_group();
            break;
        case 2:
            show_group();
            break;
        case 3:
            change_group();
            break;
        case 4:
            //delete_group();
            break;
        default:
            cout << "Что-то не так" << endl;
    }
}

void add_group() {

    int group_id = 0;
    while (group_id == 0) {
        cout << "Введите номер группы(0 для выхода)" << endl;
        string number = getString();
        if (number == "0") return;
        group_id = SQLOperation("INSERT INTO GROUPS (NUMBER_OF_GROUP) VALUES ("
                                    + quotesql(number) + ");");
    }

    while(true) {
        cout << "Добавить учащегося в группу?" << endl;
        cout << "1 - Да\n2 - Нет" << endl;
        int op_men = getInt(1, 2);
        switch (op_men) {
            case 1: {
                int user_id = add_user(1);
                if (user_id != 0) {
                    string sql = "PRAGMA foreign_keys = ON;\n"
                                 "UPDATE USERS SET GROUP_ID = " + to_string(group_id) + " WHERE ID = " +
                                 to_string(user_id) + ";\nPRAGMA foreign_keys = OFF;";
                    SQLOperation(sql);
                }
            }
                break;
            case 2:
                return;
            default:
                cout << "Что-то пошло не так" << endl;
        }
    }
}

vector<Group> get_groups() {
    string sql = "SELECT * FROM GROUPS";
    sqlite3 *DB;

    try
    {
        int exit = 0;
        exit = sqlite3_open("test.db", &DB);
        cout << exit << " " << sql << endl;
        char* messageError;
        vector<Group> groups;
        sqlite3_stmt *stmt;
        exit = sqlite3_prepare_v2(DB, sql.c_str(), sql.length(), &stmt, nullptr);

        if (exit != SQLITE_OK) {
            cerr << "Error Authenticate" << endl;
        }
        else {
            while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) {
                Group group;
                group.setID(sqlite3_column_int(stmt, 0));
                group.setNumber(string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
                groups.push_back(group);
            }
        }
        sqlite3_finalize(stmt);
        sqlite3_close(DB);

        return groups;
    }
    catch (const exception & e)
    {
        cerr << e.what();
        return {};
    }
}

vector<User> get_users(int group_id){
    string sql = "SELECT * FROM USERS WHERE GROUP_ID = " + to_string(group_id);
    sqlite3 *DB;

    try
    {
        int exit = 0;
        exit = sqlite3_open("test.db", &DB);
        cout << exit << " " << sql << endl;
        char* messageError;
        vector<User> users;
        sqlite3_stmt *stmt;
        exit = sqlite3_prepare_v2(DB, sql.c_str(), sql.length(), &stmt, nullptr);

        if (exit != SQLITE_OK) {
            cerr << "Error Authenticate" << endl;
        }
        else {
            while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) {
                User user;
                user.setID(sqlite3_column_int(stmt, 0));
                user.setName(string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
                users.push_back(user);
            }
        }
        sqlite3_finalize(stmt);
        sqlite3_close(DB);

        return users;
    }
    catch (const exception & e)
    {
        cerr << e.what();
        return {};
    }
}

void show_group() {
    vector<Group> groups = get_groups();

    while (true) {
        cout << "Выберите номер группы, которую хотите просмотреть(0 для выхода)" << endl;
        for (int i = 0; i < groups.size(); i++) {
            cout << i + 1 << " - " << groups[i].getNumber() << endl;
        }

        int op_men = getInt(0, groups.size());
        if (op_men == 0) {
            break;
        } else {
            op_men--;
            auto users = get_users(groups[op_men].getID());
            cout << "Студенты группы " << groups[op_men].getNumber() << endl;
            for (int i = 0; i < users.size(); i++) {
                cout << i + 1 << " - " << users[i].getName() << endl;
            }
        }
    }
}
