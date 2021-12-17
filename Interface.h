//
// Created by danila on 17.12.21.
//

#ifndef COURSE_TEST_INTERFACE_H
#define COURSE_TEST_INTERFACE_H
#include "SqlGateway.h"
#include "Authorization.h"

using namespace std;

class Authorization;
class Interface {
public:

    static int add_correctAnswer_to_table(int answer_id, int question_id) {
        SqlGateway DB;
        string sql = "INSERT INTO CORRECT_ANSWERS (ANSWER_ID, QUESTION_ID) VALUES ("
                     + to_string(answer_id) + ","
                     + to_string(question_id) + ");";

        int id = DB.SQLOperation(sql);

        return id;
    }

    static int add_answers_to_table(Question question, int question_id) {
        SqlGateway DB;
        int num = 0;
        for (auto answer : question.getAnswers()) {
            string sql = "INSERT INTO ANSWERS (TEXT_OF_ANSWER, QUESTION_ID) VALUES ("
                         + quotesql(answer.getName()) + ","
                         + to_string(question_id) + ");";

            int id = DB.SQLOperation(sql);

            if (num == question.getCorrectAnswer()) {
                add_correctAnswer_to_table(id, question_id);
                num = -2e9;

            }

            num++;
        }
    }

    static int add_questions_to_table(vector<Question> questions, int test_id) {
        SqlGateway DB;
        for (auto question : questions) {
            string sql = "INSERT INTO QUESTIONS (TEXT_OF_QUESTION, TEST_ID) VALUES ("
                         + quotesql(question.getName()) + ","
                         + to_string(test_id) + ");";

            int id = DB.SQLOperation(sql);
            add_answers_to_table(question, id);
        }
    }

    static void groups_menu() {
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
                show_results();
                break;
            case 3:
                change<Group>("SELECT * FROM GROUPS");
                break;
            case 4:
                del<Group>("SELECT * FROM GROUPS");
                break;
            default:
                cout << "Что-то не так" << endl;
        }
    }

    static void add_group() {
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
                    int user_id = 2;
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

    static void show_results() {
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

    static void tests_menu(int user_id) {
        cout << "1 - Добавить тест" << endl;
        cout << "2 - Показать тесты" << endl;
        cout << "3 - Редактировать тест" << endl;
        cout << "4 - Удалить тест" << endl;
        cout << "0 - Вернуться назад" << endl;
        int op_men = getInt(0, 4);
        switch (op_men) {
            case 0:
                return;
            case 1:
                add_test(user_id);
                break;
            case 2:
                show_tests(user_id);
                break;
            case 3:
                change<Test>("SELECT * FROM TESTS WHERE USER_ID = " + to_string(user_id));
                break;
            case 4:
                del<Test>("SELECT * FROM TESTS WHERE USER_ID = " + to_string(user_id));
                break;
            default:
                cout << "Что-то не так" << endl;
        }
    }

    static void add_test(int user_id) {
        cout << "Введите тему теста" << endl;
        string topic = getString();
        cout << "Введите кол-во вопросов" << endl;
        int count = getInt(1, INT_MAX);

        vector<Question> questions;
        for (int i = 1; i <= count; i++) {
            cout << "Вопрос №" << i << endl;
            Question question;
            cin >> question;
            questions.push_back(question);
        }

        SqlGateway DB;
        string sql = "SELECT * FROM GROUPS";
        vector <Group> groups = DB.getData<Group>(sql);
        vector <Group> groups_of_test;
        while (!groups.empty()) {
            cout << "Добавить группу к тесту?" << endl;
            cout << "1 - Да" << endl;
            cout << "2 - Нет" << endl;
            int op = getInt(1, 2);

            if (op == 2) {
                break;
            }

            int i = 1;
            for (auto group : groups) {
                cout << i++ << " - " << group.getName() << endl;
            }

            cout << "Выберите номер группы, которую хотите добавить к тесту(0 для выхода)" << endl;
            int group_id = getInt(0, groups.size());

            if (group_id != 0) {
                group_id--;
                groups_of_test.push_back(groups[group_id]);
                groups.erase(groups.begin() + group_id);
            }
        }

        sql = "INSERT INTO TESTS (NAME_OF_TEST, NUMBER_OF_QUESTIONS, USER_ID) VALUES ("
              + quotesql(topic) + ","
              + to_string(count) + ","
              + to_string(user_id) + ");";
        int test_id = DB.SQLOperation(sql);

        for (auto group : groups_of_test) {
            cout << group.getID() << " " << test_id  << endl;
            DB.SQLOperation("INSERT INTO GROUP_TESTS (GROUP_ID, TEST_ID) VALUES ("
                            + to_string(group.getID()) + ", "
                            + to_string(test_id) + ");");
        }

        add_questions_to_table(questions, test_id);
    }

    static vector<Test> show_tests(int user_id) {
        SqlGateway DB;

        string sql = "SELECT * FROM TESTS WHERE USER_ID = " + to_string(user_id);
        vector<Test> tests = DB.getData<Test>(sql);

        for (auto test : tests) {
            cout << test;
        }

        return tests;
    }

    template<class T>
    static void change(string sql) {
        SqlGateway DB;

        vector<T> objs = DB.getData<T>(sql);

        if (objs.empty()) {
            cout << "Нет доступных объектов для изменения" << endl;
            return;
        }

        while (true) {
            cout << "Выберите номер объекта, который хотите изменить(0 для выхода)" << endl;
            show_vector<T>(objs);

            int id = getInt(0, objs.size());
            if (id == 0) {
                break;
            }

            objs[--id].change();
        }
    }

    template<class T>
    static void del(string sql) {
        SqlGateway DB;

        vector<T> objs = DB.getData<T>(sql);

        string table_name = typeid(T).name();
        table_name = table_name.substr(1) + "s";

        if (objs.empty()) {
            cout << "Нет доступных объектов для удаления" << endl;
            return;
        }

        while (true) {
            cout << "Выберите номер группы, которую хотите удалить(0 для выхода)" << endl;
            for (int i = 0; i < objs.size(); i++) {
                cout << i + 1 << " - " << objs[i].getName() << endl;
            }

            int id = getInt(0, objs.size());
            if (id == 0) {
                break;
            }

            id--;
            cout << "Вы уверены, что хотите сохранить изменения?" << endl;
            cout << "1 - Да" << endl;
            cout << "2 - Нет" << endl;
            int op_men = getInt(1, 2);
            if (op_men == 1) {
                sql = "PRAGMA foreign_keys = ON;\n"
                      "DELETE FROM " + table_name + " WHERE ID = " + to_string(objs[id].getID())
                      + ";\nPRAGMA foreign_keys = OFF;";
                DB.SQLOperation(sql);
                return;
            }
        }
    }

};

#endif //COURSE_TEST_INTERFACE_H
