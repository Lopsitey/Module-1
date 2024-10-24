#include <iostream>
#define countArr(x) sizeof(x)/sizeof(x[0])
using namespace std;
/*
int globalArray[10];
int globalArray2[10];
void PrintArray(int* myArray, int size) 
{
    for (int z = 0; z < size; ++z) 
    {
        cout << myArray[z] << endl;
    }
}
*/
int main()
{
   /*
   int localArray[10];

    for (int i = 0; i < 10; ++i) 
    {
        globalArray[i] = 0;
        globalArray2[i] = 1;
    }

    globalArray[14] = 5;

    PrintArray(globalArray,50);//memory addresses after the array are shown
    */
    int fatArr[] = {-5,-10,-15};
    for (int i = 0; i < 3; ++i) 
    {
        cout << fatArr[i] << endl;
    }
    struct Person
    {
        string name = "";
        int age = 0;
    };
    Person playerArr[4] = {
        {"bob",10},{"john",5},{"steve",9},{"harry",19}
    };
    cout << playerArr[1].name << endl;
    float test[100] = {0};
    cout << test[82] << endl;
    bool arr[1] = { true };
    cout << arr[5] << endl;
    cout << arr[-8] << endl;
    int arryo[10] = {};
    cout << _countof(arryo) << endl;
    cout << sizeof(arryo) / sizeof(arryo[0]) << endl;//same as line above
    int howBigAmI;
    cout << sizeof(howBigAmI) << endl;
    string whatsMySize;
    cout << sizeof(whatsMySize) << endl;
    whatsMySize = "test";
    cout << sizeof(whatsMySize) << endl;
    cout << countArr(arryo) << endl;
    for (int& anInt : arryo) 
    {
        cout << "The element is " << anInt << endl;//foreach loop - uses references
    }
    int age = 0;
    int age1 = 0;
    int maxAge = 0;
    for (Person& person : playerArr) 
    {
        age1 = person.age;//before the check so it will store the current value
        if (person.age <= 18) 
        {
            cout << "A person called: " << person.name << " is very young!" << endl;
        }
        else 
        {
            cout << person.name << " is old!" << endl;
        }
        if (age > age1) //if the old value is greater than the new value
        {
            maxAge = age;
        }
        else if (age1>maxAge)
        {
            maxAge = age1;
        }
        age = person.age;//after the check so it will be storing the old value when compared
    }
    cout << "The largest age is: " << maxAge << endl;
}