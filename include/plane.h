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

bool CheckIntersectionOfPlanes(Plane& plane0, Plane& plane1, Line& line);

float GetDistBetweenPlaneAndPoint(Plane& plane, Point& point);
