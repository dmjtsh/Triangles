#include "plane.h"
#include "triangle.h"
#include "line.h"
#include "utilities.h"

Plane::Plane(const Triangle& triangle)
{
    Vector a_b(triangle.point1, triangle.point2);
    Vector a_c(triangle.point1, triangle.point3);

    normal = Cross(a_b, a_c);

    distance = -normal.x * triangle.point1.x - normal.y * triangle.point1.y
              - normal.z * triangle.point1.z;
}

// TODO: znak normali
bool CheckIntersectionOfPlanes(Plane& plane1, Plane& plane2, Line& line)
{
    Vector cross_plane12 = Cross(plane1.normal, plane2.normal);

    // TODO: + Planes coincidence
    if(CheckFloatsEqual(cross_plane12.length(), 0))
    {
        return false;
    }

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

    return true;
}
