/*
 * File: c:\Users\Conor\Documents\GitHub\Hangman\main.cpp
 * Project: c:\Users\Conor\Documents\GitHub\Hangman
 * Created Date: Saturday April 20th 2019 8:20:46 pm
 * Author: ConorHK
 * -----
 * Description: main file that calls functions to run game.
 */

#include "board.h"
#include "game_logic.h"
#include <string>
#include <iostream>
using namespace std;

int main(void)
{

    //declaring variables to store return of functions in order to pass to next function.
    int difficulty;
    string word;

    difficulty = initializeWord(); //stores whether user has picked easy, medium, or hard.
    word = randomWordPick();       //stores the word to be guessed.

    cout << "word: " << word << endl;
    //function that plays game.
    wordGuess(difficulty, word);
}