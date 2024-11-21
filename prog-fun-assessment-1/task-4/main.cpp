#include <iostream>
#include <string>
#define clr() system("cls")
using namespace std;
int main(int argc, char* argv[])
{
    //Insert your code to complete challenge 4
    bool validInput = false;
    string reply = "";
    int i = 0;

    while (true) 
    {
        i += i = 3 ? -3 : 1;//resets i at 3
        if (i == 3)
        {
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
            else {
                // Process the input
                cout << "You entered: " << reply << endl;
                validInput = true;
            }
        }
    }
    return 0;
}