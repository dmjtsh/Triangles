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

TEST(TestIsPointInTriangle, PointInsideTriangle)
{
    Triangle2D triangle(Point2D(0, 0), Point2D(5, 0), Point2D(2.5, 5));
    Point2D point(2.5, 2);

    ASSERT_TRUE(IsPointInTriangle(triangle, point));
}

TEST(TestIsPointInTriangle, PointOnTriangleEdge)
{
    Triangle2D triangle(Point2D(0, 0), Point2D(5, 0), Point2D(2.5, 5));
    Point2D point(2.5, 0);

    ASSERT_TRUE(IsPointInTriangle(triangle, point));
}

TEST(TestIsPointInTriangle, PointOutsideTriangle)
{
    Triangle2D triangle(Point2D(1, 1), Point2D(5, 0), Point2D(2.5, 5));
    Point2D point(5, 2);

    ASSERT_FALSE(IsPointInTriangle(triangle, point));
}

TEST(TestIsPointInTriangle, PointOnVertex)
{
    Triangle2D triangle(Point2D(0, 0), Point2D(5, 0), Point2D(2.5, 5));
    Point2D point(5, 0);

    ASSERT_TRUE(IsPointInTriangle(triangle, point));
}

TEST(TestIsPointInTriangle, PointOutsideFar)
{
    Triangle2D triangle(Point2D(0, 0), Point2D(5, 0), Point2D(2.5, 5));
    Point2D point(10, 10);

    ASSERT_FALSE(IsPointInTriangle(triangle, point));
}

TEST(TestCheckTrianglesIntersection2D, SmallIntersection)
{
    Triangle2D triangle1(Point2D(0, 0), Point2D(5, 0), Point2D(2.5, 5));
    Triangle2D triangle2(Point2D(2, 2), Point2D(6, 0), Point2D(4, 4));

    ASSERT_TRUE(CheckTrianglesIntersection(triangle1, triangle2));
}

TEST(TestCheckTrianglesIntersection2D, NoIntersection1)
{
    Triangle2D triangle1(Point2D(0, 0), Point2D(5, 0), Point2D(2.5, 5));
    Triangle2D triangle2(Point2D(3.5, 3.5), Point2D(6, 0), Point2D(4, 4));

    ASSERT_FALSE(CheckTrianglesIntersection(triangle1, triangle2));
}

TEST(TestCheckTrianglesIntersection2D, NoIntersection2)
{
    Triangle2D triangle1(Point2D(1, 1), Point2D(0.5, 0.5), Point2D(2.5, 5));
    Triangle2D triangle2(Point2D(2, 2), Point2D(3, 0), Point2D(3, 3));

    ASSERT_FALSE(CheckTrianglesIntersection(triangle2, triangle1));
}

TEST(TestCheckTrianglesIntersection2D, OneInAnother1)
{
    Triangle2D triangle1(Point2D(0, 0), Point2D(5, 0), Point2D(2.5, 5));
    Triangle2D triangle2(Point2D(2, 2), Point2D(3, 0), Point2D(3, 3));

    ASSERT_TRUE(CheckTrianglesIntersection(triangle1, triangle2));
}

TEST(TestCheckTrianglesIntersection2D, OneInAnother2)
{
    Triangle2D triangle1(Point2D(0, 0), Point2D(5, 0), Point2D(2.5, 5));
    Triangle2D triangle2(Point2D(2, 2), Point2D(3, 0), Point2D(3, 3));

    ASSERT_TRUE(CheckTrianglesIntersection(triangle2, triangle1));
}

TEST(TestCheckTrianglesIntersection2D, NegativeVertex1)
{
    Triangle2D triangle1(Point2D(-1, 1), Point2D(0.5, 0.5), Point2D(2.5, 5));
    Triangle2D triangle2(Point2D(-2, -2), Point2D(3, 0), Point2D(3, 3));

    ASSERT_TRUE(CheckTrianglesIntersection(triangle2, triangle1));
}

TEST(TestCheckTrianglesIntersection2D, NegativeVertex2)
{
    Triangle2D triangle1(Point2D(-1, 1), Point2D(0.5, 0.5), Point2D(2.5, 5));
    Triangle2D triangle2(Point2D(-1, -2), Point2D(3, 0), Point2D(3, 3));

    ASSERT_FALSE(CheckTrianglesIntersection(triangle2, triangle1));
}

TEST(TestCheckTrianglesIntersection2D, NegativeVertex3)
{
    Triangle2D triangle1(Point2D(-1, 1), Point2D(0.5, 0.5), Point2D(2.5, 5));
    Triangle2D triangle2(Point2D(-1, -2), Point2D(-2, -2), Point2D(1/3, 1/3));

    ASSERT_FALSE(CheckTrianglesIntersection(triangle2, triangle1));
}

TEST(TestCheckTrianglesIntersection2D, NegativeVertex4)
{
    Triangle2D triangle1(Point2D(-1, 1), Point2D(0.5, 0.5), Point2D(2.5, 5));
    Triangle2D triangle2(Point2D(-1, -2), Point2D(-2, -2), Point2D(1, 1));

    ASSERT_TRUE(CheckTrianglesIntersection(triangle2, triangle1));
}

TEST(TestCheckTrianglesIntersection2D, NegativeVertex5)
{
    Triangle2D triangle1(Point2D(-1, 1), Point2D(0.5, 0.5), Point2D(2.5, 5));
    Triangle2D triangle2(Point2D(-1, -2), Point2D(-3, -2), Point2D(1, 1));

    ASSERT_TRUE(CheckTrianglesIntersection(triangle2, triangle1));
}

TEST(TestCheckTrianglesIntersection2D, NegativeVertex6)
{
    Triangle2D triangle1(Point2D(-5, 6), Point2D(-0.5, -0.5), Point2D(-2.5, -5));
    Triangle2D triangle2(Point2D(-1, -2), Point2D(-3, -2), Point2D(-1, -1));

    ASSERT_TRUE(CheckTrianglesIntersection(triangle2, triangle1));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
