#include <iostream>

#include "vector.h"

#include <gtest/gtest.h>

//
// Vector3D Tests
//

TEST(TestVecPlusCorrectness, Subtest_1)
{
    Vector3D v1(1, 2, 3);
    Vector3D v2(2, 3, 5);

    Vector3D v_sum = v1 + v2;

    ASSERT_NEAR(v_sum.x, 3.0f, 0.0001f);
    ASSERT_NEAR(v_sum.y, 5.0f, 0.0001f);
    ASSERT_NEAR(v_sum.z, 8.0f, 0.0001f);
}

TEST(TestVecPlusCorrectness, Subtest_2)
{
    Vector3D v1(-1, -2, -3);
    Vector3D v2(1, 2, 3);

    Vector3D v_sum = v1 + v2;

    ASSERT_NEAR(v_sum.x, 0.0f, 0.0001f);
    ASSERT_NEAR(v_sum.y, 0.0f, 0.0001f);
    ASSERT_NEAR(v_sum.z, 0.0f, 0.0001f);
}

TEST(TestVecPlusCorrectness, Subtest_3)
{
    Vector3D v1(2.5, 3.5, -1.5);
    Vector3D v2(1.5, -2.5, 4.0);

    Vector3D v_sum = v1 + v2;

    ASSERT_NEAR(v_sum.x, 4.0f, 0.0001f);
    ASSERT_NEAR(v_sum.y, 1.0f, 0.0001f);
    ASSERT_NEAR(v_sum.z, 2.5f, 0.0001f);
}

TEST(TestVecMinusCorrectness, Subtest_1)
{
    Vector3D v1(0, 0, 0);
    Vector3D v2(4, 5, 6);

    Vector3D v_diff = v1 - v2;

    ASSERT_NEAR(v_diff.x, -4.0f, 0.0001f);
    ASSERT_NEAR(v_diff.y, -5.0f, 0.0001f);
    ASSERT_NEAR(v_diff.z, -6.0f, 0.0001f);
}

TEST(TestVecMinusCorrectness, Subtest_2)
{
    Vector3D v1(-1, -2, -3);
    Vector3D v2(-1, -2, -3);

    Vector3D v_diff = v1 - v2;

    ASSERT_NEAR(v_diff.x, 0.0f, 0.0001f);
    ASSERT_NEAR(v_diff.y, 0.0f, 0.0001f);
    ASSERT_NEAR(v_diff.z, 0.0f, 0.0001f);
}

TEST(TestVecMinusCorrectness, Subtest_3)
{
    Vector3D v1(4.5, 3.5, -1.5);
    Vector3D v2(1.5, -2.5, 4.0);

    Vector3D v_diff = v1 - v2;

    ASSERT_NEAR(v_diff.x, 3.0f, 0.0001f);
    ASSERT_NEAR(v_diff.y, 6.0f, 0.0001f);
    ASSERT_NEAR(v_diff.z, -5.5f, 0.0001f);
}

TEST(TestVecMultOnConstCorrectness, Subtest_1)
{
    Vector3D v(1.0f, 2.0f, 3.0f);
    float scalar = 2.0f;

    Vector3D v_scaled = v * scalar;

    ASSERT_NEAR(v_scaled.x, 2.0f, 0.0001f);
    ASSERT_NEAR(v_scaled.y, 4.0f, 0.0001f);
    ASSERT_NEAR(v_scaled.z, 6.0f, 0.0001f);
}

TEST(TestVecMultOnConstCorrectness, Subtest_2)
{
    Vector3D v(4.0f, 5.0f, 6.0f);
    float scalar = 0.0f;

    Vector3D v_scaled = v * scalar;

    ASSERT_NEAR(v_scaled.x, 0.0f, 0.0001f);
    ASSERT_NEAR(v_scaled.y, 0.0f, 0.0001f);
    ASSERT_NEAR(v_scaled.z, 0.0f, 0.0001f);
}

TEST(TestVecMultOnConstCorrectness, Subtest_3)
{
    Vector3D v(-1.0f, -2.0f, -3.0f);
    float scalar = -3.0f;

    Vector3D v_scaled = v * scalar;

    ASSERT_NEAR(v_scaled.x, 3.0f, 0.0001f);
    ASSERT_NEAR(v_scaled.y, 6.0f, 0.0001f);
    ASSERT_NEAR(v_scaled.z, 9.0f, 0.0001f);
}

TEST(TestVectorCrossCorrectness, Subtest_1)
{
    Vector3D v1(1.0f, 0.0f, 0.0f);
    Vector3D v2(0.0f, 1.0f, 0.0f);

    Vector3D v_cross = Cross(v1, v2);

    ASSERT_NEAR(v_cross.x, 0.0f, 0.0001f);
    ASSERT_NEAR(v_cross.y, 0.0f, 0.0001f);
    ASSERT_NEAR(v_cross.z, 1.0f, 0.0001f);
}

