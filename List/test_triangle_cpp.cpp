#include <gtest/gtest.h>
#include "triangle.h"
#include "triangle.cpp"

TEST(TriangleTest, GetPerimeter) {
	Triangle t(3.0, 4.0, 5.0);
	EXPECT_EQ(t.getPerimeter(), 12.0);
}

TEST(TriangleTest, GetArea) {
	Triangle t(3.0, 4.0, 5.0);
	EXPECT_EQ(t.getArea(), 6.0);
}

TEST(TriangleTest, OperatorEquality) {
	Triangle t1(3.0, 4.0, 5.0);
	Triangle t2(3.0, 4.0, 5.0);
	EXPECT_EQ(t1, t2);
}

TEST(TriangleTest, OperatorInequality) {
	Triangle t1(3.0, 4.0, 5.0);
	Triangle t2(1.0, 2.0, 3.0);
	EXPECT_NE(t1, t2);
}

TEST(TriangleTest, GetSideA) {
	Triangle t(3.0, 4.0, 5.0);
	EXPECT_EQ(t.getSideA(), 3.0);
}

TEST(TriangleTest, GetSideB) {
	Triangle t(3.0, 4.0, 5.0);
	EXPECT_EQ(t.getSideB(), 4.0);
}

TEST(TriangleTest, GetSideC) {
	Triangle t(3.0, 4.0, 5.0);
	EXPECT_EQ(t.getSideC(), 5.0);
}