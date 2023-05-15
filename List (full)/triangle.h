#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>

class Triangle {
public:
    Triangle(double a, double b, double c); // Constructor

    double getPerimeter() const;
    double getArea() const;
    bool operator==(const Triangle& other) const; // Overloaded equality operator
    double getSideA() const;
    double getSideB() const;
    double getSideC() const;

private:
    double sideA, sideB, sideC; // Private member variables
};

#endif // TRIANGLE_H
