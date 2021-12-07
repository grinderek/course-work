//
// Created by danila on 1.12.21.
//

#ifndef COURSE_TEST_QUESTION_MANY_VARIANTS_H
#define COURSE_TEST_QUESTION_MANY_VARIANTS_H

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
class Question_Many_Variants {
private:
    int id;
    string question_text;
    int number_of_answers;
    int correct_answer;

    vector<Answer> answers;

public:
    Question_Many_Variants();

    Question_Many_Variants(string question, int number_of_answers, vector<Answer> answers, int correct_answer);

    Question_Many_Variants(const Question_Many_Variants &question);

    ~Question_Many_Variants();

    string getQuestion();
    int getCorrectAnswer();
    int getID();
    void setQuestionText(string text);
    void setAnswers(vector<Answer> ans);
    void setCorrectAnswer(int ide);
    void setID(int ide);

    void get_data(sqlite3_stmt *stmt);


    Question_Many_Variants& operator= (const Question_Many_Variants& question);

    friend class User;
    friend ostream& operator<< (ostream &out, const Question_Many_Variants &question);
    friend istream& operator>> (istream &in, Question_Many_Variants &question);

    vector<Answer> getAnswers();
};

ostream& operator<< (ostream &out, const Question_Many_Variants &question);
istream& operator>> (istream &in, Question_Many_Variants &question);


#endif //COURSE_TEST_QUESTION_MANY_VARIANTS_H
