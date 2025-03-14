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
#define GetInventoryValues() GetInventory(inventoryKeys, inventoryValues, wholeInventory, inventoryKeySpot, inventoryValueSpot, wholeInventorySpot, inventory, values)
#define GetInventoryKeys() GetInventory(inventoryKeys, inventoryValues, wholeInventory, inventoryKeySpot, inventoryValueSpot, wholeInventorySpot, inventory, keys)
#define GetInventoryWhole() GetInventory(inventoryKeys, inventoryValues, wholeInventory, inventoryKeySpot, inventoryValueSpot, wholeInventorySpot, inventory, both)

using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::vector;

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
string GetInventory(vector<string>& keysVect, vector<string>& valuesVect, vector<string>& wholeInventory, int& i, int& k, int& m, vector<string>& inventory, const int& outputMethod)//a function that adds the keys of the inventory map to a vector
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
class Player
{
public:
    int health = 20;//this variable would be updated whenever the player instance is re-initialised
    const int maxHealth = 20;
    bool isAlive()
    {
        if (health > 0)
        {
            return true;
        }
        else
        {
            clr();
            sleep(0.5);
            cout << "You died!" << endl;
            sleep(3);
            exit(0);//terminates the program
            return false;//never gets run, just for clarity
        }
    }//alive by default but dies on 0 health
    /*Player()
    {
        if (health <= 0)
        {
            alive = false;//directly assigning the class variable a value so I don't need to use this->alive = alive since it is implicit in this scenario
        }
        this->health = health;
    }*/
};
class BlackSlime
{
public:
    int health = 20;//takes 2 or 4 sword hits
    bool isAlive()
    {
        if (health > 0)
        {
            return true;
        }
        else
        {
            clr();
            sleep(0.5);
            cout << "The slime died!" << endl;
            sleep(3);
            return false;
        }
    }//alive by default but dies on 0 health

    int getDamage()
    {
        static bool seeded = false;
        if (!seeded) {
            srand(time(0));
            seeded = true;
        }

        float critChance = rand() % 100 + 1;
        float hitChance = rand() % 100 + 1;

        int damage = 0;//resets damage after prior alterations
        if (hitChance <= 40)//40% chance
        {
            damage = 5;//can kill you in 4 consecutive hits

            if (critChance <= 5)//5% chance (could kill you in 2 hits)
            {
                damage *= 2;
            }
        }
        return damage;//total opportunity for a max of 8 damage if you get a crit and normal damage
    }

    void attackPlayer(Player& player)
    {
        if (isAlive())//if the slime is alive it can attack
        {
            sleep(8);
            clr();
            cout << "The slime attempts to attack you with it's wet tendrils!" << endl;
            cout << "You had " << player.health << " health but now have ";
            player.health -= getDamage();//for the random damage to be recalculated I use a function which returns the damage
            cout << player.health << " health!" << endl;
            sleep(8);
        }
    }
};
class SmallCreature
{
public:
    int health = 12;//takes 2 sword hits
    bool isAlive()
    {
        if (health > 0)
        {
            return true;
        }
        else
        {
            clr();
            sleep(0.5);
            cout << "The creature died!" << endl;
            sleep(3);
            return false;
        }
    }//alive by default but dies on 0 health

    int getDamage()
    {
        static bool seeded = false;
        if (!seeded) {
            srand(time(0));
            seeded = true;
        }

        float critChance = rand() % 100 + 1;
        float hitChance = rand() % 100 + 1;

        int damage = 0;//resets damage after prior alterations
        if (hitChance <= 70)//70% chance
        {
            damage = 2;//can kill you in 4 consecutive hits

            if (critChance <= 8)//8% chance
            {
                damage *= 2;
            }
        }
        return damage;//total opportunity for a max of 4 damage if they get a crit and normal damage
    }

    void attackPlayer(Player& player)
    {
        if (isAlive())//if the slime is alive it can attack
        {
            sleep(8);
            clr();
            cout << "The creature attempts to attack you with it's slappy hands!" << endl;
            cout << "You had " << player.health << " health but now have ";
            player.health -= getDamage();//for the random damage to be recalculated I use a function which returns the damage
            cout << player.health << " health!" << endl;
            sleep(8);
        }
    }
};
class MonsterKing
{
public:
    int health = 50;//takes a lot of sword hits
    bool isAlive()
    {
        if (health > 0)
        {
            return true;
        }
        else
        {
            clr();
            sleep(0.5);
            cout << "The king is dead, congratulations!" << endl;
            cout << "No more monsters will be found in this place" << endl;
            sleep(6);
            return false;
        }
    }//alive by default but dies on 0 health

