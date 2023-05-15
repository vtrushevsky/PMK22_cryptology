#include <iostream>
#include <algorithm>
#include <fstream>
#include <list>
#include <cmath>
#include <stdexcept>

#include "triangle.h"
#include "doublylinkedlist.h"

using namespace std;

template<typename T>
DoublyLinkedList<T> filterTriangles(const DoublyLinkedList<T>& inputList, double minPerimeter, double maxPerimeter);
// Function template declaration for filtering triangles based on perimeter.

int main() {
    try {
        DoublyLinkedList<Triangle> triangles; // Doubly linked list of Triangle objects.
        ifstream inputFile("triangles.txt"); // Open file for reading triangles.

        if (!inputFile.is_open())
            throw runtime_error("Error: Failed to open file."); // Throw an exception if the file cannot be opened.

        double sideA, sideB, sideC;
        while (inputFile >> sideA >> sideB >> sideC) {
            Triangle triangle(sideA, sideB, sideC); // Create a Triangle object with given sides.
            triangles.pushBack(triangle); // Add the triangle to the list.
        }

        inputFile.close(); // Close the input file.

        triangles.sort(); // Sort the triangles in ascending order.

        double minPerimeter = 1.0;
        double maxPerimeter = 50.0;
        DoublyLinkedList<Triangle> filteredTriangles = filterTriangles(triangles, minPerimeter, maxPerimeter);
        // Filter triangles based on minimum and maximum perimeter.

        cout << endl;

        for (const Triangle& triangle : filteredTriangles)
            cout << "Triangle with perimeter " << triangle.getPerimeter() << " and area " << triangle.getArea() << endl;
        // Print the filtered triangles' perimeter and area.
    }
    catch (const exception& ex) {
        cout << "Exception occurred: " << ex.what() << endl;
    }

    return 0;
}

template<typename T>
DoublyLinkedList<T> filterTriangles(const DoublyLinkedList<T>& inputList, double minPerimeter, double maxPerimeter) {
    DoublyLinkedList<T> filteredList; // Doubly linked list to store filtered triangles.
    for (const T& item : inputList) {
        if (item.getPerimeter() >= minPerimeter && item.getPerimeter() <= maxPerimeter)
            filteredList.pushBack(item); // Add triangle to filtered list if its perimeter falls within the specified range.
    }
    return filteredList; // Return the filtered list.
}
