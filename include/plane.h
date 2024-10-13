#pragma once

#include <cmath>

#include "vector.h"
#include "triangle.h"

class Plane final
{
public:
    Plane(const Triangle& triangle)
    {
        ;
    }

    Vector normal;

    float distance;
};
