//
// Created by danila on 5.12.21.
//

#include "groups_service.h"

void groups_menu() {
    cout << "1 - Создать группу" << endl;
    cout << "2 - Просмотреть результаты группы" << endl;
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
            delete_group();
            break;
        default:
            cout << "Что-то не так" << endl;
    }
}

void add_group() {
    SqlGateway DB;
    int group_id = 0;
    //Group group;
    //cin >> group;
    while (group_id == 0) {
        cout << "Введите номер группы(0 для выхода)" << endl;
        string number = getString();
        if (number == "0") return;
        group_id = DB.SQLOperation("INSERT INTO GROUPS (NUMBER_OF_GROUP) VALUES ("
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
                    DB.SQLOperation(sql);
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

void show_group() {
    SqlGateway DB;

    string sql = "SELECT * FROM GROUPS";
    vector<Group> groups = DB.getData<Group>(sql);

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
            int group_id = groups[op_men].getID();
            //sql = "SELECT t.name FROM TESTS t"
              //    "LEFT JOIN GROUP_TESTS gt.TESTS_ID = ";

            sql = "SELECT * FROM USERS WHERE GROUP_ID = " + to_string(group_id);
            auto users = DB.getData<User>(sql);
            cout << "Студенты группы " << groups[op_men].getNumber() << endl;
            for (int i = 0; i < users.size(); i++) {
                cout << i + 1 << " - " << users[i].getName() << endl;
            }
        }
    }
}

void change_group() {
    SqlGateway DB;

    string sql = "SELECT * FROM GROUPS";
    vector<Group> groups = DB.getData<Group>(sql);

    while (true) {
        cout << "Выберите номер группы, которую хотите изменить(0 для выхода)" << endl;
        for (int i = 0; i < groups.size(); i++) {
            cout << i + 1 << " - " << groups[i].getNumber() << endl;
        }

        int group_id = getInt(0, groups.size());
        if (group_id == 0) {
            break;
        } else {
            group_id--;
            cout << group_id << endl;
            string sql = "SELECT * FROM USERS WHERE GROUP_ID = " + to_string(groups[group_id].getID());
            auto users = DB.getData<User>(sql);
            cout << "Что вы хотите изменить?" << endl;
            cout << "1 - Номер группы" << endl;
            cout << "2 - Данные студентов" << endl;
            cout << "0 - Выход" << endl;

            int op_men = getInt(0, 2);
            if (op_men == 0) {
                continue;
            } else if (op_men == 1) {
                cout << "Введите новый номер группы" << endl;
                string number = getString();
                cout << "Вы уверены, что хотите сохранить изменения?" << endl;
                cout << "1 - Да" << endl;
                cout << "2 - Нет" << endl;
                op_men = getInt(1, 2);
                if (op_men == 1) {
                    DB.SQLOperation("UPDATE GROUPS SET NUMBER_OF_GROUP = "
                                 + quotesql(number) + "WHERE ID = "
                                 + to_string(groups[group_id].getID()) + ";");
                    return;
                }
            } else {
                cout << "Студенты группы " << groups[group_id].getNumber() << endl;
                for (int i = 0; i < users.size(); i++) {
                    cout << i + 1 << " - " << users[i].getName() << endl;
                }
                cout << "Выберите номер студента, которого хотите изменить(0 для выхода)" << endl;
                int user_id = getInt(0, users.size());

                if (user_id == 0) {
                    continue;
                } else {
                    user_id--;
                    cout << users[user_id].getName() << endl;
                    cout << "1 - Изменить ФИО" << endl;
                    cout << "0 - Выход" << endl;
                    op_men = getInt(0, 1);
                    if (op_men == 0) {
                        continue;
                    } else {
                        cout << "Введите новое ФИО" << endl;
                        string full_name = getString();
                        cout << "Вы уверены, что хотите сохранить изменения?" << endl;
                        cout << "1 - Да" << endl;
                        cout << "2 - Нет" << endl;
                        op_men = getInt(1, 2);
                        if (op_men == 1) {
                            DB.SQLOperation("UPDATE USERS SET FULL_NAME = "
                                         + quotesql(full_name) + "WHERE ID = "
                                         + to_string(users[user_id].getID()) + ";");
                            return;
                        }
                    }
                }
            }
        }
    }
}

void delete_group() {
    SqlGateway DB;

    string sql = "SELECT * FROM GROUPS";
    vector<Group> groups = DB.getData<Group>(sql);

    while (true) {
        cout << "Выберите номер группы, которую хотите удалить(0 для выхода)" << endl;
        for (int i = 0; i < groups.size(); i++) {
            cout << i + 1 << " - " << groups[i].getNumber() << endl;
        }

        int group_id = getInt(0, groups.size());
        if (group_id == 0) {
            break;
        } else {
            group_id--;
            cout << "Вы уверены, что хотите сохранить изменения?" << endl;
            cout << "1 - Да" << endl;
            cout << "2 - Нет" << endl;
            int op_men = getInt(1, 2);
            if (op_men == 1) {
                string sql = "PRAGMA foreign_keys = ON;\n"
                             "DELETE FROM GROUPS WHERE ID = " + to_string(groups[group_id].getID())
                             + ";\nPRAGMA foreign_keys = OFF;";

                DB.SQLOperation(sql);
                return;
            }
        }
    }
}
