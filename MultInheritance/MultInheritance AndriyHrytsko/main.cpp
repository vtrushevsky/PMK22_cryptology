#include <iostream>

using namespace std;

class Figure {
public:
    virtual double area() = 0;
    virtual double volume() = 0;
    virtual void print() = 0;
};

class PlaneFigure : public Figure {
public:
    virtual double area() = 0;
    double volume() { return 0.0; }
};

class SolidFigure : public Figure {
public:
    double area() { return 0.0; }
    virtual double volume() = 0;
};

class Polygon : public PlaneFigure {
protected:
    int numSides;
public:
    Polygon(int numSides) : numSides(numSides) {}
    int getNumSides() { return numSides; }
};

class Circle : public PlaneFigure {
protected:
    double radius;
public:
    Circle(double radius) : radius(radius) {}
    double area() { return 3.14 * radius * radius; }
    void print() { cout << "Circle with radius " << radius << endl; }
};

class Parallelepiped : public SolidFigure {
protected:
    double length, width, height;
public:
    Parallelepiped(double length, double width, double height) : length(length), width(width), height(height) {}
    double volume() { return length * width * height; }
    void print() { cout << "Parallelepiped with length " << length << ", width " << width << ", and height " << height << endl; }
};

class Cone : public SolidFigure {
protected:
    double radius, height;
public:
    Cone(double radius, double height) : radius(radius), height(height) {}
    double volume() { return (1.0 / 3.0) * 3.14 * radius * radius * height; }
    void print() { cout << "Cone with radius " << radius << " and height " << height << endl; }
};

int main() {
    Figure* figures[10];

    figures[0] = new Circle(3.0);
    figures[1] = new Circle(4.0);
    figures[2] = new Circle(2.0);
    figures[3] = new Parallelepiped(2.0, 3.0, 4.0);
    figures[4] = new Parallelepiped(5.0, 2.0, 1.0);
    figures[5] = new Parallelepiped(3.0, 3.0, 3.0);
    figures[6] = new Cone(2.0, 5.0);
    figures[7] = new Cone(3.0, 2.0);
    figures[8] = new Cone(1.0, 6.0);
    figures[9] = new Polygon(5);

    // Plane figures sorted by area in descending order
    for (int i = 0; i < 10; i++) {
        if (dynamic_cast<PlaneFigure*>(figures[i]) != nullptr) {
            for (int j = i + 1; j < 10; j++) {
                if (dynamic_cast<PlaneFigure*>(figures[j]) != nullptr) {
                    if (figures[j]->area() > figures[i]->area()) {
                        Figure* temp = figures[i];
                        figures[i] = figures[j];
                        figures[j] = temp;
                    }
                }
            }
        }
    }

    cout << "Plane figures sorted by area in descending order:" << endl;
    for (int i = 0; i < 10; i++) {
        if (dynamic_cast<PlaneFigure*>(figures[i]) != nullptr) {
            figures[i]->print();
        }
    }

    // Solid figures sorted by height in ascending order
    for (int i = 0; i < 10; i++) {
        if (dynamic_cast<SolidFigure*>(figures[i]) != nullptr) {
            for (int j = i + 1; j < 10; j++) {
                if (dynamic_cast<SolidFigure*>(figures[j]) != nullptr) {
                    if (dynamic_cast<Cone*>(figures[j]) != nullptr && dynamic_cast<Cone*>(figures[i]) != nullptr) {
                        if (dynamic_cast<Cone*>(figures[j])->height < dynamic_cast<Cone*>(figures[i])->height) {
                            Figure* temp = figures[i];
                            figures[i] = figures[j];
                            figures[j] = temp;
                        }
                    }
                    else if (figures[j]->volume() < figures[i]->volume()) {
                        Figure* temp = figures[i];
                        figures[i] = figures[j];
                        figures[j] = temp;
                    }
                }
            }
        }
    }

    cout << "Solid figures sorted by height in ascending order:" << endl;
    for (int i = 0; i < 10; i++) {
        if (dynamic_cast<SolidFigure*>(figures[i]) != nullptr) {
            figures[i]->print();
        }
    }

    // Find figure with matching dimension
    double dimension;
    cout << "Enter a dimension: ";
    cin >> dimension;

    for (int i = 0; i < 10; i++) {
        if (dynamic_cast<Circle*>(figures[i]) != nullptr) {
            if (dynamic_cast<Circle*>(figures[i])->radius == dimension) {
                cout << "Match found: ";
                figures[i]->print();
            }
        }
        else if (dynamic_cast<Parallelepiped*>(figures[i]) != nullptr) {
            if (dynamic_cast<Parallelepiped*>(figures[i])->length == dimension || dynamic_cast<Parallelepiped*>(figures[i])->width == dimension || dynamic_cast<Parallelepiped*>(figures[i])->height == dimension) {
                cout << "Match found: ";
                figures[i]->print();
            }
        }
        else if (dynamic_cast<Cone*>(figures[i]) != nullptr) {
            if (dynamic_cast<Cone*>(figures[i])->radius == dimension || dynamic_cast<Cone*>(figures[i])->height == dimension) {
                cout << "Match found: ";
                figures[i]->print();
            }
        }
    }

    return 0;
}

