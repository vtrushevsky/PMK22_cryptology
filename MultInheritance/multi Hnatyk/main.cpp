#include <iostream>
#include <string>

using namespace std;

class Figure {
public:
    virtual float area() = 0;
    virtual float volume() = 0;
    virtual void print() = 0;
};

class FlatFigure : public Figure {
public:
    virtual float area() = 0;
    float volume() { return 0; }
};

class SolidFigure : public Figure {
public:
    virtual float volume() = 0;
    float area() { return 0; }
};

//  Багатокутник
class Polygon : public FlatFigure {
protected:
    float sides[10]; // Масив сторін багатокутника
    int n;
public:
    virtual float area() = 0;
    virtual void print() = 0;
};

class Circle : public FlatFigure {
protected:
    float radius;
public:
    Circle(float r) : radius(r) {} // Конструктор
    float area() { return 3.1415 * radius * radius; } //  площа кола
    void print() { cout << "Circle, radius = " << radius << ", area = " << area() << endl; }
};
class Parallelepiped : public SolidFigure {
protected:
    float a, b, h; // Довжина, ширина та висота паралелепіпеда
public:
    Parallelepiped(float aa, float bb, float hh) : a(aa), b(bb), h(hh) {} // Конструктор
    float volume() { return a * b * h; } // об'єм паралелепіпеда
    void print() { cout << "Parallelepiped, a = " << a << ", b = " << b << ", h = " << h << ", volume = " << volume() << endl; }
};

class Cone : public SolidFigure {
protected:
    float r, h;
public:
    Cone(float rr, float hh) : r(rr), h(hh) {}
    float volume() { return (1.0/3.0) * 3.1415 * r * r * h; }
    void print() { cout << "Cone, r = " << r << ", h = " << h << ", volume = " << volume() << endl; }
    };

int main() {
    Figure *figures[10]; // Масив
    // Ввід даних
    figures[0] = new Circle(5.0);
    figures[1] = new Parallelepiped(3.0, 4.0, 5.0);
    figures[2] = new Cone(2.0, 4.0);
    figures[3] = new Circle(3.0);
    figures[4] = new Parallelepiped(2.0, 6.0, 4.0);
    figures[5] = new Cone(4.0, 6.0);
    figures[6] = new Circle(2.0);
    figures[7] = new Parallelepiped(5.0, 3.0, 2.0);
    figures[8] = new Cone(3.0, 5.0);
    figures[9] = new Circle(4.0);
    
    //  порядок спадання площі
    //  оператор dynamic_cast я взяла з інтернету
    cout << "Flat figures:" << endl;
    for (int i = 0; i < 10; i++) {
        if (dynamic_cast<FlatFigure*>(figures[i])) {
            for (int j = i + 1; j < 10; j++) {
                if (figures[i]->area() < figures[j]->area()) { // Сортування фігур за спаданням площі
                    Figure *temp = figures[i];
                    figures[i] = figures[j];
                    figures[j] = temp;
                }
            }
            figures[i]->print();
        }
    }
    
    //  зростання висоти
    cout << "Solid figures:" << endl;
    for (int i = 0; i < 10; i++) {
        if (dynamic_cast<SolidFigure*>(figures[i])) {
            for (int j = i + 1; j < 10; j++) {
                if (dynamic_cast<SolidFigure*>(figures[j]) && dynamic_cast<SolidFigure*>(figures[i])->volume() > dynamic_cast<SolidFigure*>(figures[j])->volume()) { // Сортування фігур за зростанням висоти
                    Figure *temp = figures[i];
                    figures[i] = figures[j];
                    figures[j] = temp;
                }
            }
            figures[i]->print();
        }
    }
    
    
}
