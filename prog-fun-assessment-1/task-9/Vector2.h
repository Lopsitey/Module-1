#include <iostream>
#pragma once

using std::cerr;

struct Vector2 {
    //Here you should fill out the class according
    //to what is requested by challenge #9.   
    float x, y;//the two paramaters the struct will take when initialized

    Vector2 operator+(const Vector2& other) const //overloads the operator with another vector 2 struct being passed in as a reference argument
    {
        return Vector2{ x + other.x, y + other.y };//adds all 4 values together - where x is the value of the current vector and other.x is the vector being passed into the constructor
    }

    Vector2 operator-(const Vector2& other) const 
    {
        return Vector2{ x - other.x, y - other.y };
    }

    Vector2 operator*(const Vector2& other) const 
    {
        return Vector2{ x * other.x, y * other.y };
    }

    Vector2 operator/(const Vector2& other) const 
    {
        if (other.x == 0.0f || other.y == 0.0f || x == 0.0f || y == 0.0f)//ensures the user doesn't attempt division by zero - none of the 4 values can be zero
        {
            cerr << "Error: Division by zero.\n";
            return Vector2{ 0.0f, 0.0f };
        }
        return Vector2{ x / other.x, y / other.y };
    }

    Vector2 operator-() const 
    {   
        return Vector2{ -x, -y};//negation - returns the opposite value (negative if positive, and positive if negative)
    }
};