#include <iostream>
#include "Vector2.h"
using namespace std;
int main(int argc, char* argv[])
{
    //Please build your interactive calculator, using the
    //Vector2 class, here.
    Vector2 a{ 1.0f, 2.0f };
    Vector2 b{ 3.0f, 4.0f };

    Vector2 sum = a + b;
    Vector2 difference = a - b;
    cout << "Sum: (" << sum.x << ", " << sum.y << ")" << endl;//adds each vector together
    cout << "Difference: (" << difference.x << ", " << difference.y << ")" << endl;
    return 0;
}