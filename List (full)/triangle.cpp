#include "Triangle.h"

Triangle::Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {}
// Constructor: Initializes the sideA, sideB, and sideC member variables with the provided values.

double Triangle::getPerimeter() const {
    return sideA + sideB + sideC;
}
// Calculates and returns the perimeter of the triangle.

double Triangle::getArea() const {
    double s = getPerimeter() / 2.0;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}
// Calculates and returns the area of the triangle using Heron's formula.

bool Triangle::operator==(const Triangle& other) const {
    return sideA == other.sideA && sideB == other.sideB && sideC == other.sideC;
}
// Overloaded equality operator: Compares the sides of two Triangle objects and returns true if they are equal, and false otherwise.

double Triangle::getSideA() const {
    return sideA;
}
// Returns the value of sideA.

double Triangle::getSideB() const {
    return sideB;
}
// Returns the value of sideB.

double Triangle::getSideC() const {
    return sideC;
}
// Returns the value of sideC.
