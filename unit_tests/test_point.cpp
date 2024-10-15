#include <iostream>

#include "point.h"
#include "vector.h"

#include <gtest/gtest.h>

TEST(TestPointPlusCorrectness, Subtest_1)
{
    Point p1(1, 2, 3);
    Point p2(2, 3, 5);

    Point p_sum = p1 + p2;

    ASSERT_TRUE(p_sum.x == 3 && p_sum.y == 5 && p_sum.z == 8);
}

TEST(TestPointPlusCorrectness, Subtest_2)
{
    Point p1(-1, -2, -3);
    Point p2(1, 2, 3);

    Point p_sum = p1 + p2;

    ASSERT_TRUE(p_sum.x == 0 && p_sum.y == 0 && p_sum.z == 0);
}

TEST(TestPointPlusCorrectness, Subtest_3)
{
    Point p1(2.5, 3.5, -1.5);
    Point p2(1.5, -2.5, 4.0);

    Point p_sum = p1 + p2;

    ASSERT_TRUE(p_sum.x == 4.0 && p_sum.y == 1.0 && p_sum.z == 2.5);
}

TEST(TestPointMinusCorrectness, Subtest_1)
{
    Point p1(0, 0, 0);
    Point p2(4, 5, 6);

    Point p_diff = p1 - p2;

    ASSERT_TRUE(p_diff.x == -4 && p_diff.y == -5 && p_diff.z == -6);
}

TEST(TestPointMinusCorrectness, Subtest_2)
{
    Point p1(-1, -2, -3);
    Point p2(-1, -2, -3);

    Point p_diff = p1 - p2;

    ASSERT_TRUE(p_diff.x == 0 && p_diff.y == 0 && p_diff.z == 0);
}

TEST(TestPointMinusCorrectness, Subtest_3)
{
    Point p1(4.5, 3.5, -1.5);
    Point p2(1.5, -2.5, 4.0);

    Point p_diff = p1 - p2;

    ASSERT_TRUE(p_diff.x == 3.0 && p_diff.y == 6.0 && p_diff.z == -5.5);
}

TEST(TestIsThreePointsOnOneLine, Subtest_1)
{
    Point p1(1.0f, 2.0f, 3.0f);
    Point p2(2.0f, 4.0f, 6.0f);
    Point p3(3.0f, 6.0f, 9.0f);

    bool result = IsThreePointsOnOneLine(p1, p2, p3);

    ASSERT_TRUE(result);
}

TEST(TestIsThreePointsOnOneLine, Subtest_2)
{
    Point p1(1.0f, 1.0f, 1.0f);
    Point p2(2.0f, 2.0f, 2.0f);
    Point p3(3.0f, 3.0f, 3.0f);

    bool result = IsThreePointsOnOneLine(p1, p2, p3);

    ASSERT_TRUE(result);
}

TEST(TestIsThreePointsOnOneLine, Subtest_3)
{
    Point p1(0.0f, 0.0f, 0.0f);
    Point p2(1.0f, 1.0f, 1.0f);
    Point p3(1.0f, 2.0f, 3.0f);

    bool result = IsThreePointsOnOneLine(p1, p2, p3);

    ASSERT_FALSE(result);
}

TEST(TestIsThreePointsOnOneLine, Subtest_4)
{
    Point p1(-1.0f, -1.0f, -1.0f);
    Point p2(0.0f, 0.0f, 0.0f);
    Point p3(1.0f, 1.0f, 1.0f);

    bool result = IsThreePointsOnOneLine(p1, p2, p3);

    ASSERT_TRUE(result);
}

TEST(TestIsThreePointsOnOneLine, Subtest_5)
{
    Point p1(1.0f, 1.0f, 1.0f);
    Point p2(2.0f, 2.0f, 2.0f);
    Point p3(2.0f, 3.0f, 4.0f);

    bool result = IsThreePointsOnOneLine(p1, p2, p3);

    ASSERT_FALSE(result);
}

TEST(TestIsThreePointsOnOneLine, Subtest_6)
{
    Point p1(0.0f, 0.0f, 1.0f);
    Point p2(0.0f, 0.0f, -1.0f);
    Point p3(0.0f, 0.0f, 2.0f);

    bool result = IsThreePointsOnOneLine(p1, p2, p3);

    ASSERT_FALSE(result);
}

TEST(TestPointAssignmentOperator, AssignVectorToPoint)
{
    Vector vector(3.5, -2.5, 4.0);
    Point point;

    point = vector;

    ASSERT_NEAR(point.x, vector.x, 0.0001);
    ASSERT_NEAR(point.y, vector.y, 0.0001);
    ASSERT_NEAR(point.z, vector.z, 0.0001);
}

TEST(TestPointAssignmentOperator, AssignZeroVectorToPoint)
{
    Vector vector(0.0, 0.0, 0.0);
    Point point(1.0, 2.0, 3.0);

    point = vector;

    ASSERT_NEAR(point.x, vector.x, 0.0001);
    ASSERT_NEAR(point.y, vector.y, 0.0001);
    ASSERT_NEAR(point.z, vector.z, 0.0001);
}

TEST(TestPointAssignmentOperator, AssignNegativeVectorToPoint)
{
    Vector vector(-5.0, -1.5, -3.0);
    Point point;

    point = vector;

    ASSERT_NEAR(point.x, vector.x, 0.0001);
    ASSERT_NEAR(point.y, vector.y, 0.0001);
    ASSERT_NEAR(point.z, vector.z, 0.0001);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
