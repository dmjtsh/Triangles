#include <iostream>

#include "point.h"
#include "triangle.h"

#include <gtest/gtest.h>

TEST(TestTriangleValid, ValidTriangle)
{
    Point p1(0, 0, 0);
    Point p2(1, 1, 0);
    Point p3(0, 1, 1);
    Triangle triangle(p1, p2, p3);

    ASSERT_TRUE(triangle.valid());
}

TEST(TestTriangleValid, InvalidTriangleWithCoincidingPoints)
{
    Point p1(0, 0, 0);
    Point p2(0, 0, 0);
    Point p3(1, 1, 1);
    Triangle triangle(p1, p2, p3);

    ASSERT_FALSE(triangle.valid());
}

TEST(TestTriangleValid, InvalidTriangleWithCollinearPoints)
{
    Point p1(0, 0, 0);
    Point p2(1, 1, 1);
    Point p3(2, 2, 2);
    Triangle triangle(p1, p2, p3);

    ASSERT_FALSE(triangle.valid());
}

TEST(TestTriangleValid, InvalidTriangleWithInvalidPoints)
{
    Point p1(0, 0, 0);
    Point p2(NAN, NAN, NAN);
    Point p3(1, 1, 1);
    Triangle triangle(p1, p2, p3);

    ASSERT_FALSE(triangle.valid());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
