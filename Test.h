//
// Created by danila on 3.12.21.
//

#ifndef COURSE_TEST_TEST_H
#define COURSE_TEST_TEST_H
#include <iostream>
#include <string>
#include <vector>
#include "Question.h"
#include "SqlGateway.h"

using namespace std;

class Question;
class Test {
private:
    int id;
    string name;
    int number_of_questions;
    vector<Question> questions;
public:
    int getID();
    string getName();
    void setQuestions(vector<Question> list_of_questions);
    vector<Question> getQuestions();

    void get_data(sqlite3_stmt *stmt);

    friend ostream& operator<< (ostream &out, const Test &test);
    friend istream& operator>> (istream &in, Test &test);
};

ostream& operator<< (ostream &out, const Test &test);
istream& operator>> (istream &in, Test &test);
#endif //COURSE_TEST_TEST_H