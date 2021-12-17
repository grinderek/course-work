//
// Created by danila on 1.12.21.
//

#include "Question.h"

#include <utility>

string Question::getName() {
    return this->question_text;
}

int Question::getCorrectAnswer() {
    return this->correct_answer;
}

vector<Answer> Question::getAnswers() {
    return this->answers;
}

Question& Question::operator= (const Question& question) {
    if (&question != this) {
        this->question_id = question.question_id;
        this->question_text = question.question_text;
        this->number_of_answers = question.number_of_answers;
        this->answers = question.answers;
        this->correct_answer = question.correct_answer;
    }

    return *this;
}

ostream& operator<< (ostream &out, const Question &question)
{
    out << "Вопрос - " << question.question_text << endl;
    auto answers = question.answers;

    int j = 1;
    map <int, int> ids;
    for (auto answer : answers) {
        ids[answer.get_id()] = j;
        out << j++ << " - " << answer.getName() << endl;
    }

    //out << "Правильный ответ - " << ids[question.correct_answer] << "\n\n";
    return out;
}


istream& operator>> (istream &in, Question &question)
{
    cout << "Текст вопроса\n";
    question.question_text = getString();
    cout << "Количество ответов\n";
    question.number_of_answers = getInt(1, INT_MAX);
    cout << "Введите ответы\n";
    question.answers.resize(question.number_of_answers);
    for (int i = 0; i < question.number_of_answers; i++) {
        cout << "Ответ №" << i + 1 << ": ";
        question.answers[i].set_text(getString());
    }
    cout << "Введите номер правильного ответа\n";
    question.correct_answer = getInt(1, question.number_of_answers) - 1;

    return in;
}

int Question::getID() {
    return this->question_id;
}

void Question::setID(int ide) {
    this->question_id = ide;
}

void Question::setQuestionText(string text) {
    this->question_text = text;
}

void Question::setAnswers(vector<Answer> ans) {
    this->answers = ans;
}

void Question::setCorrectAnswer(int ide) {
    this->correct_answer = ide;
}

void Question::get_data(sqlite3_stmt *stmt) {
    SqlGateway DB;

    this->question_id = sqlite3_column_int(stmt, 0);
    this->question_text = string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));

    string sql = "SELECT * FROM ANSWERS WHERE QUESTION_ID = " + to_string(this->question_id);
    this->answers = DB.getData<Answer>(sql);

    sql = "SELECT ANSWER_ID FROM CORRECT_ANSWERS WHERE QUESTION_ID = " + to_string(this->question_id);
    this->correct_answer = DB.getData<JustInt>(sql)[0].getVal();
}

void Question::change() {
    SqlGateway DB;

    cout << *this << endl;
    cout << "Что вы хотите изменить?" << endl;
    cout << "1 - Текст вопроса" << endl;
    cout << "2 - Ответы" << endl;
    cout << "0 - Выход" << endl;
    int op_menu = getInt(0, 2);

    switch (op_menu) {
        case 0:
            return;
        case 1: {
            cout << "Введите новый вопрос" << endl;
            string text = getString();
            cout << "Вы уверены, что хотите сохраните изменения?" << endl;
            cout << "1 - Да" << endl;
            cout << "2 - Нет" << endl;

            int x = getInt(1, 2);
            if (x == 1) {
                string sql = "PRAGMA foreign_keys = ON;\n"
                             "UPDATE QUESTIONS SET TEXT_OF_QUESTION = " + quotesql(text) + " WHERE ID = " +
                             to_string(this->question_id) + ";\nPRAGMA foreign_keys = OFF;";
                DB.SQLOperation(sql);
            }
        }

        case 2:
            show_vector<Answer>(answers);
            while (true) {
                cout << "Введите номер ответа, который хотите изменить(0 для выхода)" << endl;
                int id = getInt(0, answers.size());
                if (id == 0) {
                    return;
                } else {
                    answers[--id].change();
                }
            }
    }
}

