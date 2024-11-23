#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
    //Insert your code to complete challenge 5
    string reply = "";
    cout << "Please input a sentence or something random: ";
    getline(cin, reply);
    string upperCase = reply;
    string lowerCase = reply;
    string sentenceCase = "";
    string alternateCase = "";
    string noWhiteSpace = "";
    int spacesAmount = 0;

    for (int i = 0; i < reply.length(); i++)
    {
        if (reply[i] >= 'a' && reply[i] <= 'z')//ensures the value is in the alphabet and lowercase
        {
            upperCase[i] = toupper(reply[i]);//deducts 32 from the ascii value which converts it into the uppercase section
        }
        else if (reply[i] >= 'A' && reply[i] <= 'Z') 
        {
            lowerCase[i] = tolower(reply[i]);
        }
        if (reply[i] != ' ')
        {
            noWhiteSpace += reply[i];//creating the no whitespace variable
        }
    }

    for (int i = 0; i < reply.length(); i++) 
    {
        if (i == 0)
        {
            sentenceCase = lowerCase;//sets it to all lowercase initially
            sentenceCase[i] = toupper(reply[i]);
        }
        else if (reply[i] == '!' || reply[i] == '?' || reply[i] == '.')
        {
            try
            {
                if (sentenceCase[i + 1] == ' ')//checks to see if it is a legitimate gap or just the end of the sentence
                {
                    sentenceCase[i + 2] = toupper(reply[i + 2]);
                }
            }
            catch (exception ex) {}//just in case the sentence ends with a space for some reason
        }
    }

    int k = -1;//so it's zero on the first iteration - for keeping track of the pattern
    for (int i = 0; i < noWhiteSpace.length(); i++)//used to accurately access the noWhiteSpace variable whilst accounting for spaces
    {
        ++k;
        if (reply[i + spacesAmount] == ' ')
        {
            alternateCase += ' ';
            ++spacesAmount;//puts the arrays on the same page by fixing the space discrepancy between the reply string and the noWhiteSpace string
        }

        if (noWhiteSpace[i] == '?' || noWhiteSpace[i] == '!' || noWhiteSpace[i] == '.' || noWhiteSpace[i] == ',')
        {
            alternateCase += noWhiteSpace[i];
            --k;//maintains the pattern by skipping any punctuation
        }
        else if (k % 2 == 0)
        {
            alternateCase += tolower(noWhiteSpace[i]);//makes every even character uppercase
        }//reply: "the cat sat on the mat"
        else//nowWhiteSpace: "thecatsatonthemat"
        {
            alternateCase += toupper(noWhiteSpace[i]);
        }
    }

    cout << "Uppercase        => " << upperCase << endl;
    cout << "Lowercase        => " << lowerCase << endl;
    cout << "Sentence casing  => " << sentenceCase << endl;
    cout << "Alternate casing => " << alternateCase << endl;
    return 0;
}