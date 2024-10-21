#pragma once

#include <cmath>

//
// Point3D Block
//

class Vector3D;

class Point3D final
{
public:
    Point3D() = default;
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

    bool valid() const;
    bool equal(const Point3D& another_point) const;

    void print() const;

    Point3D operator+(const Point3D& point) const;
    Point3D operator-(const Point3D& point) const;
    void  operator=(const Vector3D& vector);
    operator Vector3D() const;

    double x = NAN;
    double y = NAN;
    double z = NAN;
};

bool IsThreePointsOnOneLine(const Point3D& p0, const Point3D& p1, const Point3D& p2);

//
// Point2D Block
//

class Vector2D;

class Point2D final
{
public:
    Point2D() = default;
    Point2D(double x, double y) : x(x), y(y) {}

    bool valid() const;
    bool equal(const Point2D& another_point) const;

    void print() const;

    Point2D operator+(const Point2D& point) const;
    Point2D operator-(const Point2D& point) const;
    void    operator=(const Vector2D& vector);

    double x = NAN;
    double y = NAN;
  };

bool IsThreePointsOnOneLine(const Point2D& p1, const Point2D& p2, const Point2D& p3);
