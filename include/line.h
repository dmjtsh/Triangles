#pragma once

#include "point.h"
#include "vector.h"

class Line final
{
public:
    Line(Vector d, Point p) : distance(d), point(p) {}

    bool valid() const;

    void print() const;

    Vector distance;
    Point point;
};
