#pragma once

#include "point.h"

class Triangle final
{
public:
    Triangle(Point p1, Point p2, Point p3) : point1(p1), point2(p2), point3(p3) {}

    bool valid() const;
    bool equal(const Triangle& another_triangle) const;

    void print() const;

    Point point1;
    Point point2;
    Point point3;
};
