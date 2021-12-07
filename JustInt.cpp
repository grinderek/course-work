//
// Created by danila on 7.12.21.
//

#include "JustInt.h"

void JustInt::setVal(int x) {
    this->val = x;
}

int JustInt::getVal() {
    return this->val;
}

void JustInt::get_data(sqlite3_stmt *stmt) {
    this->val = sqlite3_column_int(stmt, 0);
}


