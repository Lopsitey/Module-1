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

class InvalidInputException : public runtime_error //inherits from the main error class
{
public:
    explicit InvalidInputException(const string& message) : runtime_error(message) {}//explicit is used on the constuctor because string may get implicitly converted to TypeMismatchException
};

uint16_t convertStringToUint16(const string& str) 
{
    stringstream ss(str);//uses a string stream because it can be converted uniquely
    uint16_t value;//uint16_t because we don't need a massive uint64_t and we don't want it to be negative either

    if (ss >> value) {//if the input string is successfully converted into a uint16_t
        return value;
    }
    else {
        throw InvalidInputException("Invalid input string: " + str);//throw a custom error from the custom error class
    }
}

int main(int argc, char* argv[])
{
    //Insert your code to complete challenge 2
    string realName = "";
    string userName = "";
    string clanTag = "";
    uint16_t expPoints;
    uint16_t level = 0;
    string temp = "";

    bool validInput = false;

    cout << "Input your first name: ";
    cin >> realName;
    cout << endl << "Input your username: ";
    cin >> userName;
    cout << endl << "Input your clan tag: ";
    cin >> clanTag;
    while (!validInput)//while the input is invalid
    {
        try 
        {
            cout << endl << "Input your experience points: ";
            cin >> temp;
            expPoints = convertStringToUint16(temp);//converts the stream (string) that was read to a uint and checks if it's valid
        }
        catch (const InvalidInputException& e) 
        {//for catching this error specifically
            cerr << "Error: " << e.what() << endl;//.what retrieves the error from the class
            validInput = false;
            continue;
        }
        catch (exception error)//for any other errors
        {
            cerr << "Error: " << error.what() << endl;//errror.what gets the error from the class as a string to output
            validInput = false;
            continue;//goes back to the next loop iteration and misses the validInput = true line, which would only run if the input was accurate
        }
        validInput = true;
    }
    level = expPoints / 100;

    cout << endl << "Your first name is " << realName << " and your in" << '-' << "game name is " << '[' << clanTag << ']' << userName << ". You have " << expPoints << " experience points." << endl;
    cout << endl << "Your current level is " << level << "." << endl;
    cout << "You need " << 100 - (expPoints % 100) << " points to reach the next level, which is " << level + 1 << "." << endl;
    return 0;
}