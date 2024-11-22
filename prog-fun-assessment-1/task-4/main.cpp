#include <iostream>
#include <string>
#include <vector>
#define clr() system("cls")
using namespace std;
int main(int argc, char* argv[])
{
    //Insert your code to complete challenge 4
    bool validInput = false;
    string reply = "";
    const string hyphen = "-";//because the encoding is meesed up I have to use this variable
    int i = 0;

    while (true) 
    {
        ++i;
        if (i == 3)
        {
            i -= 3;
            while (!validInput)
            {
                cout << "Do you want to clear the console? (y/n)" << endl;
                cin >> reply;
                if (reply != "y" && reply != "n")
                {
                    validInput = false;
                }
                else if (reply == "y")
                {
                    clr();
                    validInput = true;
                }
            }
        }
        validInput = false;
        while (!validInput)
        {    
            cout << "\nInput some text: ";
            getline(cin, reply);//essentially the same as cin >> reply;
            cout << endl;//except it allows us to check if the string inputted is empty
            if (reply.empty())//if there is no input
            {
                cerr << "Error: empty input!" << endl;
                validInput = false;
            }
            else 
            {
                // Process the input
                string boxLine = "";

                for (int i = 0; i < reply.size(); ++i)
                {   
                    boxLine += "+=" + hyphen + "=" + hyphen + "=";//saves the vector as a string for later output
                }
                cout << boxLine << "+\n" << "|";
                for (int i = 0; i < reply.size(); ++i) 
                {
                    cout << "  " << reply[i] << "  |";
                }
                cout << endl << boxLine << "+" << endl;
                validInput = true;
            }
        }
    }
    return 0;
}
/*
int main() {
    string reply;
    bool validInput = false;

    while (!validInput) {
        cout << "Input some text: ";
        getline(cin, reply);

        if (reply.empty()) {
            cerr << "Error: empty input!" << endl;
        } else {
            validInput = true;

            // Find the length of the longest word
            int maxLength = 0;
            for (char c : reply) {
                if (c != ' ') {
                    maxLength++;
                } else {
                    if (maxLength > 0) {
                        maxLength = max(maxLength, 3); // Account for "+=" and "="
                        maxLength = 0;
                    }
                }
            }
            maxLength = max(maxLength, 3); // Handle the last word

            // Create the box lines
            string boxLine = "";
            for (int i = 0; i < maxLength + 2; ++i) {
                boxLine += "+=";
            }
            boxLine += "+";

            // Print the box and text
            cout << boxLine << endl;
            cout << "| ";
            for (char c : reply) {
                cout << c << " | ";
            }
            cout << endl << boxLine << endl;
        }
    }

    return 0;
}
*/