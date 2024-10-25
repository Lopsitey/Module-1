#include <iostream>
using namespace std;
struct Vector2 
{
    int x;
    int y;
};
int main()
{
    float* ahaheoo = nullptr;
    bool* wehaweho = nullptr;
    int* hetetewato = nullptr;
    float player1Health = 50.0f;
    float player2Health = 25.0f;
    float* currentHealth = &player2Health;
    cout << &player2Health << endl;
    cout << currentHealth << endl;
    *currentHealth = 10.0f;
    currentHealth = &player1Health;
    cout << &player1Health << endl;
    cout << currentHealth << endl;
    cout << &currentHealth << endl;//the address of the pointer which is storing an address
    cout << *currentHealth << endl;
    *currentHealth = 5.0f;
    cout << *currentHealth << endl;
    cout << "P1:" << player1Health << endl;
    cout << "P2:" << player2Health << endl;
    currentHealth = &player1Health;
    float temp = *currentHealth;
    player1Health = player2Health;
    player2Health = temp;//gotta use a temp variable because the pointer keeps pointing to the varibale even when it changes value
    cout << "P1, again:" << player1Health << endl;
    cout << "P2, again:" << player2Health << endl;
    int arr[5] = {10,20,38,69,420};
    int* arrPtr = arr;
    cout << arrPtr[0] << endl;
    cout << arrPtr[1] << endl;
    cout << arrPtr[4] << endl;
    Vector2 vectorr;
    //&=address/reference *=pointer/referencevalue blank=referenceaddress
}