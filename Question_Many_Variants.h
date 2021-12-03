//
// Created by danila on 1.12.21.
//

#ifndef COURSE_TEST_QUESTION_MANY_VARIANTS_H
#define COURSE_TEST_QUESTION_MANY_VARIANTS_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include "Service.h"
#include "User.h"

using namespace std;

class User;
class Question_Many_Variants {
private:
    string question_text;
    int number_of_answers;
    vector <string> answers;
    int correct_answer;

public:
    Question_Many_Variants();

    Question_Many_Variants(string question, int number_of_answers, vector<string> answers, int correct_answer);

    Question_Many_Variants(const Question_Many_Variants &question);

    ~Question_Many_Variants();

    string getQuestion();
    int getCorrectAnswer();


    Question_Many_Variants& operator= (const Question_Many_Variants& question);

    friend class User;
    friend ostream& operator<< (ostream &out, const Question_Many_Variants &question);
    friend istream& operator>> (istream &in, Question_Many_Variants &question);

    vector<string> getAnswers();
};

ostream& operator<< (ostream &out, const Question_Many_Variants &question);
istream& operator>> (istream &in, Question_Many_Variants &question);


#endif //COURSE_TEST_QUESTION_MANY_VARIANTS_H
