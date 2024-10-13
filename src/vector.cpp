#include <iostream>
#include <cmath>

#include "vector.h"
#include "point.h"
#include "utilities.h"

Vector::Vector(const Point& p1, const Point& p2)
{
    Point p = p1-p2;

    x = p.x;
    y = p.y;
    z = p.z;
}

void Vector::print() const
{
    std::cout << "x:" << x << " " << "y:" << y << " " << "z:" << z << std::endl;
}

bool Vector::valid() const { return x != NAN && y != NAN && z != NAN;}

bool Vector::equal(const Vector& another_vector) const
{
    if(!another_vector.valid())
        return false;

    if (CheckFloatsEqual(x, another_vector.x) && CheckFloatsEqual(y, another_vector.x)
    &&  CheckFloatsEqual(z, another_vector.z))
        return true;

    return false;
}

float Vector::length()
{
    return std::sqrt(x*x + y*y + z*z);
}

Vector Cross(const Vector& v1, const Vector& v2)
{
    return Vector(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
            v1.x * v2.y - v1.y * v2.x);
}

float Dot(const Vector& v1, const Vector& v2)
{
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}


//
// Operators Overloading
//


Vector Vector::operator+(const Vector & vector) const
{
    return Vector(x+vector.x, y+vector.y, z+vector.z);
}

Vector Vector::operator-(const Vector & vector) const
{
    return Vector(x-vector.x, y-vector.y, z-vector.z);
}

Vector Vector::operator=(const Point& point) const
{
    return Vector(point.x, point.y, point.z);
}

Vector Vector::operator*(float const_var) const
{
    return Vector(x*const_var, y*const_var, z*const_var);
}
