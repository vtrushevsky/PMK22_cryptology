#include "pch.h"
#include <gtest/gtest.h>
#include "triangle.h"

// Test fixture class
class TriangleTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Set up any required initialization before each test
    }

    void TearDown() override {
        // Clean up any resources after each test
    }
};

// Test case for the constructor
TEST_F(TriangleTest, Constructor) {
    // Create a Triangle object
    Triangle triangle(3.0, 4.0, 5.0);

    // Perform assertions to check the values of the sides
    EXPECT_EQ(3.0, triangle.getSideA());
    EXPECT_EQ(4.0, triangle.getSideB());
    EXPECT_EQ(5.0, triangle.getSideC());
}

// Test case for getPerimeter() method
TEST_F(TriangleTest, GetPerimeter) {
    Triangle triangle(3.0, 4.0, 5.0);

    // Perform assertion to check the calculated perimeter
    EXPECT_DOUBLE_EQ(12.0, triangle.getPerimeter());
}

// Test case for getArea() method
TEST_F(TriangleTest, GetArea) {
    Triangle triangle(3.0, 4.0, 5.0);

    // Perform assertion to check the calculated area
    EXPECT_DOUBLE_EQ(6.0, triangle.getArea());
}

// Test case for operator==() method
TEST_F(TriangleTest, EqualityOperator) {
    Triangle triangle1(3.0, 4.0, 5.0);
    Triangle triangle2(3.0, 4.0, 5.0);
    Triangle triangle3(4.0, 5.0, 6.0);

    // Perform assertions to check the equality operator
    EXPECT_TRUE(triangle1 == triangle2);
    EXPECT_FALSE(triangle1 == triangle3);
}
