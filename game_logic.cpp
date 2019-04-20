/*
 * File: c:\Users\Conor\Documents\GitHub\Hangman\game_logic.cpp
 * Project: c:\Users\Conor\Documents\GitHub\Hangman
 * Created Date: Saturday April 20th 2019 8:23:49 pm
 * Author: ConorHK
 * -----
 * Description:
 */

#include "game_logic.h"
#include "board.h"
#include <string>
#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

#define EASY 1
#define MEDIUM 2
#define HARD 3

string wordlist[10];

int initializeWord(){
    int difficulty, increment = 0;
    ifstream file;

    invalidInput:
    cout << "Please select a difficulty:" << endl << endl;
    cout << "1: Easy" << endl;
    cout << "2: Medium" << endl;
    cout << "3: Hard" << endl << endl;
    cout << "Enter choice: ";
    cin >> difficulty;

    switch(difficulty){
        case EASY:
                file.open("easy.txt");
                if(file.is_open()){
                    for(size_t i = 0; i < 10; i++){
                        file >> wordlist[i];
                    }
                }
                return EASY;
                break;
        case MEDIUM:
                file.open("medium.txt");
                if(file.is_open()){
                    for(size_t i = 0; i < 10; i++){
                        file >> wordlist[i];
                    }
                }
                return MEDIUM;
                break;
        case HARD:
                file.open("hard.txt");
                if(file.is_open()){
                    for(size_t i = 0; i < 10; i++){
                        file >> wordlist[i];
                    }
                }
                return HARD;
                break;
        default:
                cout << "ERROR: Invalid input" << endl << endl;
                goto invalidInput;

    }
}

int wordGuess(int difficulty, string randomWord){
    char spaces[14];
    char guess;
    int mistakes = 0, correct = 0;
    bool win = false, lose = false;
    string word = randomWord;
    size_t found;

    printBoard(0);
    cout << endl;

    switch(difficulty){
        case EASY:
                for(size_t i = 0; i < 5; i++){
                    spaces[i] = '_';
                }

                while(!win || !lose){
                    for(size_t i = 0; i < 5; i++){
                        cout << " " << spaces[i];
                    }
                    cout << endl << endl << endl;
                    cout << "Enter a letter: ";
                    cin >> guess;
                    found = word.find(guess);
                    if(found != string::npos){
                        spaces[found] = guess;
                        correct ++;
                    }
                    else{
                        mistakes++;
                        if(mistakes == 1){
                            cout << "Wrong! " << mistakes << " mistake." << endl;
                        }
                        else{
                            cout << "Wrong! " << mistakes << " mistakes." << endl;
                        }
                        printBoard(mistakes);
                        if(mistakes == 6){
                            cout << endl << "He died." << endl;
                            lose = true;
                        }
                    }
                    if(correct == 5){
                        cout << endl << "***********" << endl;
                        cout << "* WINNER !*" << endl;
                        cout << "***********" << endl;
                        win = true;
                    }

                }
                
    }
}

string randomWordPick(){
    srand(time(NULL));
    int random = rand() % 10;
    return wordlist[random];
}