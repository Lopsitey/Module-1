#include <iostream>
#include <type_traits>
#include <stdexcept>
#include <sstream>

using std::endl;
using std::cin;
using std::cout;
using std::cerr;
using std::exception;
using std::string;
using std::stringstream;
using std::runtime_error;

class InvalidInputException : public runtime_error
{
public:
    explicit InvalidInputException(const string& message) : runtime_error(message) {}//explicit is used so strings aren't implicitly converted to the class type
};

float parseString(const string& str) 
{
    stringstream ss(str);//converts the string to a float immediately
    float flt;
    bool isNegative = false;

    // Check for a leading negative sign
    if (str[0] == '-') 
    {
        isNegative = true;
        ss.ignore(1); // Skip the negative sign
    }

    if (ss >> flt) 
    {//if the input string is successfully converted into an int
        return isNegative ? -flt : flt;
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
            cerr << "Error: " << error.what() << endl;//.what gets the error from the class and outputs it as a string
            validInput = false;
            continue;//goes back to the start of the loop and skips the line below
        }
        validInput = true;
    }

    validInput = false;
    while (!validInput)//while the input is invalid
    {
        cout << "Select a calculation to be performed on the number: \nNegation (1)\nAbsolute Value (2)\nSquaring (3)\nCubing (4)\nSquare Root (5)\nFlooring (6)\nRounding (7)\nCeiling (8)" << endl;
        cout << "Please enter a number from 1-9" << endl;
        cin >> reply1;
        switch (reply1) 
        {
        case '1':
            validInput = true;
            cout << "Negation: " << -number << endl;//returns the opposite value
            break;
        case '2':
            validInput = true;
            cout << "Absolute Value: " << abs(number) << endl;
            break;
        case '3':
            validInput = true;
            cout << "Squared: " << powf(number,2) << endl;
            break;
        case '4':
            validInput = true;
            cout << "Cubed: " << powf(number, 3) << endl;
            break;
        case '5':
            validInput = true;
            if (number<0)
            {
                float temp = number * -1;
                temp = sqrtf(temp);
                number = -temp;
            }
            else
            {
                number = sqrt(number);
            }
            cout << "Square root: " << number << endl;
            break;
        case '6':
            validInput = true;
            cout << "Floored: " << floorf(number) << endl;
            break;
        case '7':
            validInput = true;
            cout << "Rounded: " << roundf(number) << endl;
            break;
        case '8':
            validInput = true;
            cout << "Ceiling: " << ceilf(number) << endl;//always returns the positive value f is for float input
            break;

        default:
            cout << "Invalid choice, retry" << endl;
            validInput = false;
        }
    }
    return 0;
}