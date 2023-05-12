#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Triangle {
    double side1;
    double side2;
    double side3;
    double area;
    double perimeter;
};

bool sortByArea(const Triangle& triangle1, const Triangle& triangle2) {
    return triangle1.area < triangle2.area;
}

int main() {
 ifstream inputFile("/Users/solomia/Desktop/list/list/triangles.txt");
    if (!inputFile) {
    cout << "Failed to open the input file." <<endl;
        return 1;
    }

 vector<Triangle> triangles;
    double minPerimeter, maxPerimeter;
cout << "Enter the minimum perimeter: ";
cin >> minPerimeter;
cout << "Enter the maximum perimeter: ";
    cin >> maxPerimeter;

    while (inputFile) {
        Triangle triangle;
        inputFile >> triangle.side1 >> triangle.side2 >> triangle.side3;
       
        double s = (triangle.side1 + triangle.side2 + triangle.side3) / 2.0;
        triangle.area = sqrt(s * (s - triangle.side1) * (s - triangle.side2) * (s - triangle.side3));
        triangle.perimeter = triangle.side1 + triangle.side2 + triangle.side3;

        triangles.push_back(triangle);
    }

    inputFile.close();

  
    sort(triangles.begin(), triangles.end(), sortByArea);

   
    vector<Triangle> filteredTriangles;
    for (const auto& triangle : triangles) {
        if (triangle.perimeter >= minPerimeter && triangle.perimeter <= maxPerimeter) {
            filteredTriangles.push_back(triangle);
        }
    }

    ofstream outputFile("/Users/solomia/Desktop/list/list/filtered_triangles.txt");
    if (!outputFile) {
      cout << "Failed to open the output file." << std::endl;
        return 1;
    }

    for (const auto& triangle : filteredTriangles) {
        outputFile << "Side 1: " << triangle.side1 << ", Side 2: " << triangle.side2 << ", Side 3: " << triangle.side3
                   << ", Area: " << triangle.area << ", Perimeter: " << triangle.perimeter << endl;
    }

    outputFile.close();

    cout << "Filtered triangles have been written to filtered_triangles.txt." << endl;

    return 0;
}

