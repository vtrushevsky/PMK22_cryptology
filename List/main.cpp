#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

class Triangle {
public:
    int a, b, c;

    Triangle(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    double getArea() const {
        double p = getPerimeter() / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    int getPerimeter() const {
        return a + b + c;
    }
};

bool compareTriangles(const Triangle& t1, const Triangle& t2) {
    return t1.getArea() < t2.getArea();
}

int main() {
    // Читання трикутників з файлу та збереження їх у списку
    list<Triangle> triangles;
    ifstream inputFile("triangles.txt");
    int a, b, c;
    while (inputFile >> a >> b >> c) {
        Triangle triangle(a, b, c);
        triangles.push_back(triangle);
    }
    inputFile.close();

    // Сортування трикутників за зростанням площі
    triangles.sort(compareTriangles);

    // Переміщення трикутників периметр яких знаходиться у заданих межах у новий список
    list<Triangle> filteredTriangles;
    int minPerimeter = 0;
    int maxPerimeter = 50;
    for (const Triangle& triangle : triangles) {
        int perimeter = triangle.getPerimeter();
        if (perimeter >= minPerimeter && perimeter <= maxPerimeter) {
            filteredTriangles.push_back(triangle);
        }
    }

    // Запис результуючих списків у новий файл
    ofstream outputFile("result.txt");
    for (const Triangle& triangle : triangles) {
        outputFile << triangle.a << " " << triangle.b << " " << triangle.c << " " << triangle.getArea() << endl;
    }
    outputFile << endl;
    for (const Triangle& triangle : filteredTriangles) {
        outputFile << triangle.a << " " << triangle.b << " " << triangle.c << " " << triangle.getPerimeter() << endl;
    }
    outputFile.close();

    return 0;
}