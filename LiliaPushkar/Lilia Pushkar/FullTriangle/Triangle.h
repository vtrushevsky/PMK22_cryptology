#pragma once
#include <iostream>
#include <cmath>

using namespace std;


class Triangle {

    double sideA;
    double sideB;
    double sideC;

public:
    Triangle(double a, double b, double c); 
    Triangle(const Triangle& other);

    double GetPerimeter() const; 
    double GetArea() const; 

    bool operator==(const Triangle& other) const; 
    bool operator!=(const Triangle& other) const;

    double GetSideA() const { return sideA; }
    double GetSideB() const { return sideB; }
    double GetSideC() const { return sideC; }
};

