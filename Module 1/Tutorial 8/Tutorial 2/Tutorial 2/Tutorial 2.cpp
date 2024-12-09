
#include <iostream>

using namespace std;
int main()
{
    float grade = 0.0f;
    cout << "Input grade: ";
    cin >> grade;
    string passed;// = grade < 40 ? "Fail" : grade >= 40 && grade <= 50 ? "3rd" : grade > 50 && grade <= 60 ? "2:2" : grade > 60 && grade <= 70 ? "2:1" : "1st";
    //the same calculator as below but in an unreadable ternary if format
    if (grade < 40)//grade calculator
    {
        passed = "Fail";
    }
    else if (grade <= 50)
    {
        passed = "3rd";
    }
    else if (grade <= 60)
    {
        passed = "2:2";
    }
    else if (grade <= 70)
    {
        passed = "2:1";
    }
    else 
    {
        passed = "1st";
    }
    cout << "Grade: " << passed << "\n";

    string name;
    cout << "Input your name: ";
    cin >> name;
    string nameBob = name == "bob" || name == "Bob" ? "Yes" : "No";//checks if the name isn't bob
    cout << "\n" << "Is your name bob?" << "\n" << nameBob << "\n";// outputs result of check
    cout << ("bob" < "car") << "\n";//experiment with a comparison between strings, I think this uses the asci value or something
    cout << (name != "bob" || name != "Bob") << "\n";// practicing using the != operator

    int playerAmmo = 0;
    const int maxAmmo = 10;
    bool noAmmo = playerAmmo == 0;
    
    int inputNum = 0;
    cout << "Input a number: ";
    cin >> inputNum;
    cout << (inputNum >= 70 || inputNum <= 100) << "\n";

    string username = "bob";
    string password = "abc123";
    string tempUser = "";
    string tempPass = "";
    bool allowedAccess = false;

    cout << "Please Input Your Username: ";
    cin >> tempUser;
    cout << "\n";
    cout << "Please Input Your Password: ";
    cin >> tempPass;
    cout << "\n";

    if (tempUser == username && tempPass == password)
    {
        allowedAccess = true;
    }
    if (allowedAccess) 
    {
        cout << "You are allowed access!";
    }
    else
    {
        cout << "You aren't allowed access!";
    }
}
