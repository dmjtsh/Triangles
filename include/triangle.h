#pragma once

#include "point.h"

class Triangle final
{
public:
    Triangle() = default;
    Triangle(Point p0, Point p1, Point p2) : point0(p0), point1(p1), point2(p2) {}

    bool valid() const;
    bool equal(const Triangle& another_triangle) const;

    void print() const;

    Point point0;
    Point point1;
    Point point2;
};

bool CheckTrianglesIntersection(Triangle& triangle0, Triangle& triangle1);
