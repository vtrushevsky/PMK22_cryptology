#include <iostream>

class Figure {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void print() const = 0;
};

class FlatFigure : public Figure {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class VolumetricFigure : public Figure {
public:
    virtual double volume() const = 0;
    virtual double surfaceArea() const = 0;
};

class Polygon : public FlatFigure {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void print() const {
        std::cout << "Polygon" << std::endl;
    }
};

class Circle : public FlatFigure {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void print() const {
        std::cout << "Circle" << std::endl;
    }
};

class Parallelepiped : public VolumetricFigure {
public:
    virtual double volume() const = 0;
    virtual double surfaceArea() const = 0;
    virtual void print() const {
        std::cout << "Parallelepiped" << std::endl;
    }
};

class Cone : public VolumetricFigure {
public:
    virtual double volume() const = 0;
    virtual double surfaceArea() const = 0;
    virtual void print() const {
        std::cout << "Cone" << std::endl;
    }
};

class Rectangle : public Polygon {
public:
    Rectangle(double length, double width) : length_(length), width_(width) {}
    virtual double area() const {
        return length_ * width_;
    }
    virtual double perimeter() const {
        return 2 * (length_ + width_);
    }
    virtual void print() const {
        std::cout << "Rectangle" << std::endl;
    }
private:
    double length_;
    double width_;
};

class Triangle : public Polygon {
public:
    Triangle(double base, double height, double side1, double side2, double side3) : base_(base), height_(height), side1_(side1), side2_(side2), side3_(side3) {}
    virtual double area() const {
        return 0.5 * base_ * height_;
    }
    virtual double perimeter() const {
        return side1_ + side2_ + side3_;
    }
    virtual void print() const {
        std::cout << "Triangle" << std::endl;
    }
private:
    double base_;
    double height_;
    double side1_;
    double side2_;
    double side3_;
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}
    virtual void print() const {
        std::cout << "Square" << std::endl;
    }
};

class Circle2D : public Circle {
public:
    Circle2D(double radius) : radius_(radius) {}
    virtual double area() const {
        return 3.14159 * radius_ * radius_;
    }
    virtual double perimeter() const {
        return 2 * 3.14159 * radius_;
    }
private:
    double radius_;
};

class Cube : public Parallelepiped {
public:
    Cube(double side) : side_(side) {}
    virtual double volume() const {
        return side_ * side_ * side_;
    }
    virtual double surfaceArea() const {
        return 6 * side_ * side_;
    }
    virtual void print() const {
        std::cout << "Cube" << std::endl;
    }
private:
    double side_;
};