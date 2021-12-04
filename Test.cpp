//
// Created by danila on 3.12.21.
//

#include "Test.h"

ostream &operator<<(ostream &out, const Test &test) {
    out << "Тема теста - " << test.name << endl;
    out << "Вопросы теста: " << endl;
    int i = 1;
    for (auto question : test.questions) {
        out << "Вопрос №" << i++ << ":\n";
        out << question.getQuestion() << endl;
        auto answers = question.getAnswers();

        int j = 1;
        map <int, int> ids;
        for (const auto& answer : answers) {
            ids[answer.first] = j;
            out << j++ << " - " << answer.second << endl;
        }

        out << "Правильный ответ - " << ids[question.getCorrectAnswer()] << "\n\n";
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
