//
// Created by danila on 30.11.21.
//

#include "TestInterface.h"

void TestInterface::tests_menu(int user_id) {
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
            change_test(user_id);
            break;
        case 4:
            delete_test(user_id);
            break;
        default:
            cout << "Что-то не так" << endl;
    }
}

int add_correctAnswer_to_table(int answer_id, int question_id) {
    SqlGateway DB;
    string sql = "INSERT INTO CORRECT_ANSWERS (ANSWER_ID, QUESTION_ID) VALUES ("
                 + to_string(answer_id) + ","
                 + to_string(question_id) + ");";

    int id = DB.SQLOperation(sql);

    return id;
}

int add_answers_to_table(Question question, int question_id) {
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

int add_questions_to_table(vector<Question> questions, int test_id) {
    SqlGateway DB;
    for (auto question : questions) {
        string sql = "INSERT INTO QUESTIONS (TEXT_OF_QUESTION, TEST_ID) VALUES ("
                     + quotesql(question.getName()) + ","
                     + to_string(test_id) + ");";

        int id = DB.SQLOperation(sql);
        add_answers_to_table(question, id);
    }
}

void TestInterface::add_test(int user_id) {
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

vector<Test> TestInterface::show_tests(int user_id) {
    SqlGateway DB;

    string sql = "SELECT * FROM TESTS WHERE USER_ID = " + to_string(user_id);
    vector<Test> tests = DB.getData<Test>(sql);

    for (auto test : tests) {
        cout << test;
    }

    return tests;
}

void TestInterface::delete_test(int user_id) {
    SqlGateway DB;
    string sql = "SELECT * FROM TESTS WHERE USER_ID = " + to_string(user_id);
    auto tests = DB.getData<Test>(sql);

    if (tests.empty()) {
        cout << "Нет доступных тестов для удаления" << endl;
        return;
    }

    show_vector<Test>(tests);
    while (true) {
        cout << "Введите номер теста, который хотите удалить(0 для выхода)" << endl;
        int id = getInt(0, tests.size());

        if (id == 0) {
            break;
        }

        cout << "Вы уверены, что хотите удалить этот тест?" << endl;
        cout << "1 - Да" << endl;
        cout << "2 - Нет" << endl;
        int x = getInt(1, 2);
        if (x == 1) {
            sql = "PRAGMA foreign_keys = ON;\n"
                  "DELETE FROM TESTS WHERE ID = " + to_string(tests[--id].getID());
                  + ";\nPRAGMA foreign_keys = OFF;";

            DB.SQLOperation(sql);
            break;
        }
    }
}

void TestInterface::change_test(int user_id) {
    SqlGateway DB;
    string sql = "SELECT * FROM TESTS WHERE USER_ID = " + to_string(user_id);
    auto tests = DB.getData<Test>(sql);

    if (tests.empty()) {
        cout << "Нет доступных объектов для изменения" << endl;
        return;
    }

    show_vector<Test>(tests);
    cout << "Введите номер объекта, который хотите изменить(0 для выхода)" << endl;
    int id = getInt(0, tests.size());

    if (id == 0) {
        return;
    }

    tests[--id].change();
}