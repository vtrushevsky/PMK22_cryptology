#include <iostream>
#include <fstream>
#include <exception>
#include <utility> // for move
#include <cmath> // for sqrt()
#include <Windows.h>
#include <algorithm>
#include<string>
#include "Header.h"
using namespace std;


class MyException : public exception
{
public:
    MyException(const char* message) : exception(message) {};


    const char* what()
    {
        return " exception ";
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
    double CalculateArea();
    double CalculatePerimetr();

    friend ostream& operator<<(ostream& os, const Triangle& triangle) {
        os << " Периметир трикутника : " << triangle.perimetr << endl;
        return os;
    }





};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int count = 0;
    ifstream infile("Text1.txt");
    ofstream outfile("Text.txt");
    try
    {
        ifstream infile("Text1.txt");
        if (!"Text1.txt")
        {
            throw MyException("Не вдалося відкрити файл.");
        }
    }
    catch (MyException)
    {
        cout << "Назва файлу невідома" << endl;
    }



    const int numberTrinagles = 100;



    Triangle* tri = new Triangle[numberTrinagles]();

    DoubleLinkedList<Triangle> triangles;
    while (!infile.eof()) {
        infile >> tri[count].name >> tri[count].side[0] >> tri[count].side[1] >> tri[count].side[2];
        count++;
    }

    sort(tri, tri + count, [](Triangle& t1, Triangle& t2) {return t1.area < t2.area; });
    for (int i = 0; i < count; i++) {
        triangles.PushFront(tri[i]);
    }

    double MinPerimetr, MaxPerimetr;
    cout << "Введіть мінімальний периметр: ";
    cin >> MinPerimetr;
    cout << "Введіть максимальний периметр: ";
    cin >> MaxPerimetr;
    for (int i = 0; i < count; i++) {
        tri[i].perimetr = tri[i].CalculatePerimetr();
        tri[i].area = tri[i].CalculateArea();
        if (tri[i].perimetr >= MinPerimetr && tri[i].perimetr <= MaxPerimetr)
        {
            outfile << tri[i].name << " сторона 1: " << tri[i].side[0] << ", сторона 2: " << tri[i].side[1] << "сторона  3: " << tri[i].side[2] << " периметр : " << tri[i].perimetr << ", площа (округлена): " << tri[i].area << endl;

        }
    }

    outfile.close();
    infile.close();

    return 0;
}

double Triangle :: CalculateArea()
{
    
        double s = (side[0] + side[1] + side[2]) / 2;
        area = sqrt(s * (s - side[0]) * (s - side[1]) * (s - side[2]));
        area = round(area * 10.0) / 10.0;  
        return area;
    
}

double Triangle::CalculatePerimetr()
{
    perimetr = this->side[0] + this->side[1] + this->side[2];
    return perimetr;
}
