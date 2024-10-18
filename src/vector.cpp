#include "vector.h"
#include "point.h"
#include "utilities.h"

#include <iostream>
#include <cmath>

//
// Vector3D Block
//

Vector3D::Vector3D(const Point3D& p1, const Point3D& p2)
{
    Point3D p = p1-p2;

    x = p.x;
    y = p.y;
    z = p.z;
}

void Vector3D::print() const
{
    std::cout << "x:" << x << " " << "y:" << y << " " << "z:" << z << std::endl;
}

bool Vector3D::valid() const { return !std::isnan(x) && !std::isnan(y) && !std::isnan(z); }

bool Vector3D::equal(const Vector3D& another_vector) const
{
    if(!another_vector.valid())
        return false;

    if (CheckFloatsEqual(x, another_vector.x) && CheckFloatsEqual(y, another_vector.y)
    &&  CheckFloatsEqual(z, another_vector.z))
        return true;

    return false;
}

float Vector3D::length() const
{
    return std::sqrt(x*x + y*y + z*z);
}

Vector3D Cross(const Vector3D& v1, const Vector3D& v2)
{
    return Vector3D(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
            v1.x * v2.y - v1.y * v2.x);
}

float Dot(const Vector3D& v1, const Vector3D& v2)
{
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

float Dot(const Vector3D& v1, const Point3D& p2)
{
    return v1.x*p2.x + v1.y*p2.y + v1.z*p2.z;
}

Vector3D Vector3D::operator+(const Vector3D& vector) const
{
    return Vector3D{x+vector.x, y+vector.y, z+vector.z};
}

Vector3D Vector3D::operator-(const Vector3D & vector) const
{
    return Vector3D{x-vector.x, y-vector.y, z-vector.z};
}

void Vector3D::operator=(const Point3D& point)
{
    x = point.x;
    y = point.y;
    z = point.z;
}

Vector3D Vector3D::operator*(float scalar) const
{
    return Vector3D{x*scalar, y*scalar, z*scalar};
}

//
// Vector2D Block
//

Vector2D::Vector2D(const Point2D& p1, const Point2D& p2)
{
    Point2D p = p1 - p2;

    x = p.x;
    y = p.y;
}

void Vector2D::print() const
{
    std::cout << "x: " << x << " " << "y: " << y << std::endl;
}

bool Vector2D::valid() const
{
    return !std::isnan(x) && !std::isnan(y);
}

bool Vector2D::equal(const Vector2D& another_vector) const
{
    if (!another_vector.valid())
        return false;

    return CheckFloatsEqual(x, another_vector.x) && CheckFloatsEqual(y, another_vector.y);
}

float Vector2D::length() const
{
    return std::sqrt(x * x + y * y);
}

float Cross(const Vector2D& v1, const Vector2D& v2)
{
    return v1.x*v2.y - v1.y*v2.x;
}

float Dot(const Vector2D& v1, const Vector2D& v2)
{
    return v1.x*v2.x + v1.y*v2.y;
}

Vector2D Vector2D::operator+(const Vector2D& vector) const
{
    return Vector2D{x + vector.x, y + vector.y};
}

Vector2D Vector2D::operator-(const Vector2D& vector) const
{
    return Vector2D{x - vector.x, y - vector.y};
}

Vector2D Vector2D::operator*(float scalar) const
{
    return Vector2D{x*scalar, y*scalar};
}

void Vector2D::operator=(const Point2D& point)
{
    x = point.x;
    y = point.y;
}
