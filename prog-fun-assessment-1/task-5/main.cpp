#include <iostream>
#include <algorithm>
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
    string sentenceCase = reply;
    string alternateCase = reply;
    string noWhiteSpace = "";
    bool hit = false;

    for (int i = 0; i < reply.length(); i++)
    {
        if (reply[i] >= 'a' && reply[i] <= 'z')//ensures the value is in the alphabet
        {
            upperCase[i] = toupper(reply[i]);//deducts 32 from the ascii value which converts it into the uppercase section
            lowerCase[i] = tolower(reply[i]);
        }
        if (i == 0)
        {
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
        if (reply[i] != ' ') 
        {
            noWhiteSpace += reply[i];//trying something new here
        }
    }

    int k = -1;//used to accurately access the noWhiteSpace variable whilst accounting for spaces
    for (int i = 0; i < reply.length(); i++)
    {
        ++k;
        if (reply[i] != ' ')//creating the no whitespace variable
        {
            if (i % 2 == 0)
            {
                noWhiteSpace[k] = tolower(reply[k]);//makes every even character uppercase
            }
            else
            {
                noWhiteSpace[k] = toupper(reply[k]);
            }
        }
        else
        {
            k -= 1;//takes 1 off the counter if a space is found
        }
        if (i == reply.length() - 1 && !hit)
        {
            hit = true;
            i = k;
        }
    }

    for (int i = 0; i < noWhiteSpace.length(); i++)
    {
        ++k;
        if (noWhiteSpace[i] >= 'a' && noWhiteSpace[i] <= 'z')
        {
            if (reply[i] == ' ')
            {
                alternateCase[i] = ' ';
                k -= 1;
            }
            else
            {
                alternateCase[i] = noWhiteSpace[k];
            }
        }
    }

    cout << "Uppercase        => " << upperCase << endl;
    cout << "Lowercase        => " << lowerCase << endl;
    cout << "Sentence casing  => " << sentenceCase << endl;
    cout << "Alternate casing => " << alternateCase << endl;
    return 0;
}