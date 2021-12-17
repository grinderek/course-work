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

string Answer::getName() {
    return this->text;
}

int Answer::get_id() {
    return this->id;
}

void Answer::change() {
    SqlGateway DB;

    cout << this->getName() << endl;
    cout << "Что вы хотите изменить?" << endl;
    cout << "1 - Текст ответа" << endl;
    cout << "0 - Выход" << endl;
    int op_menu = getInt(0, 1);

    switch (op_menu) {
        case 0:
            return;
        case 1: {
            cout << "Введите новый ответ" << endl;
            string text = getString();
            cout << "Вы уверены, что хотите сохраните изменения?" << endl;
            cout << "1 - Да" << endl;
            cout << "2 - Нет" << endl;
            int x = getInt(1, 2);
            if (x == 1) {
                string sql = "PRAGMA foreign_keys = ON;\n"
                             "UPDATE ANSWERS SET TEXT_OF_ANSWER = " + quotesql(text) + " WHERE ID = " +
                             to_string(this->id) + ";\nPRAGMA foreign_keys = OFF;";
                DB.SQLOperation(sql);
            }
        }
            break;
        default:
            cout << "Что-то пошло не так" << endl;
    }
}

ostream& operator<< (ostream &out, const Answer &answer)
{
    out << answer.text;
    return out;
}