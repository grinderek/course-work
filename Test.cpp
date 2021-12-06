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
