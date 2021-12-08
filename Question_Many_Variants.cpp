//
// Created by danila on 1.12.21.
//

#include "Question_Many_Variants.h"

#include <utility>

Question_Many_Variants::Question_Many_Variants() {
    this->question_text = "...";
    this->number_of_answers = 0;
    this->correct_answer = 0;
}

Question_Many_Variants::Question_Many_Variants(string question, int number_of_answers, vector<Answer> answers, int correct_answer) {
    this->question_text = std::move(question);
    this->number_of_answers = number_of_answers;
    this->answers = std::move(answers);
    this->correct_answer = correct_answer;
}

Question_Many_Variants::Question_Many_Variants(const Question_Many_Variants &question) {
    this->id = question.id;
    this->question_text = question.question_text;
    this->number_of_answers = question.number_of_answers;
    this->answers = question.answers;
    this->correct_answer = question.correct_answer;
}

Question_Many_Variants::~Question_Many_Variants() {
    this->answers.clear();
}

string Question_Many_Variants::getQuestion() {
    return this->question_text;
}

int Question_Many_Variants::getCorrectAnswer() {
    return this->correct_answer;
}

vector<Answer> Question_Many_Variants::getAnswers() {
    return this->answers;
}

Question_Many_Variants& Question_Many_Variants::operator= (const Question_Many_Variants& question) {
    if (&question != this) {
        this->id = question.id;
        this->question_text = question.question_text;
        this->number_of_answers = question.number_of_answers;
        this->answers = question.answers;
        this->correct_answer = question.correct_answer;
    }

    return *this;
}

ostream& operator<< (ostream &out, const Question_Many_Variants &question)
{
    out << question.question_text << endl;
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


istream& operator>> (istream &in, Question_Many_Variants &question)
{
    cout << "Enter question\n";
    question.question_text = getString();
    cout << "Enter count of answers\n";
    question.number_of_answers = getInt(1, INT_MAX);
    cout << "Enter answers\n";
    question.answers.resize(question.number_of_answers);
    for (int i = 0; i < question.number_of_answers; i++) {
        cout << "Answer " << i + 1 << ": ";
        question.answers[i].set_text(getString());
    }
    cout << "Enter number of right answer\n";
    question.correct_answer = getInt(1, question.number_of_answers) - 1;

    return in;
}

int Question_Many_Variants::getID() {
    return this->id;
}

void Question_Many_Variants::setID(int ide) {
    this->id = ide;
}

void Question_Many_Variants::setQuestionText(string text) {
    this->question_text = text;
}

void Question_Many_Variants::setAnswers(vector<Answer> ans) {
    this->answers = ans;
}

void Question_Many_Variants::setCorrectAnswer(int ide) {
    this->correct_answer = ide;
}

void Question_Many_Variants::get_data(sqlite3_stmt *stmt) {
    SqlGateway DB;

    this->id = sqlite3_column_int(stmt, 0);
    this->question_text = string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));

    string sql = "SELECT * FROM ANSWERS WHERE QUESTION_ID = " + to_string(this->id);
    this->answers = DB.getData<Answer>(sql);

    sql = "SELECT ANSWER_ID FROM CORRECT_ANSWERS WHERE QUESTION_ID = " + to_string(this->id);
    this->correct_answer = DB.getData<JustInt>(sql)[0].getVal();
}

