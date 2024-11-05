#include <iostream>
#include <windows.h>
#include <cstdlib>
#define sleep(x) Sleep(x*1000)//a sleep function macro with a parameter that takes an integer for seconds to delay the program by
#define clr() system("cls")
#define el endl
using namespace std;
int main()
{
    string reply = "";

    cout << "Wow, you're finally awake!" << el;
    sleep(1);
    cout << "." << el;
    sleep(1.5);
    cout << ".." << el;
    sleep(1.8);
    cout << "..." << el;
    sleep(2.18);
    clr();
    cout << "Adventurer, is that really you?" << el;
    sleep(0.5);
    cout << "(y/n)" << el;
    cin >> reply;
    if (reply == "y") 
    {
        clr();
        cout << "Good, I was hoping I could get someone to clear up this mess for me." << el;
        sleep(5);
        clr();
        cout << "You see, this dungeon has been in my family for generations." << el;
        cout << "Back in the day, when I was just a little whippersnapper our family ruled this land like kings." << el;
        sleep(10);
        clr();
        cout << "We became so wealthy we needed a dungeon to store all of our gold..." << el;
        sleep(5);
        clr();
        cout << "However, in recent times the dungeon has become infested with these terrible creatures." << el;
        cout << "Come to think of it, this may have happened due to those toxic potion barrels we dumped down there a few years ago..." << el;
        sleep(10);
        clr();
        cout << "So waddya say, adventurer, think you're up to the task to help me clear these pesky creatures out?" << el;
        sleep(0.5);
        cout << "(y/n)" << el;
        cin >> reply;
        if (reply == "y")
        {
            clr();
            cout << "Brilliant, since I'm feeling extra generous today, as payment you can keep anything you find!" << el;
            sleep(5);
            //
        }
    }
    else 
    {
        clr();
        cout << "Don't lie to me adventurer..." << el;
        sleep(3);
        cout << "My powers are beyond your comprehension!" << el;
        sleep(3);
        clr();
        cout << "Haha, gotcha, I actually know it's you because of your iconic lower back tattoo." << el;
        sleep(5);
        clr();
        cout << "I'm glad you're here, I was hoping I could get someone to clear up this mess for me." << el;
        sleep(5);
        clr();
        cout << "You see, this dungeon has been in my family for generations." << el;
        cout << "Back in the day, when I was just a little whippersnapper our family ruled this land like kings." << el;
        sleep(10);
        clr();
        cout << "We became so wealthy we needed a dungeon to store all of our gold..." << el;
        sleep(5);
        clr();
        cout << "However, in recent times the dungeon has become infested with these terrible creatures." << el;
        cout << "Come to think of it, this may have happened due to those toxic potion barrels we dumped down there a few years ago..." << el;
        sleep(10);
        clr();
        cout << "So waddya say, adventurer, think you're up to the task to help me clear these pesky creatures out?" << el;
        sleep(0.5);
        cout << "(y/n)" << el;
        cin >> reply;
        if (reply == "y")
        {
            clr();
            cout << "Brilliant, since I'm feeling extra generous today, as payment you can keep anything you find!" << el;
            sleep(5);
            //
        }
    }
    sleep(1);
}
