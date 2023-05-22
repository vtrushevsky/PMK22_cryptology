#include <iostream>
#include <fstream>
#include <exception>
#include <utility> // for move
#include <cmath> // for sqrt()
#include <Windows.h>
#include <algorithm>
#include<string>
#include "list.h"
using namespace std;


class MyException : public exception
{
public:
    MyException(const char* message) : exception(message) {};


    const char* what()
    {
        return "My exception class";
    }
};

class Triangle
{

public:

    string name;
    double perimetr;
    double area;

    double side[3];

    Triangle() : name(""), perimetr(0), area(0), side() {}


    const double getPerimeter() const { return this->perimetr; }
    double CalculateArea()
    {
        double s = (side[0] + side[1] + side[2]) / 2;
        area = sqrt(s * (s - side[0]) * (s - side[1]) * (s - side[2]));
        area = round(area * 10.0) / 10.0;  //rounding to tenths
        return area;
    }
    double CalculatePerimetr()
    {
        perimetr = this->side[0] + this->side[1] + this->side[2];
        return perimetr;
    }
    friend ostream& operator<<(ostream& os, const Triangle& triangle) {
        os << " Triangle perimetr: " << triangle.perimetr << endl;
        return os;
    }





};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int count = 0;
    ifstream infile("triangle.txt");
    ofstream outfile("sorted_triangles.txt");
    try
    {
        ifstream infile("triangle.txt");
        if (!"triangle.txt")
        {
            throw MyException("Failed to open file.");
        }
    }
    catch (MyException)
    {
        cout << "File name is unknown" << endl;
    }



    const int numberTrinagles = 100;



    Triangle* tri = new Triangle[numberTrinagles]();

    DoubleLinkedList<Triangle> triangles;
    while (!infile.eof()) {

        infile >> tri[count].name >> tri[count].side[0] >> tri[count].side[1] >> tri[count].side[2];
        count++;
    }

    sort(tri, tri + count, [](Triangle& t1, Triangle& t2)
        {return t1.area < t2.area; }
    );
    for (int i = 0; i < count; i++) {
        triangles.PushFront(tri[i]);
    }

    double MinPerimetr, MaxPerimetr;
    cout << "Enter a min perimetr: ";
    cin >> MinPerimetr;
    cout << "Enter a max perimetr: ";
    cin >> MaxPerimetr;
    for (int i = 0; i < count; i++) {
        tri[i].perimetr = tri[i].CalculatePerimetr();
        tri[i].area = tri[i].CalculateArea();
        if (tri[i].perimetr >= MinPerimetr && tri[i].perimetr <= MaxPerimetr)
        {
            outfile << tri[i].name << " side 1: " << tri[i].side[0] << ", side 2: " << tri[i].side[1] << ", side 3: " << tri[i].side[2] << ", perimetr: " << tri[i].perimetr << ", area(rounded to the nearest tenth): " << tri[i].area << endl;

        }
    }

    outfile.close();
    infile.close();

    return 0;
}