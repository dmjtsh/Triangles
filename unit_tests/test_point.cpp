#include <iostream>

#include "point.h"
#include "vector.h"

#include <gtest/gtest.h>

//
// Point3D TESTS
//

TEST(TestPointPlusCorrectness, Subtest_1)
{
    Point3D p1(1, 2, 3);
    Point3D p2(2, 3, 5);

    Point3D p_sum = p1 + p2;

    ASSERT_NEAR(p_sum.x, 3.0, 0.0001);
    ASSERT_NEAR(p_sum.y, 5.0, 0.0001);
    ASSERT_NEAR(p_sum.z, 8.0, 0.0001);
}

TEST(TestPointPlusCorrectness, Subtest_2)
{
    Point3D p1(-1, -2, -3);
    Point3D p2(1, 2, 3);

    Point3D p_sum = p1 + p2;

    ASSERT_NEAR(p_sum.x, 0.0, 0.0001);
    ASSERT_NEAR(p_sum.y, 0.0, 0.0001);
    ASSERT_NEAR(p_sum.z, 0.0, 0.0001);
}

TEST(TestPointPlusCorrectness, Subtest_3)
{
    Point3D p1(2.5, 3.5, -1.5);
    Point3D p2(1.5, -2.5, 4.0);

    Point3D p_sum = p1 + p2;

    ASSERT_NEAR(p_sum.x, 4.0, 0.0001);
    ASSERT_NEAR(p_sum.y, 1.0, 0.0001);
    ASSERT_NEAR(p_sum.z, 2.5, 0.0001);
}

TEST(TestPointMinusCorrectness, Subtest_1)
{
    Point3D p1(0, 0, 0);
    Point3D p2(4, 5, 6);

    Point3D p_diff = p1 - p2;

    ASSERT_NEAR(p_diff.x, -4.0, 0.0001);
    ASSERT_NEAR(p_diff.y, -5.0, 0.0001);
    ASSERT_NEAR(p_diff.z, -6.0, 0.0001);
}

TEST(TestPointMinusCorrectness, Subtest_2)
{
    Point3D p1(-1, -2, -3);
    Point3D p2(-1, -2, -3);

    Point3D p_diff = p1 - p2;

    ASSERT_NEAR(p_diff.x, 0.0, 0.0001);
    ASSERT_NEAR(p_diff.y, 0.0, 0.0001);
    ASSERT_NEAR(p_diff.z, 0.0, 0.0001);
}

TEST(TestPointMinusCorrectness, Subtest_3)
{
    Point3D p1(4.5, 3.5, -1.5);
    Point3D p2(1.5, -2.5, 4.0);

    Point3D p_diff = p1 - p2;

    ASSERT_NEAR(p_diff.x, 3.0, 0.0001);
    ASSERT_NEAR(p_diff.y, 6.0, 0.0001);
    ASSERT_NEAR(p_diff.z, -5.5, 0.0001);
}

TEST(TestIsThreePointsOnOneLine, Subtest_1)
{
    Point3D p1(1.0, 2.0, 3.0);
    Point3D p2(2.0, 4.0, 6.0);
    Point3D p3(3.0, 6.0, 9.0);

    bool result = IsThreePointsOnOneLine(p1, p2, p3);

    ASSERT_TRUE(result);
}

TEST(TestIsThreePointsOnOneLine, Subtest_2)
{
    Point3D p1(1.0, 1.0, 1.0);
    Point3D p2(2.0, 2.0, 2.0);
    Point3D p3(3.0, 3.0, 3.0);

    bool result = IsThreePointsOnOneLine(p1, p2, p3);

    ASSERT_TRUE(result);
}

TEST(TestIsThreePointsOnOneLine, Subtest_3)
{
    Point3D p1(0.0, 0.0, 0.0);
    Point3D p2(1.0, 1.0, 1.0);
    Point3D p3(1.0, 2.0, 3.0);

    bool result = IsThreePointsOnOneLine(p1, p2, p3);

    ASSERT_FALSE(result);
}

TEST(TestIsThreePointsOnOneLine, Subtest_4)
{
    Point3D p1(-1.0, -1.0, -1.0);
    Point3D p2(0.0, 0.0, 0.0);
    Point3D p3(1.0, 1.0, 1.0);

    bool result = IsThreePointsOnOneLine(p1, p2, p3);

    ASSERT_TRUE(result);
}

TEST(TestIsThreePointsOnOneLine3D, Subtest_5)
{
    Point3D p1(1.0, 1.0, 1.0);
    Point3D p2(2.0, 2.0, 2.0);
    Point3D p3(2.0, 3.0, 4.0);

    bool result = IsThreePointsOnOneLine(p1, p2, p3);

    ASSERT_FALSE(result);
}

TEST(TestIsThreePointsOnOneLine3D, Subtest_6)
{
    Point3D p1(0.0, 0.0, 1.0);
    Point3D p2(0.0, 0.0, -1.0);
    Point3D p3(0.0, 0.0, 2.0);

    bool result = IsThreePointsOnOneLine(p1, p2, p3);

    ASSERT_FALSE(result);
}

