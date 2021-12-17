//
// Created by danila on 5.12.21.
//

#include "GroupInterface.h"

void GroupInterface::groups_menu() {
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
            Interface<Group>::change("SELECT * FROM GROUPS");
            break;
        case 4:
            delete_group();
            break;
        default:
            cout << "Что-то не так" << endl;
    }
}

void GroupInterface::add_group() {
    SqlGateway DB;
    int group_id = 0;
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
                int user_id = Authorization::add_user(1);
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

void GroupInterface::show_group() {
    SqlGateway DB;

    string sql = "SELECT * FROM GROUPS";
    vector<Group> groups = DB.getData<Group>(sql);

    while (true) {
        cout << "Выберите номер группы, которую хотите просмотреть(0 для выхода)" << endl;
        for (int i = 0; i < groups.size(); i++) {
            cout << i + 1 << " - " << groups[i].getName() << endl;
        }

        int op_men = getInt(0, groups.size());
        if (op_men == 0) {
            break;
        }

        op_men--;
        int group_number = op_men;
        int group_id = groups[op_men].getID();
        sql = "SELECT * FROM TESTS t"
              " LEFT JOIN GROUP_TESTS gt ON gt.TEST_ID = t.ID"
              " WHERE gt.GROUP_ID = " + to_string(group_id);

        auto tests = DB.getData<Test>(sql);
        cout << "Выберите тест для просмотра у выбранной группы(0 для выхода)" << endl;
        for (int i = 0; i < tests.size(); i++) {
            cout << i + 1 << " - " << tests[i].getName() << endl;
        }

        op_men = getInt(0, tests.size());
        if (op_men == 0) {
            break;
        }

        op_men--;
        int test_id = tests[op_men].getID();

        sql = "SELECT * FROM USERS WHERE GROUP_ID = " + to_string(group_id);
        auto users = DB.getData<User>(sql);
        cout << "Студенты группы " << groups[group_number].getName() << endl;
        for (int i = 0; i < users.size(); i++) {
            sql = "SELECT MARK FROM USERS_TESTS WHERE USER_ID = "
                    + to_string(users[i].getID()) + " AND TEST_ID = "
                    + to_string(test_id);
            auto marks = DB.getData<JustInt>(sql);
            int mark = -1;
            if (marks.size() != 0) {
                mark = marks[0].getVal();
            }

            cout << i + 1 << ". " << users[i].getName() << " - " << (mark == -1 ? "Не прошел" : to_string(mark)) << endl;
        }
    }
}

void GroupInterface::delete_group() {
    SqlGateway DB;

    string sql = "SELECT * FROM GROUPS";
    vector<Group> groups = DB.getData<Group>(sql);

    if (groups.empty()) {
        cout << "Нет доступных объектов для удаления" << endl;
        return;
    }

    while (true) {
        cout << "Выберите номер группы, которую хотите удалить(0 для выхода)" << endl;
        for (int i = 0; i < groups.size(); i++) {
            cout << i + 1 << " - " << groups[i].getName() << endl;
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
