#pragma once
#define PI 3.1415926535
#define convert(x) (x*0.0174533)//degrees to radians
#define NEGATIVE
int sum(int a, int b)
{
    return a + b;
}

int mult(int a, int b)
{
    return a * b;
}

int sub(int a, int b)
{
    return a - b;
}

int test(int a)
{
    return convert(a);//func in a func
}