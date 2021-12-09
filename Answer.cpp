//
// Created by danila on 7.12.21.
//

#include "Answer.h"

Answer &Answer::operator=(const Answer &answer) {
    if (&answer != this) {
        this->id = answer.id;
        this->text = answer.text;
    }

    return *this;
}

void Answer::get_data(sqlite3_stmt *stmt) {
    this->id = sqlite3_column_int(stmt, 0);
    this->text = string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
}

void Answer::set_text(string ans) {
    this->text = ans;
}

string Answer::get_text() {
    return this->text;
}

int Answer::get_id() {
    return this->id;
}
