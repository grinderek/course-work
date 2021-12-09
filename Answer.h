//
// Created by danila on 7.12.21.
//

#ifndef COURSE_TEST_ANSWER_H
#define COURSE_TEST_ANSWER_H
#include <iostream>
#include <string>
#include "SqlGateway.h"

using namespace std;

class Answer {
private:
    int id;
    string text;
public:
    int get_id();

    string get_text();

    void set_text(string ans);

    void get_data(sqlite3_stmt *stmt);

    Answer& operator= (const Answer& answer);
};


#endif //COURSE_TEST_ANSWER_H