TEST(TestVectorCrossCorrectness, Subtest_2)
{
    Vector3D v1(0.0f, 1.0f, 0.0f);
    Vector3D v2(0.0f, 0.0f, 1.0f);

    Vector3D v_cross = Cross(v1, v2);

    ASSERT_NEAR(v_cross.x, 1.0f, 0.0001f);
    ASSERT_NEAR(v_cross.y, 0.0f, 0.0001f);
    ASSERT_NEAR(v_cross.z, 0.0f, 0.0001f);
}

TEST(TestVectorCrossCorrectness, Subtest_3)
{
    Vector3D v1(-1.0f, -2.0f, 0);
    Vector3D v2(-2.0f, 0, 1.0f);

    Vector3D v_cross = Cross(v1, v2);

    ASSERT_NEAR(v_cross.x, -2.0f, 0.0001f);
    ASSERT_NEAR(v_cross.y,  1.0f, 0.0001f);
    ASSERT_NEAR(v_cross.z, -4.0f, 0.0001f);
}

TEST(TestVectorDotCorrectness, Subtest_1)
{
    Vector3D v1(1.0f, 0.0f, 0.0f);
    Vector3D v2(0.0f, 1.0f, 0.0f);

    float dot_product = Dot(v1, v2);

    ASSERT_NEAR(dot_product, 0.0f, 0.0001f);
}

TEST(TestVectorDotCorrectness, Subtest_2)
{
    Vector3D v1(1.0f, 2.0f, 3.0f);
    Vector3D v2(4.0f, 5.0f, 6.0f);

    float dot_product = Dot(v1, v2);

    ASSERT_NEAR(dot_product, 32.0f, 0.0001f);
}

TEST(TestVectorDotCorrectness, Subtest_3)
{
    Vector3D v1(-1.0f, 4.0f, -2.0f);
    Vector3D v2(2.0f, -3.0f, 1.0f);

    float dot_product = Dot(v1, v2);

    ASSERT_NEAR(dot_product, -16.0f, 0.0001f);
}

TEST(TestVectorAssignmentOperator, AssignPointToVector)
{
    Point3D point(3.5, -2.5, 4.0);
    Vector3D vector;

    vector = point;

    ASSERT_NEAR(vector.x, point.x, 0.0001);
    ASSERT_NEAR(vector.y, point.y, 0.0001);
    ASSERT_NEAR(vector.z, point.z, 0.0001);
}

TEST(TestVectorAssignmentOperator, AssignZeroPointToVector)
{
    Point3D point(0.0, 0.0, 0.0);
    Vector3D vector(1.0, -2.0, 3.0);

    vector = point;

    ASSERT_NEAR(vector.x, point.x, 0.0001);
    ASSERT_NEAR(vector.y, point.y, 0.0001);
    ASSERT_NEAR(vector.z, point.z, 0.0001);
}

TEST(TestVectorAssignmentOperator, AssignNegativePointToVector)
{
    Point3D point(-5.0, -1.5, -3.0);
    Vector3D vector;

    vector = point;

    ASSERT_NEAR(vector.x, point.x, 0.0001);
    ASSERT_NEAR(vector.y, point.y, 0.0001);
    ASSERT_NEAR(vector.z, point.z, 0.0001);
}

//
// Vector2D Tests
//

TEST(TestVecPlusCorrectness2D, Subtest_1)
{
    Vector2D v1(1.0f, 2.0f);
    Vector2D v2(2.0f, 3.0f);

    Vector2D v_sum = v1 + v2;

    ASSERT_NEAR(v_sum.x, 3.0f, 0.0001f);
    ASSERT_NEAR(v_sum.y, 5.0f, 0.0001f);
}

TEST(TestVecPlusCorrectness2D, Subtest_2)
{
    Vector2D v1(-1.0f, -2.0f);
    Vector2D v2(1.0f, 2.0f);

    Vector2D v_sum = v1 + v2;

    ASSERT_NEAR(v_sum.x, 0.0f, 0.0001f);
    ASSERT_NEAR(v_sum.y, 0.0f, 0.0001f);
}

TEST(TestVecPlusCorrectness2D, Subtest_3)
{
    Vector2D v1(2.5f, 3.5f);
    Vector2D v2(1.5f, -2.5f);

    Vector2D v_sum = v1 + v2;

    ASSERT_NEAR(v_sum.x, 4.0f, 0.0001f);
    ASSERT_NEAR(v_sum.y, 1.0f, 0.0001f);
}

TEST(TestVecMinusCorrectness2D, Subtest_1)
{
    Vector2D v1(0.0f, 0.0f);
    Vector2D v2(4.0f, 5.0f);

    Vector2D v_diff = v1 - v2;

    ASSERT_NEAR(v_diff.x, -4.0f, 0.0001f);
    ASSERT_NEAR(v_diff.y, -5.0f, 0.0001f);
}

