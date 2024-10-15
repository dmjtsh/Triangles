#include <iostream>

#include "line.h"
#include "plane.h"
#include "triangle.h"

#include <gtest/gtest.h>

TEST(TestPlaneConstructorCorrectness, Subtest_1)
{
    Triangle triangle{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    Plane plane{triangle};

    Vector needed_normal{1.0f, 1.0f, 1.0f};
    float needed_distance = - (needed_normal.x * 1 + needed_normal.y * 0 + needed_normal.z * 0);

    ASSERT_NEAR(plane.distance, needed_distance, 0.0001f);
    ASSERT_TRUE(plane.normal.equal(needed_normal));
}

TEST(TestPlaneConstructorCorrectness, Subtest_2)
{
    Triangle triangle{{1, 1, 1}, {2, 3, 1}, {3, 1, 2}};
    Plane plane{triangle};

    Vector needed_normal{2.0f, -1.0f, -4.0f};
    float needed_distance = - (needed_normal.x * 1 + needed_normal.y * 1 + needed_normal.z * 1);

    ASSERT_NEAR(plane.distance, needed_distance, 0.0001f);
    ASSERT_TRUE(plane.normal.equal(needed_normal));
}

TEST(TestPlaneConstructorCorrectness, Subtest_3)
{
    Triangle triangle{{1, 0, 0}, {1, 0, 1}, {1, 1, 0}};
    Plane plane{triangle};

    Vector needed_normal{-1.0f, 0.0f, 0.0f};
    float needed_distance = - (needed_normal.x * 1 + needed_normal.y * 0 + needed_normal.z * 0);

    ASSERT_NEAR(plane.distance, needed_distance, 0.0001f);
    ASSERT_TRUE(plane.normal.equal(needed_normal));
}

TEST(TestPlaneConstructorCorrectness, Subtest_4)
{
    Triangle triangle{{0, 0, 0}, {1, 1, 1}, {2, 0, 2}};
    Plane plane{triangle};

    Vector needed_normal{2.0f, 0.0f, -2.0f};
    float needed_distance = - (needed_normal.x * 0 + needed_normal.y * 0 + needed_normal.z * 0);

    ASSERT_NEAR(plane.distance, needed_distance, 0.0001f);
    ASSERT_TRUE(plane.normal.equal(needed_normal));
}

TEST(TestIntersectionOfPlanes, Subtest_1_PlanesIntersect)
{
    Plane plane1{{1, 0, 0}, 1};
    Plane plane2{{0, 1, 0}, 2};
    Line line;

    line = GetIntersectionLineOfPlanes(plane1, plane2);

    Vector expected_distance{0, 0, 1};
    Point expected_point{-1, -2, 0};

    ASSERT_TRUE(line.distance.equal(expected_distance));

    ASSERT_NEAR(line.point.x, expected_point.x, 0.0001f);
    ASSERT_NEAR(line.point.y, expected_point.y, 0.0001f);
    ASSERT_NEAR(line.point.z, expected_point.z, 0.0001f);
}

TEST(TestIntersectionOfPlanes, Subtest_4_GeneralCase)
{
    Plane plane1{{1, 2, -1}, 3};
    Plane plane2{{-1, 0, 1}, -4};
    Line line;

    line = GetIntersectionLineOfPlanes(plane1, plane2);

    Vector expected_distance = Cross(plane1.normal, plane2.normal);
    Point expected_point{-2, 0.5, 2};

    ASSERT_TRUE(line.distance.equal(expected_distance));

    ASSERT_NEAR(line.point.x, expected_point.x, 0.0001f);
    ASSERT_NEAR(line.point.y, expected_point.y, 0.0001f);
    ASSERT_NEAR(line.point.z, expected_point.z, 0.0001f);
}

TEST(TestGetDistBetweenPlaneAndPoint, PointAbovePlane) {
    Plane plane{{0, 0, 1}, -5};
    Point point{0, 0, 6};

    float distance = GetSignDistBetweenPlaneAndPoint(plane, point);

    ASSERT_NEAR(distance, 1.0, 0.0001);
}

TEST(TestGetDistBetweenPlaneAndPoint, PointBelowPlane) {
    Plane plane{{0, 0, 1}, -5};
    Point point{0, 0, 4};

    float distance = GetSignDistBetweenPlaneAndPoint(plane, point);

    ASSERT_NEAR(distance, -1.0, 0.0001);
}

TEST(TestGetDistBetweenPlaneAndPoint, PointOnPlane) {
    Plane plane{{0, 0, 1}, -5};
    Point point{0, 0, 5};

    float distance = GetSignDistBetweenPlaneAndPoint(plane, point);

    ASSERT_NEAR(distance, 0.0, 0.0001);
}

TEST(TestGetDistBetweenPlaneAndPoint, ArbitraryPointAndPlane) {
    Plane plane{{1, -1, 2}, -3};
    Point point{4, 3, -2};

    float distance = GetSignDistBetweenPlaneAndPoint(plane, point);

    float expected_distance = (1*4 - 1*3 + 2*(-2) - 3) / std::sqrt(1*1 + (-1)*(-1) + 2*2);
    ASSERT_NEAR(distance, expected_distance, 0.0001);
}

TEST(PlaneTests, EqualPlanesTest) {
    Plane plane1{{1.0f, 2.0f, 3.0f}, -4.0f};
    Plane plane2{{2.0f, 4.0f, 6.0f}, -8.0f};

    ASSERT_TRUE(plane1.equal(plane2));

    Plane plane3{{1.0f, 2.0f, 3.0f}, -5.0f};

    ASSERT_FALSE(plane1.equal(plane3));

    Plane plane4{{1.0f, -2.0f, 3.0f}, -4.0f};

    ASSERT_FALSE(plane1.equal(plane4));
}

TEST(PlaneTests, ParallelPlanesTest) {
    Plane plane1{{1.0f, 2.0f, 3.0f}, -4.0f};
    Plane plane2{{2.0f, 4.0f, 6.0f}, -10.0f};

    ASSERT_TRUE(plane1.parallel(plane2));
    ASSERT_FALSE(plane1.equal(plane2));

    Plane plane3{{1.0f, 2.0f, 3.0f}, -4.0f};
    Plane plane4{{2.0f, 4.0f, 6.0f}, -8.0f};

    ASSERT_TRUE(plane3.parallel(plane4));
    ASSERT_TRUE(plane3.equal(plane4));

    Plane plane5{{1.0f, 0.0f, 0.0f}, -4.0f};
    Plane plane6{{0.0f, 1.0f, 0.0f}, -4.0f};

    ASSERT_FALSE(plane5.parallel(plane6));
    ASSERT_FALSE(plane5.equal(plane6));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
