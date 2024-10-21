#include "vector.h"
#include "triangle.h"

#include <unordered_set>
#include <list>
#include <queue>

struct TriangleWithNum
{
    size_t num;
    Triangle3D triangle;
};

class BoundingBox final
{
public:
    Vector3D min;
    Vector3D max;

    BoundingBox() {}
    BoundingBox(const Vector3D& min, const Vector3D& max) : min(min), max(max) {}

    bool contains_triangle(const Triangle3D& triangle);

    bool contains_point(const Point3D& point) const;
};

class OctTree final
{
    std::list<TriangleWithNum> local_triangles;
    BoundingBox boundary;

    OctTree* children_nodes[8];

    const double MIN_OCTANT_SIZE = 1;
public:
    OctTree() {}
    OctTree(const BoundingBox& bounding_box, const std::list<TriangleWithNum>& local_triangles)
    : boundary(bounding_box), local_triangles(local_triangles) {}

    ~OctTree() { for (int i = 0; i < 8; i++) { delete children_nodes[i]; } }

    void BuildTree();

    std::unordered_set<size_t> GetIntersection(std::list<TriangleWithNum>& parent_triangles);
};