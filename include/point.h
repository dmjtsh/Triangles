#pragma once

#include <cmath>

class Vector;

class Point final
{
public:
    Point() = default;
    Point(float x, float y, float z) : x(x), y(y), z(z) {}

    bool valid() const;
    bool equal(const Point& another_point) const;

    void print() const;

    Point operator+(const Point& point) const;
    Point operator-(const Point& point) const;
    void  operator=(const Vector& vector);

    float x = NAN;
    float y = NAN;
    float z = NAN;
};

bool IsThreePointsOnOneLine(const Point& p1, const Point& p2, const Point& p3);
