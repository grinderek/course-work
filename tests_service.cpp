//
// Created by danila on 30.11.21.
//

#include "tests_service.h"

void tests_menu(const User& user) {
    cout << "1 - Добавить тест" << endl;
    cout << "2 - Показать результаты теста" << endl;
    cout << "3 - Редактировать тест" << endl;
    cout << "4 - Удалить тест" << endl;
    cout << "0 - Вернуться назад" << endl;
    int op_men = getInt(0, 4);
    switch (op_men) {
        case 0:
            return;
        case 1:
            add_test(user);
            break;
        case 2:
            show_tests(user.getID());
            break;
        case 3:
            change_test(user.getID());
            break;
        case 4:
            delete_test(user.getID());
            break;
        default:
            cout << "Что-то не так" << endl;
    }
}

void add_test(const User& user) {
    cout << "Введите тему теста" << endl;
    string topic = getString();
    cout << "Введите кол-во вопросов" << endl;
    int count = getInt(1, INT_MAX);

    vector<Question_Many_Variants> questions;
    for (int i = 1; i <= count; i++) {
        cout << "Вопрос №" << i << endl;
        Question_Many_Variants question;
        cin >> question;
        questions.push_back(question);
    }

    vector <Group> groups = get_groups();
    vector <Group> groups_of_test;
    while (true) {
        cout << "Добавить группу к тесту?" << endl;
        cout << "1 - Да" << endl;
        cout << "2 - Нет" << endl;
        int op = getInt(1, 2);

        if (op == 2) {
            break;
        }

        int i = 1;
        for (auto group : groups) {
            cout << i++ << " " << group.getNumber() << endl;
        }

        cout << "Выберите номер группы, которую хотите добавить к тесту(0 для выхода)" << endl;
        int group_id = getInt(0, groups.size());

        if (group_id == 0) {
            continue;
        } else {
            group_id--;
            groups_of_test.push_back(groups[group_id]);
            groups.erase(groups.begin() + group_id);
        }
    }

    SqlGateway DB;

    string sql = "INSERT INTO TESTS (NAME_OF_TEST, NUMBER_OF_QUESTIONS, USER_ID) VALUES ("
                 + quotesql(topic) + ","
                 + to_string(count) + ","
                 + to_string(user.getID()) + ");";
    int test_id = DB.SQLOperation(sql);

    for (auto group : groups) {
        DB.SQLOperation("INSERT INTO GROUP_TESTS (GROUP_ID, TEST_ID) VALUES ("
                     + to_string(group.getID()) + ", "
                     + to_string(test_id) + ");");
    }
    add_questions_to_table(questions, test_id);
}

vector<Test> show_tests(int user_id) {
    SqlGateway DB;
    string sql = "SELECT * FROM TESTS WHERE USER_ID = " + to_string(user_id);
    vector<Test> tests = DB.getData<Test>(sql);

    for (auto test : tests) {
        cout << test;
    }

    return tests;
}

void delete_test(int user_id) {
    SqlGateway DB;
    auto tests = show_tests(user_id);

    while (true) {
        cout << "Введите ID теста, который хотите удалить(0 для выхода)" << endl;
        int id = getInt(0, INT_MAX);

        if (id == 0) {
            return;
        } else {
            if (find_if(tests.begin(), tests.end(), [id](Test x){
                return x.getID() == id;
            }) != tests.end()) {
                cout << "Вы уверены, что хотите удалить этот тест?" << endl;
                cout << "1 - Да" << endl;
                cout << "2 - Нет" << endl;
                int x = getInt(1, 2);
                if (x == 1) {
                    string sql = "PRAGMA foreign_keys = ON;\n"
                                 "DELETE FROM TESTS WHERE ID = " + to_string(id)
                                 + ";\nPRAGMA foreign_keys = OFF;";

                    DB.SQLOperation(sql);
                    break;
                } else {
                    continue;
                }
            }
            else {
                cout << "Теста с таким ID не существует" << endl;
            }
        }
    }
}

void change_test(int user_id) {
    SqlGateway DB;
    auto tests = show_tests(user_id);

    while (true) {
        cout << "Введите ID теста, который хотите измените(0 для выхода)" << endl;
        int id = getInt(0, INT_MAX);

        if (id == 0) {
            return;
        } else {
            auto it = find_if(tests.begin(), tests.end(), [id](Test x) {
                return x.getID() == id;
            });
            if (it != tests.end()) {
                cout << *it;
                cout << "Что вы хотите изменить?" << endl;
                cout << "1 - Тему теста" << endl;
                cout << "2 - Вопросы" << endl;
                cout << "0 - Выход" << endl;
                int op_menu = getInt(0, 2);

                switch (op_menu) {
                    case 0:
                        continue;
                    case 1: {
                        cout << "Введите новую тему" << endl;
                        string topic = getString();
                        cout << "Вы уверены, что хотите сохраните изменения?" << endl;
                        cout << "1 - Да" << endl;
                        cout << "2 - Нет" << endl;
                        int x = getInt(1, 2);
                        if (x == 1) {
                            string sql = "PRAGMA foreign_keys = ON;\n"
                                         "UPDATE TESTS SET NAME_OF_TEST = " + quotesql(topic) + " WHERE ID = " +
                                    to_string(id) + ";\nPRAGMA foreign_keys = OFF;";
                            DB.SQLOperation(sql);
                            break;
                        } else {
                            continue;
                        }
                    }
                        break;
                    case 2:
                        changeQuestions((*it).getQuestions());
                        break;
                }
            } else {
                cout << "Теста с таким ID не существует" << endl;
            }
        }
    }
}