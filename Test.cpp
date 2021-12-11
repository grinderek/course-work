//
// Created by danila on 3.12.21.
//

#include "Test.h"

ostream &operator<<(ostream &out, const Test &test) {
    out << "ID - " << test.id << endl;
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
    return this->id;
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
    this->id = sqlite3_column_int(stmt, 0);
    this->name = string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
    this->number_of_questions = sqlite3_column_int(stmt, 2);

    string sql = "SELECT * FROM QUESTIONS WHERE TEST_ID = " + to_string(this->id);
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
