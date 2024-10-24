#include <iostream>

#include "line.h"
#include "plane.h"
#include "triangle.h"

#include <gtest/gtest.h>

TEST(TestPlaneConstructorCorrectness, Subtest_1)
{
    Triangle3D triangle{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    Plane3D plane{triangle};

    Vector3D needed_normal{0.577350269, 0.577350269, 0.577350269};
    double needed_distance = - (needed_normal.x * 1 + needed_normal.y * 0 + needed_normal.z * 0);

    ASSERT_NEAR(plane.distance, needed_distance, 0.00001);
    ASSERT_TRUE(plane.normal.equal(needed_normal));
}

TEST(TestPlaneConstructorCorrectness, Subtest_2)
{
    Triangle3D triangle{{1, 1, 1}, {2, 3, 1}, {3, 1, 2}};
    Plane3D plane{triangle};

    Vector3D needed_normal{0.4364357804, -0.218217890, -0.872871560};
    double needed_distance = - (needed_normal.x * 1 + needed_normal.y * 1 + needed_normal.z * 1);

    ASSERT_NEAR(plane.distance, needed_distance, 0.00001);
    ASSERT_TRUE(plane.normal.equal(needed_normal));
}

TEST(TestPlaneConstructorCorrectness, Subtest_3)
{
    Triangle3D triangle{{1, 0, 0}, {1, 0, 1}, {1, 1, 0}};
    Plane3D plane{triangle};

    Vector3D needed_normal{1.0, 0.0, 0.0};
    double needed_distance = - (needed_normal.x * 1 + needed_normal.y * 0 + needed_normal.z * 0);

    ASSERT_NEAR(plane.distance, needed_distance, 0.00001);
    ASSERT_TRUE(plane.normal.equal(needed_normal));
}

TEST(TestPlaneConstructorCorrectness, Subtest_4)
{
    Triangle3D triangle{{0, 0, 0}, {1, 1, 1}, {2, 0, 2}};
    Plane3D plane{triangle};

    Vector3D needed_normal{0.7071067811, 0.0, -0.7071067811};
    double needed_distance = - (needed_normal.x * 0 + needed_normal.y * 0 + needed_normal.z * 0);

    ASSERT_NEAR(plane.distance, needed_distance, 0.00001);
    ASSERT_TRUE(plane.normal.equal(needed_normal));
}

TEST(TestIntersectionOfPlanes, Subtest_1_PlanesIntersect)
{
    Plane3D plane1{{1, 0, 0}, 1};
    Plane3D plane2{{0, 1, 0}, 2};
    Line3D line;

    line = GetIntersectionLineOfPlanes(plane1, plane2);

    Vector3D expected_distance{0, 0, 1};
    Point3D expected_point{-1, -2, 0};

    ASSERT_TRUE(line.distance.equal(expected_distance));

    ASSERT_NEAR(line.point.x, expected_point.x, 0.00001);
    ASSERT_NEAR(line.point.y, expected_point.y, 0.00001);
    ASSERT_NEAR(line.point.z, expected_point.z, 0.00001);
}

TEST(TestIntersectionOfPlanes, Subtest_4_GeneralCase)
{
    Plane3D plane1{{1, 2, -1}, 3};
    Plane3D plane2{{-1, 0, 1}, -4};
    Line3D line;

    line = GetIntersectionLineOfPlanes(plane1, plane2);

    Vector3D expected_distance = Cross(plane1.normal, plane2.normal);
    Point3D expected_point{-2, 0.5, 2};

    ASSERT_TRUE(line.distance.equal(expected_distance));

    ASSERT_NEAR(line.point.x, expected_point.x, 0.00001);
    ASSERT_NEAR(line.point.y, expected_point.y, 0.00001);
    ASSERT_NEAR(line.point.z, expected_point.z, 0.00001);
}

TEST(TestGetDistBetweenPlaneAndPoint, PointAbovePlane) {
    Plane3D plane{{0, 0, 1}, -5};
    Point3D point{0, 0, 6};

    double distance = GetSignDistBetweenPlaneAndPoint(plane, point);

    ASSERT_NEAR(distance, 1.0, 0.0001);
}

TEST(TestGetDistBetweenPlaneAndPoint, PointBelowPlane) {
    Plane3D plane{{0, 0, 1}, -5};
    Point3D point{0, 0, 4};

    double distance = GetSignDistBetweenPlaneAndPoint(plane, point);

    ASSERT_NEAR(distance, -1.0, 0.0001);
}

TEST(TestGetDistBetweenPlaneAndPoint, PointOnPlane) {
    Plane3D plane{{0, 0, 1}, -5};
    Point3D point{0, 0, 5};

    double distance = GetSignDistBetweenPlaneAndPoint(plane, point);

    ASSERT_NEAR(distance, 0.0, 0.0001);
}

TEST(TestGetDistBetweenPlaneAndPoint, ArbitraryPointAndPlane) {
    Plane3D plane{{1, -1, 2}, -3};
    Point3D point{4, 3, -2};

    double distance = GetSignDistBetweenPlaneAndPoint(plane, point);

    double expected_distance = (1*4 - 1*3 + 2*(-2) - 3) / std::sqrt(1*1 + (-1)*(-1) + 2*2);
    ASSERT_NEAR(distance, expected_distance, 0.0001);
}

TEST(PlaneTests, EqualPlanesTest) {
    Plane3D plane1{{1.0, 2.0, 3.0}, -4.0};
    Plane3D plane2{{2.0, 4.0, 6.0}, -8.0};

    ASSERT_TRUE(plane1.equal(plane2));

    Plane3D plane3{{1.0, 2.0, 3.0}, -5.0};

    ASSERT_FALSE(plane1.equal(plane3));

    Plane3D plane4{{1.0, -2.0, 3.0}, -4.0};

    ASSERT_FALSE(plane1.equal(plane4));
}

TEST(PlaneTests, ParallelPlanesTest) {
    Plane3D plane1{{1.0, 2.0, 3.0}, -4.0};
    Plane3D plane2{{2.0, 4.0, 6.0}, -10.0};

    ASSERT_TRUE(plane1.parallel(plane2));
    ASSERT_FALSE(plane1.equal(plane2));

    Plane3D plane3{{1.0, 2.0, 3.0}, -4.0};
    Plane3D plane4{{2.0, 4.0, 6.0}, -8.0};

    ASSERT_TRUE(plane3.parallel(plane4));
    ASSERT_TRUE(plane3.equal(plane4));

    Plane3D plane5{{1.0, 0.0, 0.0}, -4.0};
    Plane3D plane6{{0.0, 1.0, 0.0}, -4.0};

    ASSERT_FALSE(plane5.parallel(plane6));
    ASSERT_FALSE(plane5.equal(plane6));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
