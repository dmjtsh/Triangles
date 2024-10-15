#pragma once

#include <cmath>

#include "point.h"

class Vector final
{
public:
    Vector() = default;
    Vector(const Point& p0, const Point& p1);
    Vector(float x, float y, float z) : x(x), y(y), z(z) {}

    float length();

    bool valid() const;
    bool equal(const Vector& another_vector) const;

    void print() const;

    Vector operator+(const Vector& vector) const;
    Vector operator-(const Vector& vector) const;
    Vector operator*(float const_var) const;
    void   operator=(const Point& point);

    float x = NAN;
    float y = NAN;
    float z = NAN;
};

Vector Cross(const Vector& v1, const Vector& v2);

float Dot(const Vector& v1, const Vector& v2);

float Dot(const Vector& v1, const Point& p2);
