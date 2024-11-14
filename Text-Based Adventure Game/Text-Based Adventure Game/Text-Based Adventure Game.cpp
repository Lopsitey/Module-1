#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <windows.h>
#include <ctime>
#include<time.h>
#include "Text-Based Adventure Game.h"
#define sleep(x) Sleep(x*1000)//a sleep function macro with a parameter that takes an integer for seconds to delay the program by
#define clr() system("cls")
#define el endl
#define GetInventoryValues() GetInventory(inventoryKeys, inventoryValues, wholeInventory, inventoryKeySpot, inventoryValueSpot, wholeInventorySpot, inventory, values)
#define GetInventoryKeys() GetInventory(inventoryKeys, inventoryValues, wholeInventory, inventoryKeySpot, inventoryValueSpot, wholeInventorySpot, inventory, keys)
#define GetInventoryWhole() GetInventory(inventoryKeys, inventoryValues, wholeInventory, inventoryKeySpot, inventoryValueSpot, wholeInventorySpot, inventory, both)
using namespace std;

vector<string> SplitString(string s) {
    vector<string> output;//output vector
    int position = 0;
    while (s.size() > 0) {//while the string hasn't been deleted yet
        position = s.find(" ");//the position of the delimiter
        output.push_back(s.substr(0, position));//extracts from the beginning to the found position (excluding the space) and adds it to the output vector
        s.erase(0, position + 1); //1 is the length of the delimiter, " ". .erase removes it and all of the string before it
    }
    return output;
}
string GetInventory(vector<string>& keysVect, vector<string>& valuesVect, vector<string>& wholeInventory, int& i, int& k, int&m, vector<string>& inventory, const int& outputMethod)//a function that adds the keys of the inventory map to a vector
{
    bool started = false;
    int j = 0;
    string output = "";
    vector<string> temp = {};
    string item = "";//stores an element of the vector when split the "keys" or "values"
    for (const auto& pair : inventory)
    {
        if ((outputMethod == 0 && j != i || outputMethod == 1 && j != k || outputMethod == 2 && j != m) && !started)//basically saying if i'm trying to use keys then iterate through the inventory until it reaches the saved spot
        {//the or checks if we're using values - if so then then j will also be iterated but using a different variable to compare with instead
            ++j;
            continue;
        }
        if (outputMethod == 0)//selects the first item in the vector "pair" the "keys"
        {
            item = SplitString(pair)[0];
            keysVect.push_back(item); ++i;
        }
        else if (outputMethod == 1)//selects the second item in the vector "pair" the "values"
        {
            item = SplitString(pair)[1];
            valuesVect.push_back(item); ++k;
        }
        else 
        {
            wholeInventory.push_back(pair); ++m;
        }
        started = true;
    }
    temp = outputMethod == 0 ? keysVect : outputMethod == 1 ? valuesVect : wholeInventory;//changes the vector used if the output is going to be keys or values
    for (const auto& element : temp) {
        output += element + " ";//has to be in this order so the string ends with a space which allows the split string function to work
    }
    return output;
}
class Sword
{
    public:
        int damage = 0;
    
        Sword() 
        {
            static bool seeded = false;//ensures that the random number is only seeded once to maintain randomness
            if (!seeded) {
                srand(time(0));
                seeded = true;
            }

            float critChance = rand() % 100 + 1;//generates a random crit chance for this instance
            float hitChance = rand() % 100 + 1;

            if (hitChance <= 80)//80% chance
            {
                damage = 6;

                if (critChance <= 10)//10% chance
                {
                    damage *= 2;
                }
            }
            //total opportunity for a max of 12 damage if you get a crit
    }
};
class Torch 
{
    public:
        int damage = 0;

        Torch()//parameters here would be used to input into the entire class but we don't want any inputs, just default values so it's left blank
        {
            static bool seeded = false;
            if (!seeded) {
                srand(time(0));
                seeded = true;
            }

            float fireChance = rand() % 100 + 1;//generates a random fire chance for this instance
            float critChance = rand() % 100 + 1;
            float hitChance = rand() % 100 + 1;

            if (hitChance <= 80)//80% chance
            {
                damage = 1;

                if (fireChance <= 60)//60% chance
                {
                    damage += 3;
                }
                if (critChance <= 10)//10% chance
                {
                    damage *= 2;
                }
            }
            //total opportunity for a max of 8 damage if you get a crit and fire damage
    }
};
class Berries 
{
    public:
        int healing = 5;//healing would need to be accessed but quantity can be sorted out internally
        int quantity = 3;//for setting the main berriesQuantity variable after a berry has been consumed
        Berries(bool consumed, int quantity) 
        {
            if (consumed && quantity > 0)
            {
                quantity -= 1;//this would always have to be the same instance which gets used unless another punnet is found
            }
            else 
            {
                healing = quantity == 0 ? 0 : 5;//Only provides healing if there are berries to be healed with
            }//Double checks that quantity is zero just in case false is accidentally input
            this->quantity = quantity;//saves the quantity from the constructor back to the class variable
        }
};
class BlackSlime 
{
    private:
        int health = 20;//takes 2 or 4 sword hits
    public:
        int damage = 0;
        bool isAlive() 
        {
            if (health > 0)
            {
                return true;
            }
            else
            {
                sleep(0.5);
                cout << "The slime died!" << el;
                return false;
            }
        }//alive by default but dies on 0 health

