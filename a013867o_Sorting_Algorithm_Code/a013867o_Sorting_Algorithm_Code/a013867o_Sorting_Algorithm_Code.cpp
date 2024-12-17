#include <iostream>
int main()
{
    int arrayToBeSorted[10] = { 10, 15, 12, 12, 25, 16, 20, 14, 28, 17 };
    int temp = 0;
    int arraySize = (sizeof(arrayToBeSorted) / sizeof(arrayToBeSorted[0]));//unneeded but more dynamic if the program is expanded
    bool swaps = false;

    while (!swaps)//if no swaps have been made end the program because the array is sorted
    {
        for (int i = 0; i < arraySize; ++i)
        {
            if (arrayToBeSorted[i] > arrayToBeSorted[i + 1] && i < arraySize - 1)//if the right number is smaller than the left number and we aren't at the end of the array
            {
                swaps = true;//a swap has been made so the program is safe to continue
                temp = arrayToBeSorted[i];//value 1 is stored
                arrayToBeSorted[i] = arrayToBeSorted[i + 1];//value 1 = value 2
                arrayToBeSorted[i + 1] = temp;//value 2 = value 1
            }
            for (int x = 0; x < arraySize; ++x)
            {
                std::cout << arrayToBeSorted[x] << " ";
            }
            std::cout << std::endl;
        }
        swaps = swaps == true ? false : true;//if swaps have been made then continue the program - otherwise end it
    }
}