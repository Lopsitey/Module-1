#include <iostream>
#include <string>
#define clr() system("cls")

using std::endl;
using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::streamsize;
using std::numeric_limits;

int main(int argc, char* argv[])
{
    //Insert your code to complete challenge 4
    bool validInput = false;
    string reply = "";
    int i = 0;

    while (true) 
    {
        if (i == 3)
        {
            i -= 3;
            validInput = false;
            while (!validInput)
            {
                cout << "Do you want to clear the console? (y/n)" << endl;
                cin >> reply;
                if (reply != "y" && reply != "n")//ensures that the user is always responding correctly - if not then the loop will iterate and they will be requested to respond again
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
        ++i;//iterates on the same line
        validInput = false;
        while (!validInput)//only runs if your not clearing the console because otherwise you would have a blank output
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
                string boxLine = "";

                for (int i = 0; i < reply.size(); ++i)
                {   
                    boxLine += "+=-=-=";//saves the vector as a string for later output
                }
                cout << boxLine << "+\n" << "|";//top line of the box
                for (int i = 0; i < reply.size(); ++i) 
                {
                    cout << "  " << reply[i] << "  |";//middle row
                }
                cout << endl << boxLine << "+" << endl;//bottom line of the box
                validInput = true;
            }
        }
    }
    return 0;
}
