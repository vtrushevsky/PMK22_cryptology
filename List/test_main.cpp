#include <gtest/gtest.h>
#include <fstream>
#include <sstream>

#include "triangle.h"
#include "doublylinkedlist.h"
#include "main.cpp"

// Test fixture class
class FilterTrianglesTest : public ::testing::Test {
protected:
    // Helper method to read triangles from a string
    DoublyLinkedList<Triangle> readTrianglesFromString(const std::string& input) {
        std::istringstream iss(input);
        DoublyLinkedList<Triangle> triangles;
        double sideA, sideB, sideC;
        while (iss >> sideA >> sideB >> sideC) {
            Triangle triangle(sideA, sideB, sideC);
            triangles.pushBack(triangle);
        }
        return triangles;
    }

    // Helper method to convert triangles to string
    std::string convertTrianglesToString(const DoublyLinkedList<Triangle>& triangles) {
        std::ostringstream oss;
        for (const Triangle& triangle : triangles) {
            oss << triangle.getSideA() << " " << triangle.getSideB() << " " << triangle.getSideC() << "\n";
        }
        return oss.str();
    }

    // Helper method to read triangles from a file
    DoublyLinkedList<Triangle> readTrianglesFromFile(const std::string& filename) {
        std::ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            throw std::runtime_error("Failed to open file: " + filename);
        }
        DoublyLinkedList<Triangle> triangles;
        double sideA, sideB, sideC;
        while (inputFile >> sideA >> sideB >> sideC) {
            Triangle triangle(sideA, sideB, sideC);
            triangles.pushBack(triangle);
        }
        inputFile.close();
        return triangles;
    }
};

// Test case for filterTriangles function
TEST_F(FilterTrianglesTest, FilterTriangles) {
    // Define the input data
    std::string input = "3 4 5\n4 5 6\n7 8 9\n10 11 12\n";
    DoublyLinkedList<Triangle> inputList = readTrianglesFromString(input);
    double minPerimeter = 9.0;
    double maxPerimeter = 20.0;

    // Call the function under test
    DoublyLinkedList<Triangle> filteredList = filterTriangles(inputList, minPerimeter, maxPerimeter);

    // Define the expected output
    std::string expectedOutput = "10 11 12\n";

    // Convert the output to string
    std::string output = convertTrianglesToString(filteredList);

    // Check if the output matches the expected output
    EXPECT_EQ(output, expectedOutput);
}

// Test case for filterTriangles function when no triangles match the criteria
TEST_F(FilterTrianglesTest, FilterTriangles_NoMatch) {
    // Define the input data
    std::string input = "3 4 5\n4 5 6\n7 8 9\n10 11 12\n";
    DoublyLinkedList<Triangle> inputList = readTrianglesFromString(input);
    double minPerimeter = 100.0;
    double maxPerimeter = 200.0;

    // Call the function under test
    DoublyLinkedList<Triangle> filteredList = filterTriangles(inputList, minPerimeter, maxPerimeter);

    // Define the expected output
    std::string expectedOutput = "";
