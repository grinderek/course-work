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

void Test::setID(int ide) {
    this->id = ide;
}

int Test::getID() {
    return this->id;
}

void Test::setName(string topic) {
    this->name = topic;
}

void Test::setQuestions(vector<Question_Many_Variants> list_of_questions) {
    this->questions = list_of_questions;
}

vector <Question_Many_Variants> Test::getQuestions() {
    return this->questions;
}

string Test::getName() {
    return this->name;
}

void Test::setCountOfQuestions(int number) {
    this->number_of_questions = number;
}

int Test::getCountOfQuestions() {
    return this->number_of_questions;
}

void Test::get_data(sqlite3_stmt *stmt) {
    SqlGateway DB;
    this->id = sqlite3_column_int(stmt, 0);
    this->name = string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
    this->number_of_questions = sqlite3_column_int(stmt, 2);

    string sql = "SELECT * FROM QUESTIONS WHERE TEST_ID = " + to_string(this->id);
    this->questions = DB.getData<Question_Many_Variants>(sql);
}
