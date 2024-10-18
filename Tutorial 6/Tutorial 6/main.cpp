#include "main.h"
using namespace std;
int main()
{
    cout << sum(10, 20);
    cout << "a";
    SetCursor(50, 80);
    cout << "b";
    ClearRows(1);
    cout << "c";
    SetColour(0xFF,0xFF,0xFF);
    test(10);//converts 10 degrees to radians
}