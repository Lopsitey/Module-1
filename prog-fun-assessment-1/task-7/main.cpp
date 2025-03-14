#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using std::endl;
using std::cin;
using std::cout;
using std::cerr;
using std::exception;
using std::string;
using std::stringstream;
using std::vector;

uint16_t convertStringToUint16(const string& str)//takes a string reference as a parameter
{//converts the string to a usable integer
    stringstream ss(str);//a string stream which can be used to convert string to another type
    uint16_t value;//a uint 16 because I don't want it to be negative and it doesn't need to hold a large amount of data

    if (ss >> value)//if the conversion is successful
    {
        if (value < 1 || value > 10)//if the value is out of range
        {//if the input string is invalid don't even try to convert it
            exception ex;//initializes the exception class to the ex variable
            throw ex;//throws an error which is useful in a try - catch statement
        }
        return value - 1;//converts the value back to a number the vector can read
    }
    else//if the conversion is unsuccessful, throw an error
    {
        exception ex;
        throw ex;//throws an error that can be caught and dealt with - 1 based input to 0 based input
    }
}
struct Item 
{
    string name;
    string type;
    string characterRole;
    int price;
    int damage;
    bool selected;

    Item(const string& name, const string& type, const string& characterRole, const int& price, const int& damage, const bool& selected) : name(name), type(type), characterRole(characterRole), price(price), damage(damage), selected(selected)
    {//this is the parent item class which is used to construct all of the items in the Item vector seen below. All of the parameters are passed as references and are then initialized using an initializer list
        /*
        The equivalent to the initializer list used however, less efficient:
        this->name = name;
        this->type = type;
        this->price = price;
        this->damage = damage;
        */
    }
};

