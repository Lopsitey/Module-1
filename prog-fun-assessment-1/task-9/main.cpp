#include <iostream>
#include "Vector2.h"

int main(int argc, char* argv[])
{
    //Please build your interactive calculator, using the
    //Vector2 class, here.
    Vector2 a{ 1.0f, 2.0f };//creates a vector 2 struct which stores 2 floats
    Vector2 b{ 3.0f, 4.0f };

    Vector2 sum = a + b;//adds the x and y values of each struct together using the operator overloads defined in the header file
    Vector2 difference = a - b;
    Vector2 negation = -a;

    std::cout << "Sum: (" << sum.x << ", " << sum.y << ")" << std::endl;//adds each vector together
    std::cout << "Difference: (" << difference.x << ", " << difference.y << ")" << std::endl;
    std::cout << "Negation: (" << negation.x << ", " << negation.y << ")" << std::endl;
    return 0;
}