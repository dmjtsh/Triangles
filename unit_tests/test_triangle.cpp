#include <iostream>

#include "point.h"
#include "triangle.h"

#include <gtest/gtest.h>

//
// Triangle3D Tests
//

TEST(TestTriangleValid, ValidTriangle)
{
    Point3D p1(0, 0, 0);
    Point3D p2(1, 1, 0);
    Point3D p3(0, 1, 1);
    Triangle3D triangle(p1, p2, p3);

    ASSERT_TRUE(triangle.valid());
}

TEST(TestTriangleValid, InvalidTriangleWithCoincidingPoints)
{
    Point3D p1(0, 0, 0);
    Point3D p2(0, 0, 0);
    Point3D p3(1, 1, 1);
    Triangle3D triangle(p1, p2, p3);

    ASSERT_FALSE(triangle.valid());
}

TEST(TestTriangleValid, InvalidTriangleWithCollinearPoints)
{
    Point3D p1(0, 0, 0);
    Point3D p2(1, 1, 1);
    Point3D p3(2, 2, 2);
    Triangle3D triangle(p1, p2, p3);

    ASSERT_FALSE(triangle.valid());
}

TEST(TestTriangleValid, InvalidTriangleWithInvalidPoints)
{
    Point3D p1(0, 0, 0);
    Point3D p2(NAN, NAN, NAN);
    Point3D p3(1, 1, 1);
    Triangle3D triangle(p1, p2, p3);

    ASSERT_FALSE(triangle.valid());
}

//
// Triangle2D Tests
//

TEST(TestTriangle2DValid, ValidTriangle)
{
    Point2D p1(0, 0);
    Point2D p2(1, 0);
    Point2D p3(0, 1);
    Triangle2D triangle(p1, p2, p3);

    ASSERT_TRUE(triangle.valid());
}

TEST(TestTriangle2DValid, InvalidTriangleWithCoincidingPoints)
{
    Point2D p1(0, 0);
    Point2D p2(0, 0);
    Point2D p3(1, 1);
    Triangle2D triangle(p1, p2, p3);

    ASSERT_FALSE(triangle.valid());
}

TEST(TestTriangle2DValid, InvalidTriangleWithCollinearPoints)
{
    Point2D p1(0, 0);
    Point2D p2(1, 1);
    Point2D p3(2, 2);
    Triangle2D triangle(p1, p2, p3);

    ASSERT_FALSE(triangle.valid());
}

TEST(TestTriangle2DValid, InvalidTriangleWithInvalidPoints)
{
    Point2D p1(0, 0);
    Point2D p2(NAN, NAN);
    Point2D p3(1, 1);
    Triangle2D triangle(p1, p2, p3);

    ASSERT_FALSE(triangle.valid());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
