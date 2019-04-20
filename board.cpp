/*
 * File: c:\Users\Conor\Documents\GitHub\Hangman\board.cpp
 * Project: c:\Users\Conor\Documents\GitHub\Hangman
 * Created Date: Saturday April 20th 2019 8:21:05 pm
 * Author: ConorHK
 * -----
 * Description:
 */

#include <iostream>
#include "board.h"
using namespace std;

void printBoard(int mistakes){

    cout  << "HANGMAN" << endl;
    cout << "___________________" <<  endl;
    cout << "|                  |" << endl;
    
    if(mistakes >= 1){
        cout << "|                  @" << endl;
    }
    else{
        cout << "|" << endl;
    }
    if(mistakes == 2){
       cout << "|                  |" << endl; 
    }
    else if(mistakes == 3){
        cout << "|                 \\|" << endl; 
    }
    else if(mistakes >= 4){
        cout << "|                 \\|/" << endl; 
    }
    else{
        cout << "|" << endl;
    }
    if(mistakes >=4){
        cout << "|                  |" << endl; 
    }
    else{
        cout << "|" << endl;
    }
    if(mistakes == 5){
        cout << "|                 /" << endl; 
    }
    else if(mistakes >= 6){
        cout << "|                 / \\" << endl;
    }
    else{
        cout << "|" << endl;
    }
    cout << "___________________" <<  endl;

}