int main(int argc, char* argv[])
{
    //Insert your code to complete challenge 7
    string player1Name = "";
    string player2Name = "";
    string player3Name = "";

    bool startGame = false;//for when all three players have finally selected their items

    cout << "What is your name, player #1?" << endl;
    cin >> player1Name;
    cout << "What is your name, player #2?" << endl;
    cin >> player2Name;
    cout << "What is your name, player #3?" << endl;
    cin >> player3Name;
    
    while (!startGame)
    {
        string itemSelectionReply = "";
        string startGameReply = "";
        string tempName = "";

        uint16_t itemSelection = 0;//this is for storing the numeric value of the item the user has chosen. It is useful later for when the vector needs to be accessed
        uint16_t coins = 100;//saved as a uint 16 for the same as the prior reasons and beause it is getting the return from a function which only outputs uint16

        bool validInput = false;//this ensures the while loop keeps running until the user has inputted something I deem acceptable

        vector<Item> shopItems = {//a vector with the type Item - a class which its constructor is used to initialize every element in the vector
        {"Magic Scimitar", "Sword", "Rogue", 25, 55, false},
        {"Dusty Nunchucks", "Bat", "Monk", 14, 38, false},
        {"Golden Dagger", "Sword", "Rogue", 20, 45, false},
        {"Ogre's Club", "Bat", "Warrior", 60, 110, false},//powerful but expensive
        {"Polished Spear", "Spear", "Knight", 21, 60, false},//maybe I should add fire rate or dps to make this more balanced
        {"Cracked Spear", "Spear", "Knight", 12, 31, false},
        {"Elven Bow", "Bow", "Archer", 30, 73, false},
        {"Small Bow", "Bow", "Archer", 20, 50, false},//would fire fast
        {"Hardened Nunchucks", "Bat", "Monk", 24, 52, false},
        {"Branch Club", "Bat", "Warrior", 10, 28, false}//had to have a 10 coin item so the party wouldn't spend it all in 2 turns
        };

        //these are blank items the player is holding - they will be changed later, but are useful for the output at the end referring to the entire party and their items
        Item player1Item("", "", "", 0, 0, false);
        Item player2Item("", "", "", 0, 0, false);
        Item player3Item("", "", "", 0, 0, false);

            cout << "\nWelcome " << player1Name << ", " << player2Name << " and " << player3Name << " to the shop!" << endl;
            cout << "You currently have " << coins << " coins." << " You can buy the following items:" << endl;
            for (int i = 0; i < shopItems.size(); ++i)//iterates through the vector to output the items to the console using the vector's size and i to display the item numbers
            {
                cout << i + 1 << ". " << shopItems[i].name << " [" << shopItems[i].price << ", " << shopItems[i].damage << "]" << endl;
            }//i+1 is used here to make the shop items 1-based as opposed to being 0-based and beginning with 0. I think 1-based is more user-friendly and natural

            for (int i = 0; i < 3; ++i)
            {
                validInput = false;
                while (!validInput)//ensures the input is valid
                {
                    try
                    {
                        cout << "\nPlayer " << i + 1 << " please enter a weapon to buy: ";
                        cin >> itemSelectionReply;
                        cout << endl;
                        itemSelection = convertStringToUint16(itemSelectionReply);//converts the reply to a useable unsigned integer

                        if (shopItems[itemSelection].selected == true)//checks if the item has already been chosen
                        {
                            cerr << "Invalid selection, this item has already been chosen." << endl;//outputs an error message if the item has already been selected
                            validInput = false;
                            continue;
                        }
                        else
                        {
                            shopItems[itemSelection].selected = true;//stops the item from being selected again
                        }

                        if (coins < shopItems[itemSelection].price) {
                            cerr << "Insufficient funds to purchase this item." << endl;//ensures that the user can afford the item
                            validInput = false;
                            continue;//if not then the loop restarts and they are forced to re-select one
                        }
                        else
                        {
                            coins -= shopItems[itemSelection].price;//deducts the price from the party's total coins
                        }
                        
                        if (i == 0) 
                        {
                            tempName = player1Name;//saves me writing 3 separate lines for each player - can be dynamic instead
                            player1Item = shopItems[itemSelection];//saves the item for later output
                        }
                        else if (i == 1) 
                        {
                            tempName = player2Name;
                            player2Item = shopItems[itemSelection];
                        }
                        else 
                        {
                            tempName = player3Name;
                            player3Item = shopItems[itemSelection];
                        }
                        
                    }
                    catch (exception error)
                    {
                        cerr << "Invalid input retry!" << endl;
                        validInput = false;
                        continue;//skips the true statement below and re-loops if there is an error
                    }
                    validInput = true;//allows the user to continue if all is well
                }
                cout << tempName << " brought a " << shopItems[itemSelection].name << " for " << shopItems[itemSelection].price << " coins." << " The party now has " << coins << " coins." << endl;
            }
            validInput = false;
            while (!validInput) 
            {
                cout << "\nDo you want to start the game? (y/n)" << endl;
                cin >> startGameReply;
                if (startGameReply != "y" && startGameReply != "n")//ensures that they inputted y/
                {
                    cerr << "Invalid input, retry!" << endl;
                    validInput = false;
                    continue;
                }
                else if (startGameReply=="y")
                {
                    startGame = true;
                }
                else if (startGameReply=="n")
                {
                    startGame = false;
                }
                validInput = true;
            }

            if (startGame) 
            {//outputs the party's stats if the user has decided to start the game
                cout << "\nThe party: " << endl;
                cout << "Player 1 " << "(" << player1Name << ")," << " Role: " << player1Item.characterRole << ", Weapon: " << player1Item.name << ", Damage: " << player1Item.damage << endl;
                cout << "Player 2 " << "(" << player2Name << ")," << " Role: " << player2Item.characterRole << ", Weapon: " << player2Item.name << ", Damage: " << player2Item.damage << endl;
                cout << "Player 3 " << "(" << player3Name << ")," << " Role: " << player3Item.characterRole << ", Weapon: " << player3Item.name << ", Damage: " << player3Item.damage << endl;

                cout << "\nWelcome to the land of oo..." << endl;//the game starting - the intro
                //exit(0); - happens anywayS
            }
        }
        return 0;
}