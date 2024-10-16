#pragma once

#include "vector.h"
#include "triangle.h"
#include "line.h"
#include "point.h"

#include <cmath>

class Plane3D final
{
public:
    Plane3D() = default;
    Plane3D(const Vector3D& n, float d) : normal(n), distance(d) {}
    Plane3D(const Triangle3D& triangle);

    bool equal(const Plane3D& another_plane) const;
    bool parallel(const Plane3D& another_plane) const;

    Vector3D normal;
    float distance;
};

Line3D GetIntersectionLineOfPlanes(const Plane3D& plane1, const Plane3D& plane2);

float GetSignDistBetweenPlaneAndPoint(const Plane3D& plane, const Point3D& point);
