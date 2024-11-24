#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
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
int main(int argc, char* argv[])
{
    //Insert your code to complete challenge 8
    string reply = "";

    while (reply != "exit")//outer loop for a restart
    {
        reply = "";

        vector<string> inventory = {};

        cout << "What size inventory do you want?" << endl;
        cin >> reply;
        for (int i = 0; i < convertStringToUint16(reply); ++i)
        {
            inventory.push_back("");
        }
        cout << "Inventory initialized to " << reply << " slots." << endl;
        cout << "Type \"help\" for a list of all commands." << endl;
        while (reply != "exit")
        {//iterates until the user decides not too
            reply = "";
            getline(cin, reply);
            if (reply == "help")
            {
                cout << "view <index>: Prints details of the item at the specified index.\nshow_all: Shows all inventory slots and their details.\nset <index> <itemid>: Sets the slot at the specified index to the given item.\nsearch_item <str>";
                cout << ": Searches the item list for items with the given name.\nitems: Shows all available items.\nexit: Exits the tool.\nrestart: Restarts the session.\nhelp: Shows this list of commands.\nclear: Clears the inventory." << endl;
            }
            if (reply == "restart")
            {
                break;
            }
            if (reply.substr(0, 4) == "view")
            {
                int inventorySlot = convertStringToUint16(reply.substr(5, reply.length()));//gets the second half of the command
                cout << "Inventory slot: " << inventory[inventorySlot] << endl;
            }
            if (reply.substr(0, 8) == "show_all")
            {
                reply = "";
                for (string element : inventory)
                {
                    reply += element;
                }
                cout << "Entire inventory: " << reply << endl;

            }
        }
    }
    return 0;
}