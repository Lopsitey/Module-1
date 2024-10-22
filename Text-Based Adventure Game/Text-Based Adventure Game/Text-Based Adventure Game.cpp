#include <iostream>
#include <windows.h>
#define sleep(x) Sleep(x*1000)//makes the sleep function better with a macro
using namespace std;
int main()
{
    cout << "Wow, you're finally awake!" << endl;
    sleep(1);
    cout << "Test" << endl;
}