TEST(TestVecMinusCorrectness2D, Subtest_2)
{
    Vector2D v1(-1.0f, -2.0f);
    Vector2D v2(-1.0f, -2.0f);

    Vector2D v_diff = v1 - v2;

    ASSERT_NEAR(v_diff.x, 0.0f, 0.0001f);
    ASSERT_NEAR(v_diff.y, 0.0f, 0.0001f);
}

TEST(TestVecMinusCorrectness2D, Subtest_3)
{
    Vector2D v1(4.5f, 3.5f);
    Vector2D v2(1.5f, -2.5f);

    Vector2D v_diff = v1 - v2;

    ASSERT_NEAR(v_diff.x, 3.0f, 0.0001f);
    ASSERT_NEAR(v_diff.y, 6.0f, 0.0001f);
}

TEST(TestVecMultOnConstCorrectness2D, Subtest_1)
{
    Vector2D v(1.0f, 2.0f);
    float scalar = 2.0f;

    Vector2D v_scaled = v * scalar;

    ASSERT_NEAR(v_scaled.x, 2.0f, 0.0001f);
    ASSERT_NEAR(v_scaled.y, 4.0f, 0.0001f);
}

TEST(TestVecMultOnConstCorrectness2D, Subtest_2)
{
    Vector2D v(4.0f, 5.0f);
    float scalar = 0.0f;

    Vector2D v_scaled = v * scalar;

    ASSERT_NEAR(v_scaled.x, 0.0f, 0.0001f);
    ASSERT_NEAR(v_scaled.y, 0.0f, 0.0001f);
}

TEST(TestVecMultOnConstCorrectness2D, Subtest_3)
{
    Vector2D v(-1.0f, -2.0f);
    float scalar = -3.0f;

    Vector2D v_scaled = v * scalar;

    ASSERT_NEAR(v_scaled.x, 3.0f, 0.0001f);
    ASSERT_NEAR(v_scaled.y, 6.0f, 0.0001f);
}

TEST(TestVectorDotCorrectness2D, Subtest_1)
{
    Vector2D v1(1.0f, 0.0f);
    Vector2D v2(0.0f, 1.0f);

    float dot_product = Dot(v1, v2);

    ASSERT_NEAR(dot_product, 0.0f, 0.0001f);
}

TEST(TestVectorDotCorrectness2D, Subtest_2)
{
    Vector2D v1(1.0f, 2.0f);
    Vector2D v2(3.0f, 4.0f);

    float dot_product = Dot(v1, v2);

    ASSERT_NEAR(dot_product, 11.0f, 0.0001f);
}

TEST(TestVectorDotCorrectness2D, Subtest_3)
{
    Vector2D v1(-1.0f, 4.0f);
    Vector2D v2(2.0f, -3.0f);

    float dot_product = Dot(v1, v2);

    ASSERT_NEAR(dot_product, -14.0f, 0.0001f);
}

TEST(TestVectorAssignmentOperator2D, AssignPointToVector)
{
    Point2D point(3.5f, -2.5f);
    Vector2D vector;

    vector = point;

    ASSERT_NEAR(vector.x, point.x, 0.0001f);
    ASSERT_NEAR(vector.y, point.y, 0.0001f);
}

TEST(TestVectorAssignmentOperator2D, AssignZeroPointToVector)
{
    Point2D point(0.0f, 0.0f);
    Vector2D vector(1.0f, -2.0f);

    vector = point;

    ASSERT_NEAR(vector.x, point.x, 0.0001f);
    ASSERT_NEAR(vector.y, point.y, 0.0001f);
}

TEST(TestVectorAssignmentOperator2D, AssignNegativePointToVector)
{
    Point2D point(-5.0f, -1.5f);
    Vector2D vector;

    vector = point;

    ASSERT_NEAR(vector.x, point.x, 0.0001f);
    ASSERT_NEAR(vector.y, point.y, 0.0001f);
}

TEST(TestCrossProduct, CrossOfNonZeroVectors)
{
    Vector2D v1(3.0f, 2.0f);
    Vector2D v2(1.0f, 4.0f);

    float result = Cross(v1, v2);
    ASSERT_NEAR(result, 10.0f, 1e-5); // 3*4 - 2*1 = 12 - 2 = 10
}

TEST(TestCrossProduct, CrossOfZeroVector)
{
    Vector2D v1(0.0f, 0.0f);
    Vector2D v2(1.0f, 1.0f);
    float result = Cross(v1, v2);
    ASSERT_NEAR(result, 0.0f, 1e-5); // 0*1 - 0*1 = 0
}

TEST(TestCrossProduct, CrossOfOrthogonalVectors)
{
    Vector2D v1(1.0f, 0.0f);
    Vector2D v2(0.0f, 1.0f);
    float result = Cross(v1, v2);
    ASSERT_NEAR(result, 1.0f, 1e-5); // 1*1 - 0*0 = 1
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
