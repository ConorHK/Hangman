/*
 * File: c:\Users\Conor\Documents\GitHub\Hangman\game_logic.cpp
 * Project: c:\Users\Conor\Documents\GitHub\Hangman
 * Created Date: Saturday April 20th 2019 8:23:49 pm
 * Author: ConorHK
 * -----
 * Description:
 */

#include "game_logic.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void initializeWord(){
    int difficulty, increment = 0;
    string wordlist[10];
    ifstream file;

    invalidInput:
    cout << "Please select a difficulty:" << endl << endl;
    cout << "1: Easy" << endl;
    cout << "2: Medium" << endl;
    cout << "3: Hard" << endl << endl;
    cout << "Enter choice:";
    cin >> difficulty;

    switch(difficulty){
        case 1:
                file.open("easy.txt");
                if(file.is_open()){
                    for(size_t i = 0; i < 10; i++){
                        file >> wordlist[i];
                    }
                }
                break;
        case 2:
                file.open("medium.txt");
                if(file.is_open()){
                    for(size_t i = 0; i < 10; i++){
                        file >> wordlist[i];
                    }
                }
                break;
        case 3:
                file.open("hard.txt");
                if(file.is_open()){
                    for(size_t i = 0; i < 10; i++){
                        file >> wordlist[i];
                    }
                }
                break;
        default:
                cout << "ERROR: Invalid input" << endl << endl;
                goto invalidInput;

    }
}