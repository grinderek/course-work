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

Question_Many_Variants::Question_Many_Variants(string question, int number_of_answers, map<int, string> answers, int correct_answer) {
    this->question_text = std::move(question);
    this->number_of_answers = number_of_answers;
    this->answers = std::move(answers);
    this->correct_answer = correct_answer;
}

Question_Many_Variants::Question_Many_Variants(const Question_Many_Variants &question) {
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

map<int, string> Question_Many_Variants::getAnswers() {
    return this->answers;
}

Question_Many_Variants& Question_Many_Variants::operator= (const Question_Many_Variants& question) {
    if (&question != this) {
        this->question_text = question.question_text;
        this->number_of_answers = question.number_of_answers;
        this->answers = question.answers;
        this->correct_answer = question.correct_answer;
    }

    return *this;
}

ostream& operator<< (ostream &out, const Question_Many_Variants &question)
{
    out << "Question: " << question.question_text << endl;
    for (auto answer : question.answers) {
        out << "Answer " << answer.first << ": " << answer.second << endl;
    }
    return out;
}

istream& operator>> (istream &in, Question_Many_Variants &question)
{
    cout << "Enter question\n";
    question.question_text = getString();
    cout << "Enter count of answers\n";
    question.number_of_answers = getInt(1, INT_MAX);
    cout << "Enter answers\n";
    for (int i = 0; i < question.number_of_answers; i++) {
        cout << "Answer " << i + 1 << ": ";
        question.answers[i] = getString();
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

void Question_Many_Variants::setAnswers(map<int, string> ans) {
    this->answers = ans;
}

void Question_Many_Variants::setCorrectAnswer(int ide) {
    this->correct_answer = ide;
}
