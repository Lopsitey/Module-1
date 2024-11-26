#include <iostream>
#pragma once
struct Vector2 {
    //Here you should fill out the class according
    //to what is requested by challenge #9.   
    float x, y;

    Vector2 operator+(const Vector2& other) const 
    {
        return Vector2{ x + other.x, y + other.y };
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
        if (other.x == 0.0f || other.y == 0.0f)//ensures the user doesn't attempt division by zero
        {
            cerr << "Error: Division by zero.\n";
            return Vector2{ 0.0f, 0.0f };
        }
        return Vector2{ x / other.x, y / other.y };
    }

    Vector2 operator-() const 
    {   
        return Vector2{ -x, -y};//negation
    }
};