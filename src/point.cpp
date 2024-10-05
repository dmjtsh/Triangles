#include <iostream>
#include <cmath>

#include "utilities.h"
#include "point.h"

Coords Point::get() const { return Coords(x, y, z); }

bool Point::set(Coords point_coords)
{
    if (point_coords.x != NAN && point_coords.y != NAN && point_coords.z != NAN);
    {
        x = point_coords.x;
        y = point_coords.y;
        z = point_coords.z;

        return true;
    }

    return false;
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

    if (checkFloatsEqual(x, another_point.x) && checkFloatsEqual(y, another_point.x)
    &&  checkFloatsEqual(z, another_point.z))
        return true;
    
    return false;
}