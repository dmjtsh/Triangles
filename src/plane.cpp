#include "plane.h"
#include "triangle.h"
#include "line.h"
#include "utilities.h"

#include <cmath>

Plane3D::Plane3D(const Triangle3D& triangle)
{
    Vector3D a_b(triangle.point0, triangle.point1);
    Vector3D a_c(triangle.point0, triangle.point2);

    normal = Cross(a_b, a_c);

    distance = -normal.x * triangle.point0.x - normal.y * triangle.point0.y
              - normal.z * triangle.point0.z;
}

bool CheckEqualOrZero(float ratio_a, float ratio_b)
{
    if (CheckFloatsEqual(ratio_a, 0.0f) || CheckFloatsEqual(ratio_b, 0.0f)
       || std::isnan(ratio_a) || std::isnan(ratio_b))
    {
        return true;
    }
    else if (!CheckFloatsEqual(ratio_a, 0.0f) && !CheckFloatsEqual(ratio_b, 0.0f))
    {
        return CheckFloatsEqual(ratio_a, ratio_b);
    }

    return false;
}

bool Plane3D::equal(const Plane3D& another_plane) const
{

    float ratio_a = normal.x / another_plane.normal.x;
    float ratio_b = normal.y / another_plane.normal.y;
    float ratio_c = normal.z / another_plane.normal.z;
    float ratio_d = distance / another_plane.distance;

    return CheckEqualOrZero(ratio_a, ratio_b) && CheckEqualOrZero(ratio_a, ratio_c)
        && CheckEqualOrZero(ratio_a, ratio_d) && CheckEqualOrZero(ratio_b, ratio_c)
        && CheckEqualOrZero(ratio_b, ratio_d) && CheckEqualOrZero(ratio_c, ratio_d);
}

bool Plane3D::parallel(const Plane3D& another_plane) const
{
    float ratio_a = normal.x / another_plane.normal.x;
    float ratio_b = normal.y / another_plane.normal.y;
    float ratio_c = normal.z / another_plane.normal.z;

    return CheckEqualOrZero(ratio_a, ratio_b) && CheckEqualOrZero(ratio_a, ratio_c)
        && CheckEqualOrZero(ratio_b, ratio_c);
}

Line3D GetIntersectionLineOfPlanes(const Plane3D& plane1, const Plane3D& plane2)
{
    Line3D line;

    Vector3D cross_plane12 = Cross(plane1.normal, plane2.normal);

    line.distance = cross_plane12;

    float s1 = plane1.distance;
    float s2 = plane2.distance;

    float n1n2dot = Dot(plane1.normal, plane2.normal);
    float n1n2dot_square = n1n2dot * n1n2dot;

    float n1n1dot = Dot(plane1.normal, plane1.normal);
    float n2n2dot = Dot(plane2.normal, plane2.normal);

    float a = (s2 * n1n2dot - s1 * n2n2dot) / (n1n1dot * n2n2dot - n1n2dot_square);
    float b = (s1 * n1n2dot - s2 * n1n1dot) / (n1n1dot * n2n2dot - n1n2dot_square);

    line.point = (plane1.normal * a) + (plane2.normal * b);

    return line;
}

float GetSignDistBetweenPlaneAndPoint(const Plane3D& plane, const Point3D& point)
{
    float numerator   = plane.normal.x * point.x + plane.normal.y * point.y
    + plane.normal.z * point.z + plane.distance;

    float denominator = std::sqrt(std::pow(plane.normal.x, 2)
    + std::pow(plane.normal.y, 2) + std::pow(plane.normal.z, 2));

    return numerator / denominator;
}
