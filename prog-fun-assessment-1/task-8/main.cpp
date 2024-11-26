#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
#define clr() system("cls")

using std::endl;
using std::cin;
using std::cout;
using std::cerr;
using std::exception;
using std::string;
using std::stringstream;
using std::vector;

uint16_t convertStringToUint16(const string& str)
{//converts the string to a usable integer
    stringstream ss(str);
    uint16_t value;

    if (ss >> value)//attempts to convert the input to the type specified
    {
        return value;
    }
    else//if it can't then the type is invalid
    {
        exception ex;
        throw ex;//throws an error that can be caught and dealt with - 1 based input to 0 based input
    }
}

void initializeInventory(vector<string>& inven, uint16_t& size)//I made this a function because this loop was used in two different parts of the program
{
    for (int i = 0; i < size; ++i)
    {
        inven.push_back("Empty");//iterates through the vector, initializing it with "Empty" values
    }
}
uint16_t main(uint16_t argc, char* argv[])
{
    //Insert your code to complete challenge 8
    string reply = "";

    while (reply != "exit")//outer loop for a restart
    {
        clr();//for when it gets reset, so does everything in the console - this means it stays clean and tidy
        reply = "";

        vector<string> inventory = {};
        vector<string> items = { "Empty","Shield","Potion","Gloves" };//the items the user can add into their inventory

        uint16_t inventorySize = 0;
        //useful for re-initializing the inventory after the clear() function has been used because using means the entire vector gets completely reset

        bool validInput = false;
        while (!validInput)
        {
            cout << "What size inventory do you want?" << endl;
            cin >> reply;
            inventorySize = convertStringToUint16(reply);
            if (inventorySize < 1 || inventorySize > 16)//ensures the user input is within the correct range
            {
                cerr << "Error: Inventory size must be between 1 and 16 slots!" << endl;
                validInput = false;
                continue;
            }
            else
            {
                validInput = true;
            }
        }

        initializeInventory(inventory, inventorySize);

        cout << "Inventory initialized to " << reply << " slots." << endl;
        cout << "Type \"help\" for a list of all commands." << endl;
        while (reply != "exit")
        {//iterates until the user decides not too
            validInput = false;
            while (!validInput)
            {
                getline(cin, reply);//gets the most recent line of user input from the console
                if (reply.substr(0, 2) != "- " && !reply.empty())//checks the command is is formatted correctly and isn't empty
                {
                    cerr << "Error: Command did not start with a \"- \" retry!" << endl;
                    validInput = false;
                    continue;
                }
                else
                {
                    validInput = true;
                    reply.erase(0, 2);//erases the "- " part of the command
                }
            }
            if (reply == "help")
            {
                cout << "view <index>: Prints details of the item at the specified index.\nshow_all: Shows all inventory slots and their details.\nset <index> <itemid>: Sets the slot at the specified index to the given item.\nsearch_item <str>";
                cout << ": Searches the item list for items with the given name.\nitems: Shows all available items.\nexit: Exits the tool.\nrestart: Restarts the session.\nhelp: Shows this list of commands.\nclear: Clears the inventory." << endl;
            }
            if (reply == "restart")
            {
                break;//returns to the outer loop and begins again
            }
            if (reply.substr(0, 4) == "view")//checks the first part of the command
            {
                uint16_t inventorySlot = convertStringToUint16(reply.substr(5, reply.length()));//gets the second half of the command and converts it to a uint16
                cout << "Inventory slot: " << inventory[inventorySlot] << endl;//outputs the requested inventory slot
            }
            if (reply.substr(0, 8) == "show_all")
            {//a foreach using references
                int i = -1;//so it's zero-based
                for (string& element : inventory)//a foreach which iterates through the vector and outputs each element to the console 
                {
                    cout << "Slot " << ++i << ": " << element << endl;//changes the value of i in-line
                }

            }
            if (reply.substr(0, 3) == "set")
            {
                reply.erase(reply.find(" "), 1);//erases the first space so the second can be found
                uint16_t testing = reply.find(" ");
                uint16_t inventorySlot = convertStringToUint16(reply.substr(3, reply.find(" ")));//gets the first number input by using the next space as a stopping point
                uint16_t itemID = convertStringToUint16(reply.substr(reply.find(" "), reply.length()));//converts the last section of the string to an integer - from the space to the end of the string
                inventory[inventorySlot] = items[itemID];//sets the element in the inventory to the element in the items vector
                cout << "Inventory slot " << inventorySlot << " details:" << endl;
                cout << "Name: " << inventory[inventorySlot] << endl;
            }
            if (reply == "items")
            {
                int i = -1;//so it's 0-based
                for (string& item : items)//iterates through the items vector and outputs each one in turn
                {//a foreach which passes each vector element as a reference
                    cout << ++i << ": " << item << endl;//iterates i in-line
                }
            }
            if (reply.substr(0, 11) == "search_item")
            {
                cout << "Search results:" << endl;

                string itemToFind = reply.substr(12, reply.length());
                string lowercase = "";
                string uppercase = "";
                //these are for searching both cases

                for (int i = 0; i < itemToFind.length(); ++i)//creates the uppercase and lowercase versions of the input one char at a time
                {
                    uppercase += toupper(itemToFind[i]);//initializes the variables for comparison in the if statement below
                    lowercase += tolower(itemToFind[i]);
                }
                for (int i = 0; i < items.size(); ++i)
                {
                    if (items[i].find(uppercase) != string::npos || items[i].find(lowercase) != string::npos)//if an item is found when comparing both cases
                    {//npos is what string.find returns when the item you're searching for isn't found
                        cout << "Item index " << i << ": " << items[i] << endl;
                    }
                }
            }
            if (reply == "clear")
            {
                inventory.clear();
                cout << "Cleared inventory" << endl;
                initializeInventory(inventory, inventorySize);//re-initializes it after clearing
            }
        }
    }
    cout << "Exiting." << endl;//once both while loops are broken then you exit the program
    return 0;
}