    int getDamage()
    {
        static bool seeded = false;
        if (!seeded) {
            srand(time(0));
            seeded = true;
        }

        float critChance = rand() % 100 + 1;
        float hitChance = rand() % 100 + 1;

        int damage = 0;//resets damage after prior alterations
        if (hitChance <= 40)//40% chance
        {
            damage = 7;//can kill you in 4 consecutive hits

            if (critChance <= 8)//8% chance
            {
                damage *= 2;
            }
        }
        return damage;//total opportunity for a max of 4 damage if they get a crit and normal damage
    }

    void attackPlayer(Player& player)
    {
        if (isAlive())//if the slime is alive it can attack
        {
            sleep(8);
            clr();
            cout << "The king attempts to attack you with giant hammer!" << endl;
            cout << "You had " << player.health << " health but now have ";
            player.health -= getDamage();//for the random damage to be recalculated I use a function which returns the damage
            cout << player.health << " health!" << endl;
            sleep(8);
        }
    }
};

class TridentAbility
{
public:
    int damage = 0;

    TridentAbility(int hp)
    {
        static bool seeded = false;//ensures that the random number is only seeded once to maintain randomness
        if (!seeded) {
            srand(time(0));
            seeded = true;
        }

        float bleedChance = rand() % 100 + 1;//generates a random crit chance for this instance
        float hitChance = rand() % 100 + 1;

        if (hitChance <= 33)//33% chance
        {
            damage = 8;
        }
        if (bleedChance <= 50)//50% chance
        {
            hp -= 2;
            cout << "You lost 2 health!" << endl;
        }
        //total opportunity for a max of 8 damage and a loss of 2 hp
    }
};

