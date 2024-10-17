#include "utilities.h"
#include "point.h"
#include "vector.h"

#include <iostream>
#include <cmath>

//
// Point3D BLOCK
//

bool IsThreePointsOnOneLine(const Point3D& p1, const Point3D& p2, const Point3D& p3)
{
    float first_fraq  = (p3.x - p1.x)/(p2.x - p1.x);
    float second_fraq = (p3.y - p1.y)/(p2.y - p1.y);
    float third_fraq  = (p3.z - p1.z)/(p2.z - p1.z);

    return CheckFloatsEqual(first_fraq, second_fraq) && CheckFloatsEqual(second_fraq, third_fraq)
        && CheckFloatsEqual(first_fraq, third_fraq);
}

void Point3D::print() const
{
    std::cout << "x:" << x << " " << "y:" << y << " " << "z:" << z << std::endl;
}

bool Point3D::valid() const { return !std::isnan(x) && !std::isnan(y) && !std::isnan(z); }

bool Point3D::equal(const Point3D& another_point) const
{
    if(!another_point.valid())
        return false;

    if (CheckFloatsEqual(x, another_point.x) && CheckFloatsEqual(y, another_point.x)
    &&  CheckFloatsEqual(z, another_point.z))
        return true;

    return false;
}

Point3D Point3D::operator+(const Point3D& point) const
{
    return Point3D(x+point.x, y+point.y, z+point.z);
}

Point3D Point3D::operator-(const Point3D& point) const
{
    return Point3D(x-point.x, y-point.y, z-point.z);
}

void Point3D::operator=(const Vector3D& vector)
{
    x = vector.x;
    y = vector.y;
    z = vector.z;
}

//
// Point2D BLOCK
//

bool IsThreePointsOnOneLine(const Point2D& p1, const Point2D& p2, const Point2D& p3)
{
    return (p2.y - p1.y) * (p3.x - p2.x) == (p3.y - p2.y) * (p2.x - p1.x);
}

void Point2D::print() const
{
    std::cout << "x:" << x << " " << "y:" << y << std::endl;
}

bool Point2D::valid() const
{
    return !std::isnan(x) && !std::isnan(y);
}

bool Point2D::equal(const Point2D& another_point) const
{
    if (!another_point.valid())
        return false;

    return CheckFloatsEqual(x, another_point.x) && CheckFloatsEqual(y, another_point.y);
}

Point2D Point2D::operator+(const Point2D& point) const
{
    return Point2D{x + point.x, y + point.y};
}

Point2D Point2D::operator-(const Point2D& point) const
{
    return Point2D{x - point.x, y - point.y};
}

void Point2D::operator=(const Vector2D& vector)
{
    x = vector.x;
    y = vector.y;
}

