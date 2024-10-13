#include <iostream>
#include <cmath>

#include "utilities.h"
#include "point.h"
#include "vector.h"

bool IsThreePointsOnOneLine(const Point& p1, const Point& p2, const Point& p3)
{
    return (p3.x - p1.x)/(p2.x - p1.x) == (p3.y - p1.y)/(p2.y - p1.y)
                                       == (p3.z - p1.z)/(p2.z - p1.z);
}

void Point::print() const
{
    std::cout << "x:" << x << " " << "y:" << y << " " << "z:" << z << std::endl;
}

bool Point::valid() const { return x != NAN && y != NAN && z != NAN;}

bool Point::equal(const Point& another_point) const
{
    if(!another_point.valid())
        return false;

    if (CheckFloatsEqual(x, another_point.x) && CheckFloatsEqual(y, another_point.x)
    &&  CheckFloatsEqual(z, another_point.z))
        return true;

    return false;
}

Point Point::operator+(const Point& point) const
{
    return Point(x+point.x, y+point.y, z+point.z);
}

Point Point::operator-(const Point& point) const
{
    return Point(x-point.x, y-point.y, z-point.z);
}
