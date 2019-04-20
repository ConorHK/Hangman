/*
 * File: c:\Users\Conor\Documents\GitHub\Hangman\game_logic.cpp
 * Project: c:\Users\Conor\Documents\GitHub\Hangman
 * Created Date: Saturday April 20th 2019 8:23:49 pm
 * Author: ConorHK
 * -----
 * Description: file that contains all the logic necessary to run game.
 */

//including headers.
#include "game_logic.h"
#include "board.h"
#include <string>
#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

//defining difficulties for readability.
#define EASY 1
#define MEDIUM 2
#define HARD 3

//declaring global variables.
string wordlist[10];
char wrongList[6];
int increment = 0;

//function that reads in wordlist from txt file.
int initializeWord()
{
    int difficulty, increment = 0;
    ifstream file;

//asks user for difficulty and stores choice.
invalidInput: //goto point for incorrect input.
    cout << "Please select a difficulty:" << endl
         << endl;
    cout << "1: Easy" << endl;
    cout << "2: Medium" << endl;
    cout << "3: Hard" << endl
         << endl;
    cout << "Enter choice: ";
    cin >> difficulty;

    //switch statement that collects different wordlist depending on difficulty chosen.
    switch (difficulty)
    {

    case EASY:
        file.open("easy.txt");
        if (file.is_open())
        {
            for (size_t i = 0; i < 10; i++)
            {
                file >> wordlist[i];
            }
        }
        return EASY; //returns difficulty to main.cpp
        break;

    case MEDIUM:
        file.open("medium.txt");
        if (file.is_open())
        {
            for (size_t i = 0; i < 10; i++)
            {
                file >> wordlist[i];
            }
        }
        return MEDIUM;
        break;

    case HARD:
        file.open("hard.txt");
        if (file.is_open())
        {
            for (size_t i = 0; i < 10; i++)
            {
                file >> wordlist[i];
            }
        }
        return HARD;
        break;

    //error check.
    default:
        cout << "ERROR: Invalid input" << endl
             << endl;
        goto invalidInput;
    }
}

