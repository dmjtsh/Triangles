#include "vector.h"
#include "triangle.h"
#include "octree.h"

#include <gtest/gtest.h>

//
// Bounding Box Tests
//

TEST(BoundingBoxTest, ContainsPoint_Inside)
{
    BoundingBox box(Vector3D(0, 0, 0), Vector3D(10, 10, 10));

    ASSERT_TRUE(box.contains_point(Point3D(5, 5, 5)));
}

TEST(BoundingBoxTest, ContainsPoint_Outside)
{
    BoundingBox box(Vector3D(0, 0, 0), Vector3D(10, 10, 10));

    ASSERT_FALSE(box.contains_point(Point3D(15, 15, 15)));
}

TEST(BoundingBoxTest, ContainsPoint_OnBoundary)
{
    BoundingBox box(Vector3D(0, 0, 0), Vector3D(10, 10, 10));

    ASSERT_TRUE(box.contains_point(Point3D(0, 0, 0)));
    ASSERT_TRUE(box.contains_point(Point3D(10, 10, 10)));
}

TEST(BoundingBoxTest, ContainsTriangle_Inside)
{
    BoundingBox box(Vector3D(0, 0, 0), Vector3D(10, 10, 10));
    Triangle3D triangle = Triangle3D(Point3D(1, 1, 1), Point3D(2, 2, 2), Point3D(3, 3, 3));

    ASSERT_TRUE(box.contains_triangle(triangle));
}

TEST(BoundingBoxTest, ContainsTriangle_Outside)
{
    BoundingBox box(Vector3D(0, 0, 0), Vector3D(10, 10, 10));
    Triangle3D triangle = Triangle3D(Point3D(5, 5, 5), Point3D(15, 15, 15), Point3D(5, 5, 15));

    ASSERT_FALSE(box.contains_triangle(triangle));
}

TEST(BoundingBoxTest, ContainsTriangle_OnBoundary)
{
    BoundingBox box(Vector3D(0, 0, 0), Vector3D(10, 10, 10));
    Triangle3D triangle = Triangle3D(Point3D(1, 1, 1), Point3D(10, 10, 10), Point3D(10, 5, 5));

    ASSERT_TRUE(box.contains_triangle(triangle));
}

//
// OctTree Tests
//

TEST(OctTreeTest, BuildTree_EmptyTree)
{
    std::list<TriangleWithNum> triangles;

    BoundingBox bounding_box(Vector3D(0, 0, 0), Vector3D(10, 10, 10));
    OctTree octree(bounding_box, triangles);

    octree.BuildTree();
}

TEST(OctTreeTest, BuildTree_SingleTriangle)
{
    std::list<TriangleWithNum> triangles;
    triangles.push_back({0, Triangle3D(Point3D(1, 1, 1), Point3D(2, 2, 2), Point3D(3, 3, 3))});

    BoundingBox bounding_box(Vector3D(0, 0, 0), Vector3D(10, 10, 10));
    OctTree octree(bounding_box, triangles);

    octree.BuildTree();
}

TEST(OctTreeTest, BuildTree_MultipleTriangles)
{
    std::list<TriangleWithNum> triangles;
    triangles.push_back({0, Triangle3D(Point3D(1, 1, 1), Point3D(2, 2, 2), Point3D(3, 3, 3))});
    triangles.push_back({1, Triangle3D(Point3D(5, 5, 5), Point3D(6, 6, 6), Point3D(7, 7, 7))});

    BoundingBox bounding_box(Vector3D(0, 0, 0), Vector3D(10, 10, 10));
    OctTree octree(bounding_box, triangles);

    octree.BuildTree();
}

TEST(OctTreeTest, GetIntersection_NoIntersection)
{
    std::list<TriangleWithNum> parent_triangles;
    parent_triangles.push_back({0, Triangle3D(Point3D(1, 1, 1), Point3D(2, 2, 2), Point3D(3, 3, 3))});

    std::list<TriangleWithNum> local_triangles;
    local_triangles.push_back({1, Triangle3D(Point3D(10, 10, 10), Point3D(11, 11, 11), Point3D(12, 12, 12))}); // Не пересекается

    BoundingBox bounding_box(Vector3D(0, 0, 0), Vector3D(10, 10, 10));
    OctTree octree(bounding_box, local_triangles);

    octree.BuildTree();
    std::unordered_set<size_t> intersections = octree.GetIntersection();

    ASSERT_EQ(intersections.size(), 0);
}

TEST(OctTreeTest, GetIntersection_InvalidTriangle)
{
    std::list<TriangleWithNum> parent_triangles;
    parent_triangles.push_back({0, Triangle3D(Point3D(1, 1, 1), Point3D(2, 2, 2), Point3D(3, 3, 3))});

    std::list<TriangleWithNum> local_triangles;
    local_triangles.push_back({1, Triangle3D(Point3D(1, 1, 1), Point3D(2, 2, 2), Point3D(2, 3, 3))});

    BoundingBox bounding_box(Vector3D(0, 0, 0), Vector3D(10, 10, 10));
    OctTree octree(bounding_box, local_triangles);

    octree.BuildTree();
    std::unordered_set<size_t> intersections = octree.GetIntersection();

    ASSERT_EQ(intersections.size(), 0);
}

TEST(OctTreeTest, GetIntersection_SelfIntersection)
{
    std::list<TriangleWithNum> local_triangles;
    local_triangles.push_back({0, Triangle3D(Point3D(1, 1, 1), Point3D(2, 2, 2), Point3D(2, 3, 3))});
    local_triangles.push_back({1, Triangle3D(Point3D(1, 1, 1), Point3D(2, 2, 2), Point3D(2, 3, 3))});

    BoundingBox bounding_box(Vector3D(0, 0, 0), Vector3D(10, 10, 10));
    OctTree octree(bounding_box, local_triangles);

    octree.BuildTree();
    std::unordered_set<size_t> intersections = octree.GetIntersection();

    ASSERT_EQ(intersections.size(), 2);
}

TEST(OctTreeTest, GetIntersection_MultipleIntersections1)
{
    std::list<TriangleWithNum> local_triangles;
    local_triangles.push_back({0, Triangle3D(Point3D(1, 1, 1), Point3D(2, 2, 2), Point3D(2, 3, 3))});
    local_triangles.push_back({1, Triangle3D(Point3D(1, 1, 1), Point3D(3, 3, 4), Point3D(2, 5, 5))});
    local_triangles.push_back({2, Triangle3D(Point3D(-2, -5, 4), Point3D(7, 8, 9), Point3D(3, 3, 3))});
    local_triangles.push_back({3, Triangle3D(Point3D(2, -5, 4), Point3D(-7, -8, -9), Point3D(-3, -3, -3))});
    local_triangles.push_back({4, Triangle3D(Point3D(-5, 6, 8), Point3D(-7, -8, 9), Point3D(-4, 4, 4))});

    BoundingBox bounding_box(Vector3D(0, 0, 0), Vector3D(10, 10, 10));
    OctTree octree(bounding_box, local_triangles);

    std::unordered_set<size_t> intersections = octree.GetIntersection();

    ASSERT_EQ(intersections.size(), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
