#include "octree.h"

bool BoundingBox::contains_triangle(const Triangle3D& triangle)
{
    return contains_point(triangle.point0) &&
           contains_point(triangle.point1) &&
           contains_point(triangle.point2);
}
bool BoundingBox::contains_point(const Point3D& point) const
{
    return (point.x >= min.x && point.x <= max.x) &&
           (point.y >= min.y && point.y <= max.y) &&
           (point.z >= min.z && point.z <= max.z);
}

OctTree::OctTree()
{
    for (int i = 0; i < 8; i++)
    {
        children_nodes[i] = nullptr;
    }
}

OctTree::OctTree(const BoundingBox& bounding_box, const std::list<TriangleWithNum>& local_triangles)
: boundary(bounding_box), local_triangles(local_triangles)
{
    for (int i = 0; i < 8; i++)
    {
        children_nodes[i] = nullptr;
    }
}

OctTree::~OctTree()
{
    for (int i = 0; i < 8; i++)
    {
        delete children_nodes[i];
    }
}

void OctTree::BuildTree()
{
    if(local_triangles.size() <= 1)
        return;

    Vector3D boundary_size = boundary.max - boundary.min;
    if(boundary_size.x <= MIN_OCTANT_SIZE && boundary_size.y <= MIN_OCTANT_SIZE
    && boundary_size.z <= MIN_OCTANT_SIZE)
        return;

    Vector3D half  = boundary_size * 0.5;
    Vector3D center = boundary.min + half;

    BoundingBox octant[8];
    octant[0] = BoundingBox(boundary.min, center);
    octant[1] = BoundingBox(Vector3D(center.x, boundary.min.y, boundary.min.z),
                            Vector3D(boundary.max.x, center.y, center.z));
    octant[2] = BoundingBox(Vector3D(center.x, boundary.min.y, center.z),
                            Vector3D(boundary.max.x, center.y, boundary.max.z));
    octant[3] = BoundingBox(Vector3D(boundary.min.x, boundary.min.y, center.z),
                            Vector3D(center.x, center.y, boundary.max.z));
    octant[4] = BoundingBox(Vector3D(boundary.min.x, center.y, boundary.min.z),
                            Vector3D(center.x, boundary.max.y, center.z));
    octant[5] = BoundingBox(Vector3D(center.x, center.y, boundary.min.z),
                            Vector3D(boundary.max.x, boundary.max.y, center.z));
    octant[6] = BoundingBox(center, boundary.max);
    octant[7] = BoundingBox(Vector3D(boundary.min.x, center.y, center.z),
                            Vector3D(center.x, boundary.max.y, boundary.max.z));

    std::list<TriangleWithNum> oct_lists[8];
    for (auto local_triangle = local_triangles.begin(); local_triangle != local_triangles.end(); ++local_triangle)
    {
        if(local_triangle->triangle.valid())
        {
            for (int i = 0 ; i < 8; i ++)
            {
                if(octant[i].contains_triangle(local_triangle->triangle))
                {
                    oct_lists[i].push_back(*local_triangle);
                    local_triangles.erase(local_triangle);
                    i--;

                    break;
                }
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        if (oct_lists[i].size() != 0)
        {
            children_nodes[i] = new OctTree(octant[i], oct_lists[i]);
            children_nodes[i]->BuildTree();
        }
    }
}

std::unordered_set<size_t> OctTree::GetIntersection(std::list<TriangleWithNum>& parent_triangles)
{
    std::unordered_set<size_t> intersections;

    for (auto parent_triangle = parent_triangles.begin(); parent_triangle != parent_triangles.end(); ++parent_triangle)
    {
        for (auto local_triangle = local_triangles.begin(); local_triangle != local_triangles.end(); ++local_triangle)
        {
            if(CheckTrianglesIntersection(parent_triangle->triangle, local_triangle->triangle))
            {
                intersections.insert(local_triangle->num);
                intersections.insert(parent_triangle->num);
            }
        }
    }

    for (auto local_triangle = local_triangles.begin(); local_triangle != local_triangles.end(); ++local_triangle)
    {
        for(auto tmp = std::next(local_triangle); tmp != local_triangles.end(); tmp++)
        {
            if(CheckTrianglesIntersection(local_triangle->triangle, tmp->triangle))
            {
                intersections.insert(local_triangle->num);
                intersections.insert(tmp->num);
            }
        }
    }

    parent_triangles.insert(parent_triangles.end(), local_triangles.begin(), local_triangles.end());

    for(int i = 0; i < 8; i++)
    {
        if(children_nodes[i] && children_nodes[i]->local_triangles.size() > 0)
        {
            std::unordered_set<size_t> new_intersections = GetIntersection(parent_triangles);
            intersections.insert(new_intersections.begin(), new_intersections.end());
        }
    }

    return intersections;
}

std::unordered_set<size_t> OctTree::GetIntersection()
{
    std::list<TriangleWithNum> parent_triangles;
    return GetIntersection(parent_triangles);
}
