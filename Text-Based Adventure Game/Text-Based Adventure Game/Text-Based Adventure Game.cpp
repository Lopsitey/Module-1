#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <windows.h>
#include "Text-Based Adventure Game.h"
#define sleep(x) Sleep(x*1000)//a sleep function macro with a parameter that takes an integer for seconds to delay the program by
#define clr() system("cls")
#define el endl
using namespace std;

string GetKeys(vector<string>& x, int& i, map<string, string>& inventory)//a function that adds the keys of the inventory map to a vector
{
    bool started = false;
    int j = 0;
    string output = "";
    for (const auto& pair : inventory)
    {
        if (j != i && !started) 
        {
            ++j;
            continue;
        }
        x.push_back(pair.first); ++i; 
        started = true;
    }
    for (const auto& key : x) {
        output += " " + key;
    }
    return output;
}
vector<string> SplitString(vector<string>& keys, int& spot, map<string, string>& inventory) {
    string s = GetKeys(keys, spot, inventory);
    vector<string> output;//output vector
    int position = 0;
    while (position < s.size()) {//while the position is within the length of the string
        position = s.find(" ");//the position of the delimiter
        output.push_back(s.substr(0, position));//extracts from the beginning to the found position (excluding the space) and adds it to the output vector
        s.erase(0, position + 1); //1 is the length of the delimiter, " ". .erase removes it and all of the string before it
    }
    return output;
}

int main()
{
    string reply = "";
    bool validInput = true;
    int health = 20;
    map<string, string> inventory = { { "TRCH","torch"}, {"SWRD", "sword",}, {"BRRS","berries"} };//starting inventory - items the old man has given you
    vector<string> inventoryKeys = {};
    int inventorySpot = 0;

    cout << "Wow, you're finally awake!" << el;
    sleep(1);
    cout << "." << el;
    sleep(1.5);
    cout << ".." << el;
    sleep(1.8);
    cout << "..." << el;
    sleep(2.18);
    while (validInput) 
    {
        clr();
        cout << "Adventurer, is that really you?" << el;
        sleep(0.5);
        cout << "(y/n)" << el;
        cin >> reply;
        validInput = reply != "y" && reply != "n" ? true : false;//if the input is valid then the validInput variable will be false
    }//doing this will break the loop and continue the program
    if (reply == "y") 
    {
        clr();
        cout << "Good, I was hoping I could get someone to clear up this mess for me." << el;
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
    }
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
    validInput = true;
    while (validInput) 
    {
        clr();
        cout << "So waddya say, adventurer, think you're up to the task to help me clear these pesky creatures out?" << el;
        sleep(0.5);
        cout << "(y/n)" << el;
        cin >> reply;
        validInput = reply != "y" && reply != "n" ? true : false;
    }
    if (reply == "y")
    {
        clr();
        cout << "Brilliant, since I'm feeling extra generous today, as payment you can keep anything you find!" << el;
        sleep(5);
    }
    else 
    {
        clr();
        cout << "Well then, I think you should just leave!" << el;
        return 0;
    }
    clr();
    cout << "You gradually enter the dungeon feeling colder the further you go..." << el;
    sleep(5);
    cout << "Fumbling for the old man's torch you manage to strike it alight with your trusty flint." << el;
    sleep(5);
    cout << "Light hasn't touched this place in a long time." << el;
    sleep(3.5);
    validInput = true;
    while (validInput) 
    {
        clr();//cout << "You feel a slightly uneasy - the air is dry and you can hear each breath echo off the walls." << el;
        cout << "You meet a fork in the dungeon, do you go left or right?" << el;
        sleep(0.5);
        cout << "(l/r)" << el;
        cin >> reply;
        validInput = reply != "l" && reply != "r" ? true : false;
    }
    if (reply == "l") 
    {
        clr();
        cout << "Is that a creature in the darkness?" << el;
        sleep(3);
        cout << "As you get closer it appears to be a large black slime." << el;
        sleep(3);
        validInput = true;
        while (validInput)
        {
            clr();
            cout << "Do you want to attack it or attempt to run past?" << el;
            sleep(0.5);
            cout << "(atk/run)" << el;
            cin >> reply;
            validInput = reply != "atk" && reply != "run" ? true : false;
        }
        if (reply == "atk") 
        {
            validInput = true;
            while (validInput) 
            {
                clr();
                cout << "You have the items in your inventory: " << GetKeys(inventoryKeys, inventorySpot, inventory) << el;
                sleep(0.5);
                cout << "Which do you choose to use?" << el;
                cin >> reply;
                validInput = reply != SplitString(GetKeys(inventoryKeys, inventorySpot, inventory))[0] ? true : false;
            }
        }
        else 
        {
            clr();
            cout << "You attempt to run past but the slime splashes you with sticky black acid as you do so." << el;
            cout << "Health -3" << el;
            cout << "Your Health is now: " << health - 3 << el;
            sleep(10);
        }
    }
    else 
    {
        validInput = true;
        while (validInput)
        {
            clr();
            cout << "There seems to be a large fountain in the room's center." << el;
            cout << "Do you drink from it?" << el;
            sleep(0.5);
            cout << "(y/n)" << el;
            cin >> reply;
            validInput = reply != "y" && reply != "n" ? true : false;
        }
        if (reply == "y") 
        {
            clr();
            cout << "The fountain snaps cracks and pops. It does not go down easily but you feel strangely rejuvenated afterwards." << el;
            cout << "Health +5" << el;
            cout << "Your Health is now: " << health + 5 << el;
            sleep(10);
        }
        else
        {
            clr();
            cout << "You walk past the fountain. As you leave the room you give it one last look, pondering what may have been..." << el;
            sleep(5);
        }
    }
    clr();
    cout << "There seems to be a shape in the distance." << el;

}