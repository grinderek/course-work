//
// Created by danila on 3.12.21.
//

#ifndef COURSE_TEST_TEST_H
#define COURSE_TEST_TEST_H
#include <iostream>
#include <string>
#include <vector>
#include "Question_Many_Variants.h"

using namespace std;

class Test {
private:
    int id;
    string name;
    vector<Question_Many_Variants> questions;
public:

    void setID(int ide);
    int getID();
    void setName(string topic);
    void setQuestions(vector<Question_Many_Variants> list_of_questions);
    vector<Question_Many_Variants> getQuestions();

    friend ostream& operator<< (ostream &out, const Test &test);
};

ostream& operator<< (ostream &out, const Test &test);
#endif //COURSE_TEST_TEST_H
