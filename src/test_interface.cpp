#include "octree.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <set>

std::set<size_t> GetIntersectingTrianglesNums(std::istream& input)
{
    size_t N = 0;

    if(!(input >> N))
        throw std::invalid_argument("Invalid input for numbers of triangles.");

    std::list<TriangleWithNum> triangles;

    Point3D min_point, max_point;

    for (size_t i = 0; i < N; ++i)
    {
        Point3D p1, p2, p3;

        if(!(input >> p1.x >> p1.y >> p1.z))
            throw std::invalid_argument("Invalid input for triangles coord.");

        if(!(input >> p2.x >> p2.y >> p2.z))
            throw std::invalid_argument("Invalid input for triangles coord.");

        if(!(input >> p3.x >> p3.y >> p3.z))
            throw std::invalid_argument("Invalid input for triangles coord.");

        min_point.x = std::min(min_point.x, std::min({p1.x, p2.x, p3.x}));
        min_point.y = std::min(min_point.x, std::min({p1.y, p2.y, p3.y}));
        min_point.z = std::min(min_point.x, std::min({p1.z, p2.z, p3.z}));

        max_point.x = std::max(min_point.x, std::max({p1.x, p2.x, p3.x}));
        max_point.y = std::max(min_point.x, std::max({p1.y, p2.y, p3.y}));
        max_point.z = std::max(min_point.x, std::max({p1.z, p2.z, p3.z}));

        Triangle3D triangle{p1, p2, p3};

        triangles.push_back({i, triangle});
    }

    BoundingBox initial_box(min_point, max_point);
    OctTree octree(initial_box, triangles);

    octree.build_tree();

    std::unordered_set<size_t> intersecting_triangles = octree.get_intersection();
    std::set<size_t> intersecting_triangles_sorted(intersecting_triangles.begin(), intersecting_triangles.end());

    for (const auto& num : intersecting_triangles_sorted)
    {
        std::cout << num << std::endl;
    }


    return intersecting_triangles_sorted;
}
