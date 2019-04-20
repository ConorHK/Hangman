/*
 * File: c:\Users\Conor\Documents\GitHub\Hangman\game_logic.h
 * Project: c:\Users\Conor\Documents\GitHub\Hangman
 * Created Date: Saturday April 20th 2019 8:23:56 pm
 * Author: ConorHK
 * -----
 * Description: header file for game_logic.cpp file.
 */

#include <string>

//function prototypes.
int initializeWord();             //no inputs, difficulty outputted.
void wordGuess(int, std::string); //difficulty and word to be guessed inputted. No outputs.

std::string randomWordPick(); //no inputs, word to be guessed outputted.

void invalidChoices(char); //incorrect guessed inputted, no outputs.