#include <iostream>
#include <type_traits>
#include <stdexcept>
#include <sstream>
using namespace std;

class InvalidInputException : public runtime_error
{
public:
    explicit InvalidInputException(const string& message) : runtime_error(message) {}//explicit is used so strings aren't implicitly converted to the class type
};

float parseString(const string& str) {//can only be an int or float
    stringstream ss(str);
    float type1;
    bool isNegative = false;

    // Check for a leading negative sign
    if (str[0] == '-') 
    {
        isNegative = true;
        ss.ignore(1); // Skip the negative sign
    }

    if (ss >> type1) 
    {//if the input string is successfully converted into an int
        return isNegative ? -type1 : type1;
    }
    else 
    {
        throw InvalidInputException("Invalid number: " + str);//throw a custom error from the custom error class
    }
}
int main(int argc, char* argv[])
{
    //Insert your code to complete challenge 3
    string reply = "";
    char reply1 = ' ';
    float number = 0;

    bool validInput = false;
    
    while (!validInput)
    {
        try
        {
            cout << "Input a number to perform calculations on: ";
            cin >> reply;
            cout << endl;
            number = parseString(reply);//converts the stream (string) that was read to an int or float and checks if it's valid
        }
        catch (const InvalidInputException& e) {
            cerr << "Error: " << e.what() << endl;//.what retrieves the error from the class
            validInput = false;
            continue;
        }
        catch (exception error)//for any other errors
        {
            cerr << "Error: " << error.what() << endl;
            validInput = false;
            continue;
        }
        validInput = true;
    }

    validInput = false;
    while (!validInput) 
    {
        cout << "Select a calculation to be performed on the number: \nNegation (1)\nAbsolute Value (2)\nSquaring (3)\nCubing (4)\nSquare Root (5)\nFlooring (7)\nRounding (8)\nCeiling (9)" << endl;
        cout << "Please enter a number from 1-9" << endl;
        cin >> reply1;
        switch (reply1) 
        {
        case '1':
            validInput = true;
            cout << "Negation: " << -number << endl;
            break;
        case '2':
            validInput = true;
            cout << "Absolute Value: " << abs(number) << endl;
            break;

        default:
            cout << "Invalid choice, retry" << endl;
            validInput = false;
        }
    }
    return 0;
}