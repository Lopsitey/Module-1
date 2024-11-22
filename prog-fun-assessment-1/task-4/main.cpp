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
            validInput = false;
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
                else if (reply == "n") 
                {
                    validInput = true;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');//ignores the input required to reply to the "do you want to clear the console" question
            }
        }
        validInput = false;
        while (!validInput)// only runs if your not clearing the console becuase otherwise you would have a blank output
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
