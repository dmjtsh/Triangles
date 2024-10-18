#pragma once

#include "point.h"

//
// Triangle3D Block
//

class Triangle3D final
{
public:
    Triangle3D() = default;
    Triangle3D(Point3D p0, Point3D p1, Point3D p2) : point0(p0), point1(p1), point2(p2) {}

    bool valid() const;
    bool equal(const Triangle3D& another_triangle) const;

    void print() const;

    Point3D point0;
    Point3D point1;
    Point3D point2;
};

bool CheckTrianglesIntersection(Triangle3D& triangle0, Triangle3D& triangle1);

//
// Triangle2D Block
//

class Triangle2D final
{
public:
    Triangle2D() = default;
    Triangle2D(Point2D p0, Point2D p1, Point2D p2) : point0(p0), point1(p1), point2(p2) {}

    bool valid() const;
    bool equal(const Triangle2D& another_triangle) const;

    void print() const;

    Point2D point0;
    Point2D point1;
    Point2D point2;
};

bool CheckTrianglesIntersection(Triangle2D& triangle0, Triangle2D& triangle1);

bool IsPointInTriangle(const Triangle2D& triangle, const Point2D& point);
