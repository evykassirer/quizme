#ifndef QUIZME_CPP //checks to make sure this hasn't been run already to avoid double declarations
#define QUIZME_CPP
#include"quizme.h"
#include <ctime>
#include<stdio.h>
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<stdlib.h>
#include<vector>
//#include <allegro.h>
using namespace std;

//input from textfile
bool takeinput (){
    ifstream infile;
    infile.open("input.txt");
    char input[500];    //500 is max per line of input
   
    infile.getline(input, 500);
    while(input[0] != '~'){
        allq.resize(allq.size()+1);
        
        allq[allq.size()-1].category = string(input);
        infile.getline(input, 500);
        if(string(input) == "TF" || string(input) == "MC" || string(input) == "CUE") 
            allq[allq.size()-1].t = string(input);
        else {
            cout << "Error - input is not a predefined type. You entered: " << input << endl;
            system("pause");
            return true;   
        }
        
        infile.getline(input, 500);
        while(input[0] != '*'){
            allq[allq.size()-1].qs.resize(allq[allq.size()-1].qs.size()+1);
            allq[allq.size()-1].qs[allq[allq.size()-1].qs.size()-1].q = input; 
            infile.getline(input, 500);
            allq[allq.size()-1].qs[allq[allq.size()-1].qs.size()-1].a = input;
            infile.getline(input, 500);
        }
        infile.getline(input, 500);
    }
    if(allq.size() == 0) return true;
    return false;
}
    
//asks individual questions of the following types
bool TorF(string category, string q, char a){
    system("cls");
    char answ;
    cout << endl << "Category: " << category << endl << "Enter one of the following answers: t  f -- or q to quit" << endl << endl << q << endl << "Your answer: ";
    cin >> answ;
    if(answ == 'q') return false;
    cout << endl;
    if(a == answ || toupper(a) == answ) cout << "Correct!";
    else cout << "Correct answer: " << a;
    cout << endl << "(Press any key to continue or q to quit)" << endl;
    fflush(stdin);
    if(getchar() == 'q') return false;;
    return true;
}

bool cueCard(string category, string q, string a){
    /*
    //buffer
    static BITMAP *buffer = create_bitmap(540,550);
    //load bitmap
    static BITMAP *cuecard = load_bitmap("cuecard.bmp", 0); //background
    //load bitmap
    static BITMAP *cuecardnext = load_bitmap("cuecard.bmp", 0); //background
    //clear screen
    clear_bitmap(buffer); 
    //print background
    draw_sprite(buffer, cuecard, 0, 0);
    //print buffer to screen
    blit (buffer, screen, 0,0,0,0,540,550);
    
    //font
    extern FONT *font;
    //prints question
    textout_ex(cuecard, font, q.c_str(), 80, 272,
		 makecol(0, 0, 0), -1);
    */
        //also print the category****
    
    /*
    bool click = false; //waits for the click to be released before taking another click
    while(!click){        
        if (mouse_b & 1) {
            if (mouse_x > 20 && mouse_x < 225 && mouse_y > 20 && mouse_y < 85){
                //menu
                return false;
            }
            if (mouse_x > 314 && mouse_x < 519 && mouse_y > 20 && mouse_y < 85){
               //quit
               return false;
            }
            if (mouse_x > 167 && mouse_x < 370 && mouse_y > 460 && mouse_y < 520){
                //clear screen
                clear_bitmap(buffer); 
                //print background
                draw_sprite(buffer, cuecardnext, 0, 0);
                //print buffer to screen
                blit (buffer, screen, 0,0,0,0,540,550); 
                //PRINT ANSWER*****************
                click = true;
            }
        }
    }*/
                
                
    system("cls");
    cout << endl << "Category: " << category << endl << "Press enter to see answer or q to quit" << endl << endl << "Question: " << q << endl << endl;
    fflush(stdin);
    if(getchar() == 'q') return false;
    cout << "Answer: " << a << endl << endl; 
    cout << endl << "(Press any key to continue or q to quit)" << endl;
    fflush(stdin);
    if(getchar() == 'q') return false;
    return true;
}

bool MC(string category, string q, string a, string aarray[4]){
    system("cls");
    char answ;
    cout << endl << "Category: " << category << endl << "Enter your answer or q to quit" << endl << endl << "Question: " << q << endl;
    for(int i = 0; i < 4; i++){
        cout << i << " : " << aarray[i] << endl;
    }
    cout << endl << "Index of your answer: ";
    fflush(stdin);
    answ = getchar();
    if(answ == 'q') return false;
    if(aarray[atoi(&answ)] == a) cout << "Correct!" << endl << endl;
    else cout << endl << "Answer: " << a << endl << endl;
    cout << endl << "(Press any key to continue or q to quit)" << endl;
    fflush(stdin);
    if(getchar() == 'q') return false;
    return true;
}


//helper functions
bool notin (int randi, int i, int randnum[4], question_group qgroup){ //for the multiple choice, checks if the answer selected has already been selected
    for(int j = 0; j < i; j++) {
        if(qgroup.qs[randnum[j]].a == qgroup.qs[randi].a) return true;
    } 
    return false;
}


//main menu
bool mainMenu(){
    while(1){
        char index = '`';
        while((index != 'q') && (atoi(&index) > int(allq.size()) || atoi(&index) <= 0)){
            system("cls");
            cout << "Please choose the category/type of question you would like to test" << endl << endl;
            for (int i = 0; i < allq.size(); i++){
                cout << i+1 << " : " << allq[i].category << " -- " << allq[i].t << endl;
            }        
            cout << endl << "Enter index here, or q to quit: ";
            cin >> index;         
        }
        if(index == 'q') return true;
         
        question_group qgroup = allq[atoi(&index)-1];
        
        if(qgroup.t == "TF"){
            srand(time(0));
            int randnum = (rand()%(qgroup.qs.size()));
            while(TorF(qgroup.category, qgroup.qs[randnum].q, qgroup.qs[randnum].a[0])){
                srand(time(0));
                randnum = (rand()%qgroup.qs.size());
                cout << randnum;   
            } 
        }else 
        //Cue cards
        if(qgroup.t == "CUE"){
            srand(time(0));
            int randnum = (rand()%qgroup.qs.size());
            while(cueCard(qgroup.category, qgroup.qs[randnum].q, qgroup.qs[randnum].a)){
                srand(time(0));
                randnum = (rand()%qgroup.qs.size());
            } 
        }
        else
        //Multiple choice
        if(qgroup.t == "MC"){
                   
            int randnum[4], randq;
            string aarray[4];
         
            do{
                srand(time(0));
                randq = (rand()%qgroup.qs.size());
                randnum[0] = randq;
                for(int i = 1; i < 4; i++){
                    srand(time(0));
                    int randi = (rand()%qgroup.qs.size());
                    while(notin(randi, i, randnum, qgroup)){
                        randi = (rand()%qgroup.qs.size());
                    }
                    randnum[i] = randi;
                }
                srand(time(0));
                int swap = (rand()%4);
                int temp = randq;
                randnum[0] = randnum[swap];
                randnum[swap] = temp;      
                for(int i = 0; i < 4; i++){
                    aarray[i] = qgroup.qs[randnum[i]].a;
                }        
            }while(MC(qgroup.category, qgroup.qs[randq].q, qgroup.qs[randq].a, aarray)); 
        }
        else return true;
        
        system("cls");
        cout << "Enter q again to quit the program," << endl << "or any other key to go back to the main screen" << endl;
        fflush(stdin);
        if(getchar() == 'q') return true;
        system("cls");
    }
}

#endif
