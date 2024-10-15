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

    Vector normal;
    float distance;
};

bool CheckIntersectionOfPlanes(Plane& plane1, Plane& plane2, Line& line);
