//
// Created by danila on 1.12.21.
//

#include "Question.h"

#include <utility>

string Question::getQuestion() {
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
        this->id = question.id;
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
        out << j++ << " - " << answer.get_text() << endl;
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
    return this->id;
}

void Question::setID(int ide) {
    this->id = ide;
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

    this->id = sqlite3_column_int(stmt, 0);
    this->question_text = string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));

    string sql = "SELECT * FROM ANSWERS WHERE QUESTION_ID = " + to_string(this->id);
    this->answers = DB.getData<Answer>(sql);

    sql = "SELECT ANSWER_ID FROM CORRECT_ANSWERS WHERE QUESTION_ID = " + to_string(this->id);
    this->correct_answer = DB.getData<JustInt>(sql)[0].getVal();
}

