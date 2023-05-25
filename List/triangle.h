#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>


class Triangle {
public:
    Triangle(double a, double b, double c); // Constructor
    Triangle(const Triangle& other); // Copy constructor
    double getPerimeter() const; // Method
    double getArea() const; // Method
    bool operator==(const Triangle& other) const; // Method
    bool operator!=(const Triangle& other) const; // Method
    double getSideA() const; // Method
    double getSideB() const; // Method
    double getSideC() const; // Method

private:
    double sideA;
    double sideB;
    double sideC;
};

#endif // TRIANGLE_H
