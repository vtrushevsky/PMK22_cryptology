#include "Triangle.h"


Triangle::Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {}

Triangle::Triangle(const Triangle& other) : sideA(other.sideA), sideB(other.sideB), sideC(other.sideC) {} 

double Triangle::GetPerimeter() const 
{ return sideA + sideB + sideC; }

double Triangle::GetArea() const 
{ 
    double s = GetPerimeter() / 2.0;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

bool Triangle::operator==(const Triangle& other) const 
{ return sideA == other.sideA && sideB == other.sideB && sideC == other.sideC; }

bool Triangle::operator!=(const Triangle& other) const 
{  return !(*this == other); }

