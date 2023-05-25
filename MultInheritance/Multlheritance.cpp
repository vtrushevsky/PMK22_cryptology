#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

# define M_PI           3.14159265358979323846

using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double volume() const = 0;
};

class ShapeFlat : public Shape {     //ploski
public:
    virtual double area() const = 0;
    virtual double getPerimeter() = 0;
    double volume() const { return 0; }
};

class ShapeVolume : public Shape {   //ob`emni
public:
    double area() const { return 0; }
    virtual double getSurfaceArea() = 0;
    virtual double volume() const = 0;
};

class Polygon : public ShapeFlat {
protected:
    double side;
    double radius;
    int number_of_sides;

    string name;
public:
    Polygon(double s, double r, int n) : side(s), radius(r), number_of_sides(n) {}
    virtual double area() const {
        return ((side * number_of_sides) * radius) * 0.5;
    }
    double getPerimeter() override {
        return side * number_of_sides;
    }
    double getSide() {
        return side;
    }
    double getArea() {
        return ((side * number_of_sides) * radius) * 0.5;
    }
};

class Circle : public ShapeFlat {
protected:
    double radius;
public:
    Circle(double r) : radius(r) {}
    virtual double area() const {
        return M_PI * radius * radius;
    }
    virtual double getPerimeter() override {
        return 2 * M_PI * radius;
    }
    double getRadius() {
        return radius;
    }
    double getArea() {
        return M_PI * radius * radius;;
    }
};

class Parallelepiped : public ShapeVolume {
protected:
    double length, width, height;
public:
    Parallelepiped(double l, double w, double h) : length(l), width(w), height(h) {}
    virtual double volume() const {
        return length * width * height;
    }
    float getSide() {
        return length, width, height;
    }
    double getSurfaceArea() override {
        return 2 * (length * width + width * height + height * length);
    }
    double getArea() {
        return 2 * (length * width + width * height + height * length);
    }
};

class Cone : public ShapeVolume {
protected:
    double radius, height;
public:
    Cone(double r, double h) : radius(r), height(h) {}
    virtual double volume() const {
        return M_PI * radius * radius * height / 3.0;
    }
    double getSurfaceArea() override {
        return M_PI * radius * (radius + sqrt(height * height + radius * radius));
    }
    double getRadius() {
        return radius;
    }
    double getArea() {
        return  M_PI * radius * (radius + sqrt(height * height + radius * radius));
    }
};

bool compare_flat_area(const ShapeFlat* s1, const ShapeFlat* s2) {
    return s1->area() > s2->area();
}

bool compare_volume_height(const ShapeVolume* s1, const ShapeVolume* s2) {
    return s1->volume() < s2->volume();
}

int main() {
    vector<ShapeFlat*> flat_shapes;
    vector<ShapeVolume*> volume_shapes;

    Shape* figures[10];
    figures[0] = new Circle(3);
    figures[1] = new Circle(2);
    figures[2] = new Circle(9);
    figures[3] = new Polygon(4, 2, 4);
    figures[4] = new Polygon(15, 3, 20);

    figures[5] = new Parallelepiped(1, 2, 3);
    figures[6] = new Parallelepiped(2, 3, 4);
    figures[7] = new Cone(2, 3);
    figures[8] = new Cone(10, 20);
    figures[9] = new Cone(1, 2);

    for (int i = 0; i < 10; i++) {
        cout << "Figure " << i + 1 << endl;
        cout << "Area: " << figures[i]->area() << endl;
        cout << "Volume: " << figures[i]->volume() << endl;
        if (dynamic_cast<ShapeFlat*>(figures[i])) {
            cout << "Perimeter: " << dynamic_cast<ShapeFlat*>(figures[i])->getPerimeter() << endl;
        }
        if (dynamic_cast<ShapeVolume*>(figures[i])) {
            cout << "Surface Area: " << dynamic_cast<ShapeVolume*>(figures[i])->getSurfaceArea() << endl;
        }
        cout << endl;
    }
    
    flat_shapes.push_back(new Circle(3));
    flat_shapes.push_back(new Circle(2));
    flat_shapes.push_back(new Circle(9));
    flat_shapes.push_back(new Polygon(4, 2, 4));
    flat_shapes.push_back(new Polygon(15, 3, 20));

    volume_shapes.push_back(new Parallelepiped(1, 2, 3));
    volume_shapes.push_back(new Parallelepiped(2, 3, 4));
    volume_shapes.push_back(new Cone(2, 3));
    volume_shapes.push_back(new Cone(10, 20));
    volume_shapes.push_back(new Cone(1, 2));

    cout << "___________________________________" << endl << endl;

    sort(flat_shapes.begin(), flat_shapes.end(), compare_flat_area);
    cout << "Flat shapes in descending order of areas:\n";
    for (auto shape : flat_shapes) {
        cout << "Area: " << shape->area() << endl;
    }

    // Sort volume shapes in ascending order of heights
    sort(volume_shapes.begin(), volume_shapes.end(), compare_volume_height);
    cout << "\nVolume shapes in ascending order of heights:\n";
    for (auto shape : volume_shapes) {
        cout << "Volume: " << shape->volume() << endl;
    }

    cout << "___________________________________";

    int input;
    cout << "\n\nInput geometric value: ";
    cin >> input;

    int numShapes = 10;
    bool found = false;
    for (int i = 0; i < numShapes; i++) {
        Circle* c = dynamic_cast<Circle*>(figures[i]);
        Cone* co = dynamic_cast<Cone*>(figures[i]);
        Polygon* po = dynamic_cast<Polygon*>(figures[i]);
        Parallelepiped* s = dynamic_cast<Parallelepiped*>(figures[i]);
        if (c && c->getRadius() == input) {
            cout << "Found Circle." << endl;
            cout << "Area: " << c->getArea() << endl << endl;
            found = true;
        }
        else if (s && s->getSide() == input) {
            cout << "Found Paralelepiped." << endl;
            cout << "Area: " << s->getArea() << endl << endl;
            found = true;
        }
        else if (co && co->getRadius() == input) {
            cout << "Found Cone." << endl;
            cout << "Area: " << co->getArea() << endl << endl;
            found = true;
        }
        else if (po && po->getSide() == input) {
            cout << "Found Polygon." << endl;
            cout << "Area: " << po->getArea() << endl << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Shape not found." << endl;
    }

    return 0;
}