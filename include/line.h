#pragma once

#include "point.h"
#include "vector.h"

class Line3D final
{
public:
    Line3D() = default;
    Line3D(Vector3D d, Point3D p) : distance(d), point(p) {}

    bool valid() const;

    void print() const;

    Vector3D distance;
    Point3D point;
};
