#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    //Insert your code to complete challenge 1
    string ASCIIart[14] = {"                    |                  ","                   /|\\                 ","                  / | \\ a boat         ","                 /  |  \\               ","               / __ | __ \\             ","              /     |     \\            ","             / _____|_____ \\           ","       |____\\       |       /____|     ","         \\_ _ _____________ _ _/       ","          \\_ __ _ _ _ _ _ __ _/        ","   /\\  /\\  /\\  /\\  / \\  /\\  /\\  /\\  /\\ ","  /  \\/  \\/  \\/  \\/   \\/  \\/  \\/  \\/  \\"};
    for (int i = 0; i < sizeof(ASCIIart)/sizeof(ASCIIart[0]); ++i)
    {
        cout << ASCIIart[i] << endl;
    }
    /*
                    |
                   /|\                 
                  / | \ a boat         
                 /  |  \               
               / −− | −− \             
              /     |     \            
             / −−−−−|−−−−− \           
       |−−−−\       |       /−−−−|     
         \− − −−−−−−−−−−−−− − −/       
          \− −− − − − − − −− −/        
   /\  /\  /\  /\  / \  /\  /\  /\  /\ 
  /  \/  \/  \/  \/   \/  \/  \/  \/  \
  */
    return 0;
}