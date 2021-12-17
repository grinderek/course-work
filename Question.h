//
// Created by danila on 1.12.21.
//

#ifndef COURSE_TEST_QUESTION_H
#define COURSE_TEST_QUESTION_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include "Answer.h"
#include "SqlGateway.h"
#include "Service.h"
#include "Test.h"
#include "User.h"

using namespace std;

class User;
class Test;
class Answer;
class Question {
private:
    int question_id;
    string question_text;
    int number_of_answers;
    int correct_answer;

    vector<Answer> answers;

public:
    string getName();
    int getCorrectAnswer();
    int getID();
    void setQuestionText(string text);
    void setAnswers(vector<Answer> ans);
    void setCorrectAnswer(int ide);
    void setID(int ide);

    void change();
    void get_data(sqlite3_stmt *stmt);


    Question& operator= (const Question& question);

    friend class User;
    friend ostream& operator<< (ostream &out, const Question &question);
    friend istream& operator>> (istream &in, Question &question);

    vector<Answer> getAnswers();
};

ostream& operator<< (ostream &out, const Question &question);
istream& operator>> (istream &in, Question &question);


#endif //COURSE_TEST_QUESTION_H
