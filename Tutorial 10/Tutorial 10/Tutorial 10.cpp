#include <iostream>
using namespace std;
int CountPunctuation(string str)//fixed by adding a parameter str and changing the return type to int
{
    int counter = 0;//initialized the int with zero
    for (int i = 0; i <= str.size(); ++i) // changed i + i to ++i
    {
        if (str[i] == '.' || str[i] == '!' || str[i] == '?' || str[i] == ',')//added more conditions and ensured each condition checked against the array
        {
            ++counter;//tiydied up counter += 1 to ++counter
        }
    }
    return counter;
}
void PrintArray(int* arr, int size)//you could change the int* arr to an int arr[] to pass in the actual array as oppose to a pointer to it
{
    for (int i = 0; i < size; ++i) //changed to ++i
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    std::cout << CountPunctuation("Hello, how are you?") << endl;
    int numbers[] = { 3,4,5 };
    PrintArray(numbers, sizeof(numbers)/sizeof(numbers[0]));//changed from sizeof(numbers) because that would just be the the size of the entie array in bytes
    //so we divide it by the size of one element because if an array with 3 elements is 4 bytes each that would return 12 bytes
    //Divide that by the size of one element (4) and you get 3 - the array length
    char someString[] = "this is an example";
    char* strPtr = someString;

    strPtr += 11;//chops of the "this is an " section
    ++*strPtr;//changed from *(strPtr)++ for simplicity
    //changes "example" to "fxample"

    strPtr -= 5;//adds "s an " back on to the start of the phrase now the e has been changed to an f
    *(someString + 1) = *someString;//the someString pointer has had a 't' added to the second value of the original someString
    *(someString + 2) = strPtr[2];//the someString pointer has had an 'a' added to the third value of the original someString
    *someString = *(someString + 3);//uses the 's' in what was "this" to change the first value in the array to an s
    //these pointers are essentially just as good as the original value except you can do more with it like moving through a string bitwise, etc...
    //whenever the pointer is changed so is the original value -  I think

    strPtr += 5;//now just holds "fxample" again
    someString[3] = someString[4] = *strPtr;

    *(strPtr - 6) = *(strPtr - 5);
    strPtr -= 4;
    *(--strPtr) = 0;
    cout << someString << endl;
    return 0;
}
