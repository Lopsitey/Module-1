#include "main.h"
#include <iostream>
#include <sstream>
using namespace std;
uint16_t convertStringToUint16(const string& str) 
{//converts the string to a usable integer
    stringstream ss(str);
    uint16_t value;

    if (ss >> value) 
    {//if the input string is successfully converted into a uint16_t
        if (value > 100)
        {//if the input string is invalid don't even try to convert it
            exception ex;
            throw ex;
        }
        return value;
    }
    else 
    {
        exception ex;
        throw ex;//throws an error that can be caught and dealt with
    }
}
int main(int argc, char* argv[])
{
    //The project is currently set up with a function to produce random numbers between
    //intervals that you specify. Modify the current solution to provide the functionality
    //requested by the document that outlines the challenges.
    
    //Here is an example just showing how you use the random(min, max) function:
    //cout << "Here is a random number between 1 and 10: " << random(1, 10) << endl;
    //cout << "And here is one between -3 and -5: " << random(-3, -5) << endl;

    int numberToGuess = random(0, 100);
    string guess = "";
    uint16_t difference = 0;
    int guesses = 0;
    bool won = false;
    bool validInput = false;

    cout << "Psst! The correct answer is: " << numberToGuess << endl << endl;
    while (!won) 
    {
        validInput = false;
        while (!validInput)
        {
            try 
            {
                cout << "What is your guess? (0-100)" << endl;
                cin >> guess;
                difference = abs(convertStringToUint16(guess) - numberToGuess);//abs() ensures the difference is always positive
            }
            catch (exception error)//if an excpetion is thrown, which my function will if anything is amiss
            {
                cerr << "Invalid input retry!" << endl;
                validInput = false;
                continue;
            }
            validInput = true;
        }
        ++guesses;
        if (difference >= 50)
        {
            cout << "freezing" << endl;
        }
        else if (difference >= 35 && difference < 50)
        {
            cout << "colder" << endl;
        }
        else if (difference >= 25 && difference < 35)
        {
            cout << "cold" << endl;
        }
        else if (difference >= 15 && difference < 25)
        {
            cout << "warm" << endl;
        }
        else if (difference >= 10 && difference < 15)
        {
            cout << "warmer" << endl;
        }
        else if (difference >= 5 && difference < 10)
        {
            cout << "hot" << endl;
        }
        else if (difference >= 3 && difference < 5)
        {
            cout << "hotter" << endl;
        }
        else if (difference >= 1 && difference <= 2)
        {
            cout << "boiling" << endl;
        }
        else if (difference == 0)
        {
            cout << "the guess is correct" << endl;
            cout << "It took you: " << guesses << " guesses!" << endl;
            won = true;
        }
    }
    return 0;
}