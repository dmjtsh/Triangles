#include <iostream>

#include "vector.h"

#include <gtest/gtest.h>

TEST(TestVecPlusCorrectness, Subtest_1)
{
    Vector v1(1, 2, 3);
    Vector v2(2, 3, 5);

    Vector v_sum = v1+v2;

    ASSERT_TRUE(v_sum.x == 3 && v_sum.y == 5 && v_sum.z == 8);
}

TEST(TestVecPlusCorrectness, Subtest_2)
{
    Vector v1(-1, -2, -3);
    Vector v2(1, 2, 3);

    Vector v_sum = v1 + v2;

    ASSERT_TRUE(v_sum.x == 0 && v_sum.y == 0 && v_sum.z == 0);
}

TEST(TestVecPlusCorrectness, Subtest_3)
{
    Vector v1(2.5, 3.5, -1.5);
    Vector v2(1.5, -2.5, 4.0);

    Vector v_sum = v1 + v2;

    ASSERT_TRUE(v_sum.x == 4.0 && v_sum.y == 1.0 && v_sum.z == 2.5);
}

TEST(TestVecMinusCorrectness, Subtest_1)
{
    Vector v1(0, 0, 0);
    Vector v2(4, 5, 6);

    Vector v_diff = v1 - v2;

    ASSERT_TRUE(v_diff.x == -4 && v_diff.y == -5 && v_diff.z == -6);
}

TEST(TestVecMinusCorrectness, Subtest_2)
{
    Vector v1(-1, -2, -3);
    Vector v2(-1, -2, -3);

    Vector v_diff = v1 - v2;

    ASSERT_TRUE(v_diff.x == 0 && v_diff.y == 0 && v_diff.z == 0);
}

TEST(TestVecMinusCorrectness, Subtest_3)
{
    Vector v1(4.5, 3.5, -1.5);
    Vector v2(1.5, -2.5, 4.0);

    Vector v_diff = v1 - v2;

    ASSERT_TRUE(v_diff.x == 3.0 && v_diff.y == 6.0 && v_diff.z == -5.5);
}

TEST(TestVecMultOnConstCorrectness, Subtest_1)
{
    Vector v(1.0f, 2.0f, 3.0f);
    float scalar = 2.0f;

    Vector v_scaled = v * scalar;

    ASSERT_NEAR(v_scaled.x, 2.0f, 0.0001f);
    ASSERT_NEAR(v_scaled.y, 4.0f, 0.0001f);
    ASSERT_NEAR(v_scaled.z, 6.0f, 0.0001f);
}

TEST(TestVecMultOnConstCorrectness, Subtest_2)
{
    Vector v(4.0f, 5.0f, 6.0f);
    float scalar = 0.0f;

    Vector v_scaled = v * scalar;

    ASSERT_NEAR(v_scaled.x, 0.0f, 0.0001f);
    ASSERT_NEAR(v_scaled.y, 0.0f, 0.0001f);
    ASSERT_NEAR(v_scaled.z, 0.0f, 0.0001f);
}

TEST(TestVecMultOnConstCorrectness, Subtest_3)
{
    Vector v(-1.0f, -2.0f, -3.0f);
    float scalar = -3.0f;

    Vector v_scaled = v * scalar;

    ASSERT_NEAR(v_scaled.x, 3.0f, 0.0001f);
    ASSERT_NEAR(v_scaled.y, 6.0f, 0.0001f);
    ASSERT_NEAR(v_scaled.z, 9.0f, 0.0001f);
}

TEST(TestVectorCrossCorrectness, Subtest_1)
{
    Vector v1(1.0f, 0.0f, 0.0f);
    Vector v2(0.0f, 1.0f, 0.0f);

    Vector v_cross = Cross(v1, v2);

    ASSERT_NEAR(v_cross.x, 0.0f, 0.0001f);
    ASSERT_NEAR(v_cross.y, 0.0f, 0.0001f);
    ASSERT_NEAR(v_cross.z, 1.0f, 0.0001f);
}

TEST(TestVectorCrossCorrectness, Subtest_2)
{
    Vector v1(0.0f, 1.0f, 0.0f);
    Vector v2(0.0f, 0.0f, 1.0f);

    Vector v_cross = Cross(v1, v2);

    ASSERT_NEAR(v_cross.x, 1.0f, 0.0001f);
    ASSERT_NEAR(v_cross.y, 0.0f, 0.0001f);
    ASSERT_NEAR(v_cross.z, 0.0f, 0.0001f);
}

TEST(TestVectorCrossCorrectness, Subtest_3)
{
    Vector v1(-1.0f, -2.0f, 0);
    Vector v2(-2.0f, 0, 1.0f);

    Vector v_cross = Cross(v1, v2);

    ASSERT_NEAR(v_cross.x, -2.0f, 0.0001f);
    ASSERT_NEAR(v_cross.y,  1.0f, 0.0001f);
    ASSERT_NEAR(v_cross.z, -4.0f, 0.0001f);
}

TEST(TestVectorDotCorrectness, Subtest_1)
{
    Vector v1(1.0f, 0.0f, 0.0f);
    Vector v2(0.0f, 1.0f, 0.0f);

    float dot_product = Dot(v1, v2);

    ASSERT_NEAR(dot_product, 0.0f, 0.0001f);
}

TEST(TestVectorDotCorrectness, Subtest_2)
{
    Vector v1(1.0f, 2.0f, 3.0f);
    Vector v2(4.0f, 5.0f, 6.0f);

    float dot_product = Dot(v1, v2);

    ASSERT_NEAR(dot_product, 32.0f, 0.0001f);
}

TEST(TestVectorDotCorrectness, Subtest_3)
{
    Vector v1(-1.0f, 4.0f, -2.0f);
    Vector v2(2.0f, -3.0f, 1.0f);

    float dot_product = Dot(v1, v2);

    ASSERT_NEAR(dot_product, -16.0f, 0.0001f);
}

TEST(TestVectorAssignmentOperator, AssignPointToVector)
{
    Point point(3.5, -2.5, 4.0);
    Vector vector;

    vector = point;

    ASSERT_NEAR(vector.x, point.x, 0.0001);
    ASSERT_NEAR(vector.y, point.y, 0.0001);
    ASSERT_NEAR(vector.z, point.z, 0.0001);
}

TEST(TestVectorAssignmentOperator, AssignZeroPointToVector)
{
    Point point(0.0, 0.0, 0.0);
    Vector vector(1.0, -2.0, 3.0);

    vector = point;

    ASSERT_NEAR(vector.x, point.x, 0.0001);
    ASSERT_NEAR(vector.y, point.y, 0.0001);
    ASSERT_NEAR(vector.z, point.z, 0.0001);
}

TEST(TestVectorAssignmentOperator, AssignNegativePointToVector)
{
    Point point(-5.0, -1.5, -3.0);
    Vector vector;

    vector = point;

    ASSERT_NEAR(vector.x, point.x, 0.0001);
    ASSERT_NEAR(vector.y, point.y, 0.0001);
    ASSERT_NEAR(vector.z, point.z, 0.0001);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