//function that lets user guess word and decides if user has won or lost.
void wordGuess(int difficulty, string randomWord)
{

    //declaring necessary variables.
    char spaces[14];                                    //array storing empty spots or correctly guessed characters.
    char guess;                                         //variable storing user's guess.
    int mistakes = 0, guessed = 0;         //integers storing how many mistakes user has made + how many they guessed correctly.
    bool win = false, lose = false; // flags for winning and losing.
    string word = randomWord;                           // collecting word to be guessed.
    size_t found;                                       //variable that stores the position of the correctly guessed character.

    //calls printBoard function.
    printBoard(0);
    cout << endl;

    //switch statement that runs code corresponding to which difficulty chosen.
    switch (difficulty)
    {

    case EASY:

        //adds empty character '_' to spaces array for every length in the word.
        for (size_t i = 0; i < 5; i++)
        {
            spaces[i] = '_';
        }

        //loop which runs while the user hasn't won or lost.
        while (!win && !lose)
        {

            //prints out the spaces array.
            for (size_t i = 0; i < 5; i++)
            {
                cout << " " << spaces[i];
            }
            cout << endl
                 << endl
                 << endl;

            //asks for user's guess and stores answer.
            cout << "Enter a letter: ";
            cin >> guess;

            //assigns the position of the correct character in the string to found.
            found = word.find(guess);

            //if it has been correctly found then:
            if (found != string::npos)
            {
                //loop while correct characters are found: this enables words to have duplicate letters e.g hodor.
                while (found != string::npos)
                {
                    
                    //setting empty spaces to correct character.
                    spaces[found] = guess;

                    //search area is set to the position after the position just found.
                    size_t foundSearch = found + 1;

                    //next occurrence of guess is found.
                    found = word.find(guess, foundSearch);
                }
            }

            //mistake case:
            else
            {

                //increments mistake counter.
                mistakes++;

                //prints out how many mistakes have been made.
                if (mistakes == 1)
                {
                    cout << "Wrong! " << mistakes << " mistake." << endl;
                }
                else
                {
                    cout << "Wrong! " << mistakes << " mistakes." << endl;
                }

                //prints board with updated mistakes parameter, so that next part of hangman is printed.
                printBoard(mistakes);

                //passes incorrect guess to invalidChoices function.
                invalidChoices(guess);

                //if the man is hanged, game is ended.
                if (mistakes == 6)
                {
                    cout << endl
                         << "He died." << endl;
                    cout << "The word was " << word << "." << endl;
                    lose = true;
                }
            }

            //loop to see if all empty spots in the spaces array have been correctly guessed.
            for (size_t i = 0; i < 5; i++)
            {
                if (spaces[i] != '_')
                {
                    guessed++;
                }
            }
            
            //if so, the player is declared the winner.
            if (guessed == 5)
            {
                cout << endl
                     << "***********" << endl;
                cout << "* WINNER !*" << endl;
                cout << "***********" << endl;
                win = true;
            }
            
            //otherwise,"guessed" is reset to 0 in preparation for next loop. 
            else
            {
                guessed = 0;
            }
        }
        break;

    /*for comments for following cases, see above comments.*/
    case MEDIUM:
        for (size_t i = 0; i < 8; i++)
        {
            spaces[i] = '_';
        }

        while (!win && !lose)
        {
            for (size_t i = 0; i < 8; i++)
            {
                cout << " " << spaces[i];
            }
            cout << endl
                 << endl
                 << endl;
            cout << "Enter a letter: ";
            cin >> guess;
            found = word.find(guess);
            if (found != string::npos)
            {
                while (found != string::npos)
                {
                    spaces[found] = guess;

                    size_t foundSearch = found + 1;

                    found = word.find(guess, foundSearch);
                }
            }
            else
            {
                mistakes++;
                if (mistakes == 1)
                {
                    cout << "Wrong! " << mistakes << " mistake." << endl;
                }
                else
                {
                    cout << "Wrong! " << mistakes << " mistakes." << endl;
                }
                printBoard(mistakes);
                invalidChoices(guess);
                if (mistakes == 6)
                {
                    cout << endl
                         << "He died." << endl;
                    cout << "The word was " << word << "." << endl;
                    lose = true;
                }
            }
            for (size_t i = 0; i < 8; i++)
            {
                if (spaces[i] != '_')
                {
                    guessed++;
                }
            }
            if (guessed == 8)
            {
                cout << endl
                     << "***********" << endl;
                cout << "* WINNER !*" << endl;
                cout << "***********" << endl;
                win = true;
            }
            else
            {
                guessed = 0;
            }
        }
        break;

    case HARD:
        for (size_t i = 0; i < 14; i++)
        {
            spaces[i] = '_';
        }

        while (!win && !lose)
        {
            for (size_t i = 0; i < 14; i++)
            {
                cout << " " << spaces[i];
            }
            cout << endl
                 << endl
                 << endl;
            cout << "Enter a letter: ";
            cin >> guess;
            found = word.find(guess);
            if (found != string::npos)
            {
                while (found != string::npos)
                {
                    spaces[found] = guess;

                    size_t foundSearch = found + 1;

                    found = word.find(guess, foundSearch);
                }
            }
            else
            {
                mistakes++;
                if (mistakes == 1)
                {
                    cout << "Wrong! " << mistakes << " mistake." << endl;
                }
                else
                {
                    cout << "Wrong! " << mistakes << " mistakes." << endl;
                }
                printBoard(mistakes);
                invalidChoices(guess);
                if (mistakes == 6)
                {
                    cout << endl
                         << "He died." << endl;
                    cout << "The word was " << word << "." << endl;
                    lose = true;
                }
            }
            for (size_t i = 0; i < 14; i++)
            {
                if (spaces[i] != '_')
                {
                    guessed++;
                }
            }
            if (guessed == 14)
            {
                cout << endl
                     << "The word was " << word << "." << endl;
                cout << endl
                     << "***********" << endl;
                cout << "* WINNER !*" << endl;
                cout << "***********" << endl;
                win = true;
            }
            else
            {
                guessed = 0;
            }
        }
        break;
    default:
        cout << "ERROR" << endl;
        break;
    }
}

//function that picks a random word from the read-in wordlist, and returns it to main.cpp.
string randomWordPick()
{
    srand(time(NULL));
    int random = rand() % 10;
    return wordlist[random];
}

//function that stores and prints out the user's incorrect guesses.
void invalidChoices(char wrong)
{
    wrongList[increment] = wrong;
    increment++;

    cout << "Invalid choices: ";
    for (int i = 0; i <= increment; i++)
    {
        cout << wrongList[i] << " ";
    }
    cout << endl;
}