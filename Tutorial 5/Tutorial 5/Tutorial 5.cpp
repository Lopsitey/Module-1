#include <iostream>
#include <windows.h>
#include <string>
#define sleep(x) Sleep(1000 * (x))
using namespace std;

int SquareNumber(int);
int MultiplyByThree(int);
string DadJoke();
int MultiplyTogether(int, int);
int AddTogether(int, int);
void NameOutput();
bool DetectParam(int, int);
void Maths(float);

int main()
{
    cout << SquareNumber(35) << endl;
    cout << SquareNumber(2) << endl;
    cout << SquareNumber(10) << endl;
    cout << SquareNumber(20) << endl;
    cout << SquareNumber(25) << endl;
    cout << SquareNumber(40) << endl;

    cout << MultiplyByThree(3) << endl;
    cout << MultiplyByThree(6) << endl;
    cout << MultiplyByThree(10) << endl;

    cout << DadJoke() << endl;

    cout << MultiplyTogether(10, 20) << endl;

    cout << AddTogether(50, 10) << endl;

    NameOutput();

    cout << "Is a paramater odd (0) or even (1)? " << DetectParam(10, 31) << endl;

    Maths(10);

    /*
    while(true)
    {
        cout << clock() << endl;
    }
    */
    MessageBeep(10);

    MessageBoxA(0, DadJoke().c_str(), "a title", 1);//creates a window

}

int SquareNumber(int a) 
{
    return a * a;
}

int MultiplyByThree(int a)
{
    return a * 3;
}

int MultiplyTogether(int a, int b)
{
    return a * b;
}

int AddTogether(int a, int b)
{
    return a + b;
}

string DadJoke() 
{
    cout << "How do you teach a kid to climb stairs?" << endl;
    sleep(1);
    cout << "." << endl;
    sleep(2);
    cout << ".." << endl;
    sleep(3);
    cout << "..." << endl;
    return "There is a step by step guide.";
}

void NameOutput()
{
    cout << "Jake Stephen George Astles" << endl;
}

bool DetectParam(int a, int b)
{
    if (a%2==0 || b%2==0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void Maths(float a)
{
    cout << "To the power of 2: " << powf(a, 2) << endl;
    cout << "To the square root of 2: " << sqrt(a) << endl;
    cout << "The absolute value: " << fabsf(a) << endl;//the absolute value of a floating point argument
    cout << "To sine: " << sinf(a) << endl;//the sine of a floating point value -- trigonometry function
    cout << "To cosine: " << cosf(a) << endl;//the cosine of a floating point value -- trigonometry function
}