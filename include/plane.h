#pragma once

#include <cmath>

#include "vector.h"
#include "triangle.h"
#include "line.h"

class Plane final
{
public:
    Plane() = default;
    Plane(const Vector& n, float d) : normal(n), distance(d) {}
    Plane(const Triangle& triangle);

    bool equal(const Plane& another_plane) const;
    bool parallel(const Plane& another_plane) const;

    Vector normal;
    float distance;
};

Line GetIntersectionLineOfPlanes(Plane& plane1, Plane& plane2);

float GetSignDistBetweenPlaneAndPoint(Plane& plane, Point& point);
