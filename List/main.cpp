#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Triangle {
    double a, b, c;

    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    double getArea() const {
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

bool operator<<(const Triangle& t1, const Triangle& t2) {
    return t1.getArea() < t2.getArea();
}

int main() {
    vector<Triangle> triangles;
    ifstream input("triangles.txt");

    double a, b, c;
    while (input >> a >> b >> c) {
        triangles.push_back(Triangle(a, b, c));
    }

    sort(triangles.begin(), triangles.end());

    double minPerimeter = 10.0;
    double maxPerimeter = 20.0;
    vector<Triangle> filteredTriangles;
    for (const auto& t : triangles) {
        double perimeter = t.a + t.b + t.c;
        if (perimeter >= minPerimeter && perimeter <= maxPerimeter) {
            filteredTriangles.push_back(t);
        }
    }

    ofstream output("filtered_triangles.txt");
    for (const auto& t : filteredTriangles) {
        output << t.a << " " << t.b << " " << t.c << endl;
    }

    return 0;
}
