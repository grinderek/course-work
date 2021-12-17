//
// Created by danila on 3.12.21.
//

#include "Test.h"

ostream &operator<<(ostream &out, const Test &test) {
    out << "ID - " << test.test_id << endl;
    out << "Тема теста - " << test.name << endl;
    out << "Вопросы теста: " << endl;
    int i = 1;
    for (auto question : test.questions) {
        out << "Вопрос №" << i++ << ":\n";
        out << question << endl;
    }

    return out;
}

int Test::getID() {
    return this->test_id;
}

void Test::setQuestions(vector<Question> list_of_questions) {
    this->questions = list_of_questions;
}

vector <Question> Test::getQuestions() {
    return this->questions;
}

string Test::getName() {
    return this->name;
}

void Test::get_data(sqlite3_stmt *stmt) {
    SqlGateway DB;
    this->test_id = sqlite3_column_int(stmt, 0);
    this->name = string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
    this->number_of_questions = sqlite3_column_int(stmt, 2);

    string sql = "SELECT * FROM QUESTIONS WHERE TEST_ID = " + to_string(this->test_id);
    this->questions = DB.getData<Question>(sql);
}

istream &operator>>(istream &in, Test &test) {
    cout << "Тема вопроса\n";
    test.name = getString();
    cout << "Количество вопросов\n";
    test.number_of_questions = getInt(1, INT_MAX);
    cout << "Введите вопросы\n";
    test.questions.resize(test.number_of_questions);
    for (int i = 0; i < test.number_of_questions; i++) {
        cout << "Вопрос №" << i + 1 << ": ";
        Question question;
        cin >> question;
        test.questions.push_back(question);
    }
    return in;
}

void Test::change() {
    SqlGateway DB;

    cout << *this;
    cout << "Что вы хотите изменить?" << endl;
    cout << "1 - Тему теста" << endl;
    cout << "2 - Вопросы" << endl;
    cout << "0 - Выход" << endl;
    int op_menu = getInt(0, 2);

    switch (op_menu) {
        case 0:
            return;
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
                             to_string(this->test_id) + ";\nPRAGMA foreign_keys = OFF;";
                DB.SQLOperation(sql);
                break;
            }
        }
            break;
        case 2: {
            show_vector(this->questions);
            cout << "Введите номер вопроса, который хотите изменить(0 для выхода)" << endl;
            int id = getInt(0, this->questions.size());
            if (id == 0) {
                break;
            }
            questions[--id].change();
        }
            break;
        default:
            cout << "Что-то пошло не так" << endl;
    }
}
