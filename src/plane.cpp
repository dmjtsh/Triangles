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

    normalize_equation();
}

bool Plane3D::equal(const Plane3D& another_plane) const
{
    if (normal.equal(another_plane.normal) && CheckDoublesEqual(distance, another_plane.distance))
        return true;

    return false;
}

bool Plane3D::parallel(const Plane3D& another_plane) const
{
    if (normal.equal(another_plane.normal))
        return true;

    return false;
}

void Plane3D::normalize_equation()
{
    double length = normal.length();

    normal.x = normal.x / length;
    normal.y = normal.y / length;
    normal.z = normal.z / length;
    distance = distance / length;

    if(CheckLessOrZero(normal.x, 0) && CheckLessOrZero(normal.y, 0)
    && CheckLessOrZero(normal.z, 0))
    {
        normal   = normal * -1;
        distance = distance * -1;
    }
}

Line3D GetIntersectionLineOfPlanes(const Plane3D& plane1, const Plane3D& plane2)
{
    Line3D line;

    Vector3D cross_plane12 = Cross(plane1.normal, plane2.normal);

    line.distance = cross_plane12;

    double s1 = plane1.distance;
    double s2 = plane2.distance;

    double n1n2dot = Dot(plane1.normal, plane2.normal);
    double n1n2dot_square = n1n2dot * n1n2dot;

    double n1n1dot = Dot(plane1.normal, plane1.normal);
    double n2n2dot = Dot(plane2.normal, plane2.normal);

    double a = (s2 * n1n2dot - s1 * n2n2dot) / (n1n1dot * n2n2dot - n1n2dot_square);
    double b = (s1 * n1n2dot - s2 * n1n1dot) / (n1n1dot * n2n2dot - n1n2dot_square);

    line.point = (plane1.normal * a) + (plane2.normal * b);

    return line;
}

double GetSignDistBetweenPlaneAndPoint(const Plane3D& plane, const Point3D& point)
{
    double numerator   = plane.normal.x * point.x + plane.normal.y * point.y
    + plane.normal.z * point.z + plane.distance;

    return numerator;
}