int main()
{
    string reply = "";
    bool validInput = true;
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

    cout << "Wow, you're finally awake!" << endl;
    sleep(1);
    cout << "." << endl;
    sleep(1.5);
    cout << ".." << endl;
    sleep(1.8);
    cout << "..." << endl;
    sleep(2.18);
    while (validInput)
    {
        clr();
        cout << "Adventurer, is that really you?" << endl;
        sleep(0.5);
        cout << "(y/n)" << endl;
        cin >> reply;
        validInput = reply != "y" && reply != "n" ? true : false;//if the input is valid then the validInput variable will be false
    }//doing this will break the loop and continue the program
    if (reply == "y")
    {
        clr();
        cout << "Good, I was hoping I could get someone to clear up this mess for me." << endl;
    }
    else
    {
        clr();
        cout << "Don't lie to me adventurer..." << endl;
        sleep(3);
        cout << "My powers are beyond your comprehension!" << endl;
        sleep(3);
        clr();
        cout << "Haha, gotcha, I actually know it's you because of your iconic lower back tattoo." << endl;
        sleep(5);
        clr();
        cout << "I'm glad you're here, I was hoping I could get someone to clear up this mess for me." << endl;
    }
    sleep(5);
    clr();
    cout << "You see, this dungeon has been in my family for generations." << endl;
    cout << "Back in the day, when I was just a little whippersnapper our family ruled this land like kings." << endl;
    sleep(10);
    clr();
    cout << "We became so wealthy we needed a dungeon to store all of our gold..." << endl;
    sleep(5);
    clr();
    cout << "However, in recent times the dungeon has become infested with these terrible creatures." << endl;
    cout << "Come to think of it, this may have happened due to those toxic potion barrels we dumped down there a few years ago..." << endl;
    sleep(10);
    validInput = true;
    while (validInput)
    {
        clr();
        cout << "So waddya say, adventurer, think you're up to the task to help me clear these pesky creatures out?" << endl;
        sleep(0.5);
        cout << "(y/n)" << endl;
        cin >> reply;
        validInput = reply != "y" && reply != "n" ? true : false;
    }
    if (reply == "y")
    {
        clr();
        cout << "Brilliant, since I'm feeling extra generous today, as payment you can keep anything you find!" << endl;
        sleep(5);
    }
    else
    {
        clr();
        cout << "Well then, I think you should just leave!" << endl;
        return 0;
    }
    clr();
    cout << "You gradually enter the dungeon feeling colder the further you go..." << endl;
    sleep(5);
    cout << "Fumbling for the old man's torch you manage to strike it alight with your trusty flint." << endl;
    sleep(5);
    cout << "Light hasn't touched this place in a long time." << endl;
    sleep(3.5);
    validInput = true;
    while (validInput)
    {
        clr();//cout << "You feel a slightly uneasy - the air is dry and you can hear each breath echo off the walls." << endl;
        cout << "You meet a fork in the dungeon, do you go left or right?" << endl;
        sleep(0.5);
        cout << "(l/r)" << endl;
        cin >> reply;
        validInput = reply != "l" && reply != "r" ? true : false;
    }
    if (reply == "l")
    {
        clr();
        cout << "Is that a creature in the darkness?" << endl;
        sleep(3);
        cout << "As you get closer it appears to be a large black slime." << endl;
        sleep(3);
        validInput = true;
        while (validInput)
        {
            clr();
            cout << "Do you want to attack it or attempt to run past?" << endl;
            sleep(0.5);
            cout << "(atk/run)" << endl;
            cin >> reply;
            validInput = reply != "atk" && reply != "run" ? true : false;
        }
        if (reply == "atk")
        {
            BlackSlime blackSlime;
            Player player;
            while (blackSlime.isAlive() && player.isAlive())//while you and the slime are alive
            {
                validInput = true;
                while (validInput)
                {
                    clr();
                    cout << "You have the items in your inventory: " << GetInventoryWhole() << endl;
                    sleep(0.5);
                    cout << "Which do you want to use?" << endl;
                    cin >> reply;

                    if (reply == "TRCH")
                    {
                        Torch torch;//re-initialises the class on very torch call so the number is always random
                        clr();
                        cout << "You attempt to attack the slime with your fiery torch!" << endl;
                        cout << "The slime had " << blackSlime.health << " health but now has ";//doesn't have anendl; because it continues below
                        blackSlime.health -= torch.damage;//has to be on a separate line,
                        cout << blackSlime.health << " health!" << endl;
                    }
                    else if (reply == "SWRD")
                    {
                        Sword sword;
                        clr();
                        cout << "You attempt to attack the slime with your steely sword!" << endl;
                        cout << "The slime had " << blackSlime.health << " health but now has ";
                        blackSlime.health -= sword.damage;
                        cout << blackSlime.health << " health!" << endl;
                    }
                    else if (reply == "BRRS")
                    {
                        Berries berries(true, berriesQuantity);
                        berriesQuantity = berries.quantity;//stores the quantity for future use in other instances
                        clr();
                        cout << "You heal for " << berries.healing << " health!" << endl;
                        cout << "Your health was " << player.health << " and is now ";
                        player.health += player.health < 20 ? berries.healing : 0;//ensures that you aren't healing over your max health
                        cout << player.health << "!" << endl;
                    }
                    else
                    {
                        validInput = true;
                        continue;
                    }
                    validInput = false;
                }
                blackSlime.attackPlayer(player);
            }
        }
        else
        {
            Player player;
            clr();
            cout << "You attempt to run past but the slime splashes you with sticky black acid as you do so." << endl;
            cout << "Your health was " << player.health;
            player.health -= 3;
            cout << " and is now: " << player.health << endl;
            sleep(10);
        }
    }
    else
    {
        validInput = true;
        while (validInput)
        {
            clr();
            cout << "There seems to be a large fountain in the room's center." << endl;
            cout << "Do you drink from it?" << endl;
            sleep(0.5);
            cout << "(y/n)" << endl;
            cin >> reply;
            validInput = reply != "y" && reply != "n" ? true : false;
        }
        if (reply == "y")
        {
            Player player;
            clr();
            cout << "The fountain snaps cracks and pops. It does not go down easily but you feel strangely rejuvenated afterwards." << endl;
            cout << "Health +5" << endl;
            cout << "Your Health is now: " << player.health + 5 << endl;
            sleep(10);
        }
        else
        {
            clr();
            cout << "You walk past the fountain. As you leave the room you give it one last look, pondering what may have been..." << endl;
            sleep(5);
        }
    }

    validInput = true;
    while (validInput)
    {
        clr();
        cout << "There seems to be a shape in the distance." << endl;
        sleep(0.5);
        cout << "Do you choose to head closer? (y/n)" << endl;
        cin >> reply;

        validInput = reply != "y" && reply != "n" ? true : false;
    }
    if (reply == "y")
    {
        clr();
        cout << "You gradually get closer to the object..." << endl;
        sleep(1);
        cout << "." << endl;
        sleep(1.5);
        cout << ".." << endl;
        sleep(2);
        cout << "..." << endl;
        sleep(2.2);

        validInput = true;
        while (validInput)
        {
            clr();
            cout << "The shape appears to be a magical glass door, you can see a hazy outline of a trident through it." << endl;
            cout << "Do you go through? (y/n)" << endl;
            cin >> reply;
            validInput = reply != "y" && reply != "n" ? true : false;
        }

        if (reply == "y")
        {
            clr();
            cout << "You enter your hand into the door..." << endl;
            sleep(2);
            cout << "And get scratched!" << endl;
            sleep(0.5);
            cout << "The power of water channels through you..." << endl;
            cout << "You have now gained the power of the trident!" << endl;
            cout << "33% chance to deal lots of damage\n however, you may lose some health..." << endl;
            sleep(0.5);
            cout << "50% chance to lose 2 hp per use!" << endl;
            inventory.push_back("trident TRDNT ");//adds the ability into the inventory
            sleep(10);
        }
        else
        {
            clr();
            cout << "You walk past the door. As you exit the corridor you the door seems to shine brighter, almost teasing you..." << endl;
            sleep(5);
        }
            
    }
    else
    {
        clr();
        cout << "I guess we'll never know what that MYSTERIOUS SHAPE was then..." << endl;
        sleep(3);
    }
    validInput = true;
    while (validInput)
    {
        clr();
        cout << "You seem to have come upon a crossroads.\nTo your left is a door which looks like a monsters mouth. There are spikes everywhere." << endl;
        cout << "To the right is a room with an old oak door. Vines are creeping out from underneath it." << endl;
        sleep(0.5);
        cout << "Which way do you want to go? (l/r)" << endl;
        cin >> reply;

        validInput = reply != "l" && reply != "r" ? true : false;
    }
    if (reply == "l") 
    {
        validInput = true;
        while (validInput)
        {
            clr();
            cout << "You immediately feel uneasy.\nThe air doesn't feel right and it sounds like there's life in here." << endl;
            cout << "Those sound like...?" << endl;
            sleep(1);
            cout << "Scurrying noises?" << endl;
            cout << "A small creature appears, do you choose to attack? (y/n)" << endl;
            sleep(0.5);
            cin >> reply;

            validInput = reply != "y" && reply != "n" ? true : false;
        }
        if (reply == "y")
        {
            SmallCreature smallCreature;
            Player player;
            while (smallCreature.isAlive() && player.isAlive())//while you and the creature are alive
            {
                validInput = true;
                while (validInput)
                {
                    clr();
                    cout << "You have the items in your inventory: " << GetInventoryWhole() << endl;
                    sleep(0.5);
                    cout << "Which do you want to use?" << endl;
                    cin >> reply;

                    if (reply == "TRCH")
                    {
                        Torch torch;//re-initialises the class on very torch call so the number is always random
                        clr();
                        cout << "You attempt to attack the creature with your fiery torch!" << endl;
                        cout << "The creature had " << smallCreature.health << " health but now has ";//doesn't have an endl; because it continues below
                        smallCreature.health -= torch.damage;//has to be on a separate line,
                        cout << smallCreature.health << " health!" << endl;
                    }
                    else if (reply == "SWRD")
                    {
                        Sword sword;
                        clr();
                        cout << "You attempt to attack the creature with your steely sword!" << endl;
                        cout << "The creature had " << smallCreature.health << " health but now has ";
                        smallCreature.health -= sword.damage;
                        cout << smallCreature.health << " health!" << endl;
                    }
                    else if (reply == "TRDNT")
                    {
                        TridentAbility trident(player.health);
                        clr();
                        cout << "You attempt to attack the creature with your trident power!" << endl;
                        cout << "The creature had " << smallCreature.health << " health but now has ";
                        smallCreature.health -= trident.damage;
                        cout << smallCreature.health << " health!" << endl;
                    }
                    else if (reply == "BRRS")
                    {
                        Berries berries(true, berriesQuantity);
                        berriesQuantity = berries.quantity;//stores the quantity for future use in other instances
                        clr();
                        cout << "You heal for " << berries.healing << " health!" << endl;
                        cout << "Your health was " << player.health << " and is now ";
                        player.health += player.health < 20 ? berries.healing : 0;//ensures that you aren't healing over your max health
                        cout << player.health << "!" << endl;
                    }
                    else
                    {
                        validInput = true;
                        continue;
                    }
                    validInput = false;
                }
                smallCreature.attackPlayer(player);
            }
        }
        else 
        {
            Player player;
            clr();
            cout << "You attempt to run past but the creature but it latches you with its small sharp claws." << endl;
            cout << "Your health was " << player.health;
            player.health -= 3;
            cout << " and is now: " << player.health << endl;
            sleep(10);
        }
    }
    else
    {
        validInput = true;
        while (validInput)
        {
            clr();
            cout << "The large oaken door opens slowly" << endl;
            cout << "You can hear the vines snap as the door pushes them out of the way" << endl;
            sleep(3);
            cout << "There is a large chest in the centre of the room." << endl;
            sleep(0.5);
            cout << "Do you choose to open it? (y/n)" << endl;
            cin >> reply;

            validInput = reply != "y" && reply != "n" ? true : false;
        }
        if (reply == "y")
        {
            validInput = true;
            while (validInput)
            {
                Player player;
                clr();
                cout << "Thousands of small creatures jump out of the chest and start crawling all over you!" << endl;
                cout << "You have the items in your inventory: " << GetInventoryWhole() << endl;
                sleep(0.5);
                cout << "Which do you want to use?" << endl;
                cin >> reply;

                if (reply == "TRCH")
                {
                    clr();
                    cout << "The ants all burned to a crisp." << endl;
                    cout << "You remain unhurt." << endl;
                    sleep(5);
                }
                else if (reply == "SWRD")
                {
                    clr();
                    cout << "You manage to slice though a few ants, pushing them back." << endl;
                    cout << "However, they were too many and some made off with a chunk of flesh!" << endl;
                    cout << "Your health was " << player.health;
                    player.health -= 3;
                    cout << " and is now: " << player.health << endl;
                    sleep(10);
                }
                else if (reply == "TRDNT")
                {
                    clr();
                    cout << "You manage to blow most of the ants away, pushing them back." << endl;
                    cout << "However, there were a few too many and some made off with a half of a pinkie finger!" << endl;
                    sleep(8);

                }
                else if (reply == "BRRS")
                {
                    Berries berries(true, berriesQuantity);
                    berriesQuantity = berries.quantity;//stores the quantity for future use in other instances
                    clr();
                    cout << "You heal for " << berries.healing << " health!" << endl;
                    cout << "Your health was " << player.health << " and is now ";
                    player.health += player.health < 20 ? berries.healing : 0;//ensures that you aren't healing over your max health
                    cout << player.health << "!" << endl;
                    cout << "Your healing intimidated the ants and they all ran away in fear of your boldness." << endl;
                }
                else
                {
                    validInput = true;
                    continue;
                }
                validInput = false;
            }
        }
        else
        {
            cout << "Clever adventurer!" << endl;
            cout << "Little did you know that chest was full to the brim with ants!" << endl;
        }
    }
    
    validInput = true;
    while (validInput)
    {
        cout << "It looks like the king of monsters may be in the next room" << endl;
        cout << "Do you want to attack him? (y/n)" << endl;
        cin >> reply;

        validInput = reply != "y" && reply != "n" ? true : false;
    }
    if (reply == "y")
    {
        MonsterKing monsterKing;
        Player player;
        while (monsterKing.isAlive() && player.isAlive())//while you and the creature are alive
        {
            validInput = true;
            while (validInput)
            {
                clr();
                cout << "You have the items in your inventory: " << GetInventoryWhole() << endl;
                sleep(0.5);
                cout << "Which do you want to use?" << endl;
                cin >> reply;

                if (reply == "TRCH")
                {
                    Torch torch;//re-initialises the class on very torch call so the number is always random
                    clr();
                    cout << "You attempt to attack the king with your fiery torch!" << endl;
                    cout << "The king had " << monsterKing.health << " health but now has ";//doesn't have an endl; because it continues below
                    monsterKing.health -= torch.damage;//has to be on a separate line,
                    cout << monsterKing.health << " health!" << endl;
                }
                else if (reply == "SWRD")
                {
                    Sword sword;
                    clr();
                    cout << "You attempt to attack the king with your steely sword!" << endl;
                    cout << "The king had " << monsterKing.health << " health but now has ";
                    monsterKing.health -= sword.damage;
                    cout << monsterKing.health << " health!" << endl;
                }
                else if (reply == "TRDNT")
                {
                    TridentAbility trident(player.health);
                    clr();
                    cout << "You attempt to attack the king with your trident power!" << endl;
                    cout << "The king had " << monsterKing.health << " health but now has ";
                    monsterKing.health -= trident.damage;
                    cout << monsterKing.health << " health!" << endl;
                }
                else if (reply == "BRRS")
                {
                    Berries berries(true, berriesQuantity);
                    berriesQuantity = berries.quantity;//stores the quantity for future use in other instances
                    clr();
                    cout << "You heal for " << berries.healing << " health!" << endl;
                    cout << "Your health was " << player.health << " and is now ";
                    player.health += player.health < 20 ? berries.healing : 0;//ensures that you aren't healing over your max health
                    cout << player.health << "!" << endl;
                }
                else
                {
                    validInput = true;
                    continue;
                }
                validInput = false;
            }
            monsterKing.attackPlayer(player);
        }
    }
    else 
    {
        cout << "Attempt to run away but the allure of the dungeon is too strong.\nYou never see the light of day again..." << endl;
    }//bad ending
}