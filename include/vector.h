#pragma once

#include <cmath>

#include "point.h"

//
// Vector3D Block
//

class Vector3D final
{
public:
    Vector3D() = default;
    Vector3D(const Point3D& p0, const Point3D& p1);
    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    double length() const;
    void normalize();

    bool valid() const;
    bool equal(const Vector3D& another_vector) const;

    void print() const;

    Vector3D operator+(const Vector3D& vector) const;
    Vector3D operator-(const Vector3D& vector) const;
    Vector3D operator*(double const_var) const;
    void   operator=(const Point3D& point);

    double x = NAN;
    double y = NAN;
    double z = NAN;
};

Vector3D Cross(const Vector3D& v1, const Vector3D& v2);

double Dot(const Vector3D& v1, const Vector3D& v2);

double Dot(const Vector3D& v1, const Point3D& p2);

//
// Vector2D Block
//

class Vector2D final
{
public:
    Vector2D() = default;
    Vector2D(const Point2D& p0, const Point2D& p1);
    Vector2D(double x, double y) : x(x), y(y) {}

    double length() const;

    bool valid() const;
    bool equal(const Vector2D& another_vector) const;

    void print() const;

    Vector2D operator+(const Vector2D& vector) const;
    Vector2D operator-(const Vector2D& vector) const;
    Vector2D operator*(double const_var) const;
    void   operator=(const Point2D& point);

    double x = NAN;
    double y = NAN;
};

double Cross(const Vector2D& v1, const Vector2D& v2);

double Dot(const Vector2D& v1, const Vector2D& v2);