        BlackSlime(int health) 
        {
            this->health = health;
            static bool seeded = false;
            if (!seeded) {
                srand(time(0));
                seeded = true;
            }

            float critChance = rand() % 100 + 1;
            float hitChance = rand() % 100 + 1;

            if (hitChance <= 40)//40% chance
            {
                damage = 5;//can kill you in 4 consecutive hits

                if (critChance <= 5)//10% chance (could kill you in 2 hits)
                {
                    damage *= 2;
                }
            }
            //total opportunity for a max of 8 damage if you get a crit and fire damage
        }
};
class Player
{
    private:
        int health = 20;///health would always be vicariously accessed through the variable defined in main
        //this variable would be updated whenever the player instance is re-initialised
    public:
        const int maxHealth = 20;
        bool isAlive() 
        {
            if (health > 0) 
            {
                return true;
            }
            else 
            {
                sleep(0.5);
                cout << "You died!" << el;
                return false;
            }
        }//alive by default but dies on 0 health
        Player(int health)
        {
            //if (health <= 0) 
            //{
                //alive = false;//directly assigning the class variable a value so I don't need to use this->alive = alive since it is implicit in this scenario
            //}
            this->health = health;
        }
};
int main()
{
    string reply = "";
    bool validInput = true;
    int health = 20;//rather than directly accessing the health variable in the player class this can be input as a parameter which makes the class more secure
    int enemyHealth = 0;//same concept but for enemies
    vector<string> inventory = { "torch TRCH ", "sword SWRD ", "berries BRRS " };//starting inventory - items the old man has given you
    vector<string> inventoryKeys = {};//the inventory has a space after each set of items so the split string works properly
    vector<string> inventoryValues = {};
    vector<string> wholeInventory = {};
    int inventoryKeySpot = 0;
    int inventoryValueSpot = 0;
    int wholeInventorySpot = 0;
    const int keys = 0;
    const int values = 1;
    const int both = 2;
    int berriesQuantity = 3;

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
            enemyHealth = 20;
            BlackSlime blackSlime(enemyHealth);
            Player player(health);
            while (blackSlime.isAlive() && player.isAlive())//while you and the slime are alive
            {
                validInput = true;
                while (validInput)
                {
                    clr();
                    cout << "You have the items in your inventory: " << GetInventoryWhole() << el;
                    sleep(0.5);
                    cout << "Which do you want to use?" << el;
                    cin >> reply;

                    if (reply == "TRCH")
                    {
                        Torch torch;//re-initialises the class on very torch call so the number is always random
                        clr();
                        cout << "You attempt to attack the slime with your fiery torch!" << el;
                        cout << "The slime had " << enemyHealth << " health but now has ";//doesn't have an el; because it continues below
                        enemyHealth -= torch.damage;//has to be on a separate line,
                        cout << enemyHealth << " health!" << el;
                    }
                    else if (reply == "SWRD")
                    {
                        Sword sword;
                        clr();
                        cout << "You attempt to attack the slime with your steely sword!" << el;
                        cout << "The slime had " << enemyHealth << " health but now has ";
                        enemyHealth -= sword.damage;
                        cout << enemyHealth << " health!" << el;
                    }
                    else if (reply == "BRRS")
                    {
                        Berries berries(true, berriesQuantity);
                        berriesQuantity = berries.quantity;//stores the quantity for future use in other instances
                        clr();
                        cout << "You to heal for " << berries.healing << " health!" << el;
                        cout << "Your health was " << health << " and is now ";
                        health += health < 20 ? berries.healing : 0;//ensures that you aren't healing over your max health
                        cout << health << "!" << el;
                    }
                    else
                    {
                        validInput = true;
                        continue;
                    }
                    validInput = false;
                }
                sleep(8);
                clr();
                cout << "The slime attempts to attack you with it's wet tendrils!" << el;
                cout << "You had " << health << " health but now have ";
                health -= blackSlime.damage;
                cout << health << " health!" << el;
                sleep(8);
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
/*
    For checking if the input is in the inventory and valid:
    for (string item : SplitString(GetInventoryValues())) {
        if (reply == item)
        {
            validInput = false;
            break;//stops the loop if the user inputted an available item
        }
        else
        {
            validInput = true;//continues the loop so the user will be asked again
        }
    }
*/