TEST(TestIsThreePointsOnOneLine3D, Subtest_7)
{
    Point3D p1(3.0, 3.0, 2.0);
    Point3D p2(1.0, 1.0, 2.0);
    Point3D p3(1.0, 1.0, 0.0);

    bool result = IsThreePointsOnOneLine(p1, p2, p3);

    ASSERT_FALSE(result);
}

TEST(TestIsThreePointsOnOneLine3D, Subtest_8)
{
    Point3D p1(3.0, 3.0, 1.0);
    Point3D p2(1.0, 0.5, 1.0);
    Point3D p3(3.0, 4.0, 1.0);

    bool result = IsThreePointsOnOneLine(p1, p2, p3);

    ASSERT_FALSE(result);
}

TEST(TestPointAssignmentOperator, AssignVectorToPoint)
{
    Vector3D vector(3.5, -2.5, 4.0);
    Point3D point;

    point = vector;

    ASSERT_NEAR(point.x, vector.x, 0.0001);
    ASSERT_NEAR(point.y, vector.y, 0.0001);
    ASSERT_NEAR(point.z, vector.z, 0.0001);
}

TEST(TestPointAssignmentOperator, AssignZeroVectorToPoint)
{
    Vector3D vector(0.0, 0.0, 0.0);
    Point3D point(1.0, 2.0, 3.0);

    point = vector;

    ASSERT_NEAR(point.x, vector.x, 0.0001);
    ASSERT_NEAR(point.y, vector.y, 0.0001);
    ASSERT_NEAR(point.z, vector.z, 0.0001);
}

TEST(TestPointAssignmentOperator, AssignNegativeVectorToPoint)
{
    Vector3D vector(-5.0, -1.5, -3.0);
    Point3D point;

    point = vector;

    ASSERT_NEAR(point.x, vector.x, 0.0001);
    ASSERT_NEAR(point.y, vector.y, 0.0001);
    ASSERT_NEAR(point.z, vector.z, 0.0001);
}

//
// Point2D TESTS
//

TEST(TestPoint2DPlusCorrectness, Subtest_1)
{
    Point2D p1(1, 2);
    Point2D p2(2, 3);

    Point2D p_sum = p1 + p2;

    ASSERT_TRUE(p_sum.x == 3 && p_sum.y == 5);
}

TEST(TestPoint2DPlusCorrectness, Subtest_2)
{
    Point2D p1(-1, -2);
    Point2D p2(1, 2);

    Point2D p_sum = p1 + p2;

    ASSERT_TRUE(p_sum.x == 0 && p_sum.y == 0);
}

TEST(TestPoint2DPlusCorrectness, Subtest_3)
{
    Point2D p1(2.5, 3.5);
    Point2D p2(1.5, -2.5);

    Point2D p_sum = p1 + p2;

    ASSERT_TRUE(p_sum.x == 4.0 && p_sum.y == 1.0);
}

TEST(TestPoint2DMinusCorrectness, Subtest_1)
{
    Point2D p1(0, 0);
    Point2D p2(4, 5);

    Point2D p_diff = p1 - p2;

    ASSERT_TRUE(p_diff.x == -4 && p_diff.y == -5);
}

TEST(TestPoint2DMinusCorrectness, Subtest_2)
{
    Point2D p1(-1, -2);
    Point2D p2(-1, -2);

    Point2D p_diff = p1 - p2;

    ASSERT_TRUE(p_diff.x == 0 && p_diff.y == 0);
}

TEST(TestPoint2DMinusCorrectness, Subtest_3)
{
    Point2D p1(4.5, 3.5);
    Point2D p2(1.5, -2.5);

    Point2D p_diff = p1 - p2;

    ASSERT_TRUE(p_diff.x == 3.0 && p_diff.y == 6.0);
}

TEST(TestIsThreePointsOnOneLine2D, Subtest_1)
{
    Point2D p1(1.0, 1.0);
    Point2D p2(2.0, 2.0);
    Point2D p3(3.0, 3.0);

    bool result = IsThreePointsOnOneLine(p1, p2, p3);

    ASSERT_TRUE(result);
}

TEST(TestIsThreePointsOnOneLine2D, Subtest_2)
{
    Point2D p1(1.0, 2.0);
    Point2D p2(2.0, 4.0);
    Point2D p3(3.0, 5.0);

    bool result = IsThreePointsOnOneLine(p1, p2, p3);

    ASSERT_FALSE(result);
}

TEST(TestPoint2DAssignmentOperator, AssignVectorToPoint)
{
    Vector2D vector(3.5, -2.5);
    Point2D point;

    point = vector;

    ASSERT_NEAR(point.x, vector.x, 0.0001);
    ASSERT_NEAR(point.y, vector.y, 0.0001);
}

TEST(TestPoint2DAssignmentOperator, AssignZeroVectorToPoint)
{
    Vector2D vector(0.0, 0.0);
    Point2D point(1.0, 2.0);

    point = vector;

    ASSERT_NEAR(point.x, vector.x, 0.0001);
    ASSERT_NEAR(point.y, vector.y, 0.0001);
}

TEST(TestPoint2DAssignmentOperator, AssignNegativeVectorToPoint)
{
    Vector2D vector(-5.0, -1.5);
    Point2D point;

    point = vector;

    ASSERT_NEAR(point.x, vector.x, 0.0001);
    ASSERT_NEAR(point.y, vector.y, 0.0001);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
