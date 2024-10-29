#include <iostream>
#include <windows.h>
#include <cstdlib>
#define sleep(x) Sleep(x*1000)//a sleep function macro with a parameter that takes an integer for seconds to delay the program by
#define clr() system("cls")
using namespace std;
int main()
{
    cout << "Wow, you're finally awake!" << endl;
    sleep(1);
    cout << "." << endl;
    sleep(1.5);
    cout << ".." << endl;
    sleep(1.8);
    cout << "..." << endl;
    sleep(2.18);
    clr();
    cout << "Adventurer, is that really you?" << endl;
    sleep(0.5);
    cout << "(y/n)" << endl;
    string x = "";
    cin >> x;
    sleep(1);
}
