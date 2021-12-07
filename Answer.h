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
    int get_id() {
        return this->id;
    }

    string get_text() {
        return this->text;
    }

    void set_text(string ans) {
        this->text = ans;
    }

    void get_data(sqlite3_stmt *stmt) {
        this->id = sqlite3_column_int(stmt, 0);
        this->text = string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
    };

    Answer& operator= (const Answer& answer) {
        if (&answer != this) {
            this->id = answer.id;
            this->text = answer.text;
        }

        return *this;
    }
};


#endif //COURSE_TEST_ANSWER_H
