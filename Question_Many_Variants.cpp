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

Question_Many_Variants::Question_Many_Variants(string question, int number_of_answers, vector<string> answers, int correct_answer) {
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

vector<string> Question_Many_Variants::getAnswers() {
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
    for (int i = 0; i < question.number_of_answers; i++) {
        out << "Answer " << i + 1 << ": " << question.answers[i] << endl;
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
        question.answers.push_back(getString());
    }
    cout << "Enter number of right answer\n";
    question.correct_answer = getInt(1, question.number_of_answers) - 1;

    return in;
}