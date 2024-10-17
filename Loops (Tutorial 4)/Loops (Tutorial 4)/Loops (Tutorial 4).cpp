
#include <iostream>

using namespace std;
int main()
{
    int number = 0;
    while (number < 1 || number > 1000000 || cin.fail())
    {
        cout << "Input a number to countdown from: ";
        cin >> number;
        cin.clear();//clears the buffer to prevent overflow upon error
        cin.ignore(1000, '\n');//ignores the input if there is an error
        cout << "\n";
    }
    while (number > 0)
    {
        //Show the number
        cout << "T-" << number << "\n";

        //Decrease the number by 1
        --number;
    }
    cout << "Blast Off!" << "\n\n\n";

    
    string check = "";
    while (check != "bob")
    {
        cout << "PLeAsE tYpE:\nbOb \njOkE \neXiT \n: ";
        cin >> check;
        cout << "\n";
        if (check == "joke")
        {
            cout << "There's a blind man walking past a fish market, right?" << "\n";
            cin >> check;
            cout << "And he turns around and says......\n\n\n\n\n\n\n\n\n hellllooo lovely ladies!" << "\n\n";
        }
        else if (check == "exit")
        {
            break;
        }
    }
    if (check == "bob")
    {
        cout << "Nice, writing bob properly!";
    }
    cout << "No more jokes for you!";
    
    for (int i = 0; i < 31; ++i) 
    {
        cout << i;
        cout << i * 6;
    }
    for (int x = 10; x<0;x--)
    {
        cout << x;
    }
}