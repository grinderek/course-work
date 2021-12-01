//
// Created by danila on 1.12.21.
//

#include "Question_Many_Variants.h"

Question_Many_Variants::Question_Many_Variants() {
    this->question_text = "...";
    this->number_of_answers = 0;
    this->answers = nullptr;
    this->correct_answer = 0;
}

Question_Many_Variants::Question_Many_Variants(string question, int number_of_answers, string* answers, int correct_answer) {
    this->question_text = std::move(question);
    this->number_of_answers = number_of_answers;
    this->answers = new string[number_of_answers];
    for (int i = 0; i < number_of_answers; i++)
        this->answers[i] = answers[i];
    this->correct_answer = correct_answer;
}

Question_Many_Variants::Question_Many_Variants(const Question_Many_Variants &question) {
    this->question_text = question.question_text;
    this->number_of_answers = question.number_of_answers;
    this->answers = new string[question.number_of_answers];
    for (int i = 0; i < question.number_of_answers; i++)
        this->answers[i] = question.answers[i];
    this->correct_answer = question.correct_answer;
}

Question_Many_Variants::~Question_Many_Variants() {
    delete[] this->answers;
}

string Question_Many_Variants::getQuestion() {
    return this->question_text;
}

Question_Many_Variants& Question_Many_Variants::operator= (const Question_Many_Variants& question) {
    if (&question != this) {
        this->question_text = question.question_text;
        this->number_of_answers = question.number_of_answers;
        this->answers = new string[question.number_of_answers];
        for (int i = 0; i < question.number_of_answers; i++)
            this->answers[i] = question.answers[i];
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
    question.answers = new string[question.number_of_answers];
    cout << "Enter answers\n";
    for (int i = 0; i < question.number_of_answers; i++) {
        cout << "Answer " << i + 1 << ": ";
        question.answers[i] = getString();
    }
    cout << "Enter number of right answer\n";
    question.correct_answer = getInt(1, question.number_of_answers) - 1;

    return in;
}