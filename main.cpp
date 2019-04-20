/*
 * File: c:\Users\Conor\Documents\GitHub\Hangman\main.cpp
 * Project: c:\Users\Conor\Documents\GitHub\Hangman
 * Created Date: Saturday April 20th 2019 8:20:46 pm
 * Author: ConorHK
 * -----
 * Description:
 */

#include "board.h"
#include "game_logic.h"
#include <string>
#include <iostream>
using namespace std;

int main(void){
    int difficulty;
    string word;
    difficulty = initializeWord();
    
    word = randomWordPick();
    cout << word << endl;
    wordGuess(difficulty, word);
}