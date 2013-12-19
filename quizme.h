#ifndef QUIZME_H //checks to make sure this header hasn't been run already to avoid double declarations
#define QUIZME_H

#include<stdio.h>
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<stdlib.h>
#include<vector>
//#include <allegro.h>
using namespace std;

//structures used to store the questions
struct question{
    string q,a;
};
struct question_group{
    string category;
    string t;
    vector<question> qs; 
};

//global variable
vector<question_group> allq;

//input from file
bool takeinput ();


bool TorF(string category, string q, char a); //runs one true or false question
bool cueCard(string category, string q, string a); //runs one cue card question
bool MC(string category, string q, string a, string aarray[4]); //runs one multiple choice question

//helper functions
bool notin (int randi, int i, int randnum[4], question_group qgroup); //for the multiple choice, checks if the answer selected has already been selected

bool mainMenu(); //main menu

#endif
