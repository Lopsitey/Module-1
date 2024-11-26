#include <iostream>

//no namespaces or using statements are needed because the code is so simple

int main(int argc, char* argv[])
{
    //Insert your code to complete challenge 1
    std::string asciiArt[14] = {"                    |                  ","                   /|\\                 ","                  / | \\ a boat         ","                 /  |  \\               ","               / -- | -- \\             ","              /     |     \\            ","             / -----|----- \\           ","       |----\\       |       /----|     ","         \\- - ------------- - -/       ","          \\- -- - - - - - -- -/        ","   /\\  /\\  /\\  /\\  / \\  /\\  /\\  /\\  /\\ ","  /  \\/  \\/  \\/  \\/   \\/  \\/  \\/  \\/  \\"};
    for (std::string& line : asciiArt)//iterates through the array using a foreach loop
    {
        std::cout << line << std::endl;//outputted line-by-line by accessing the array elements via reference
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