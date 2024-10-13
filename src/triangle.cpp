#include <iostream>
#include <cmath>

#include "utilities.h"
#include "triangle.h"

void Triangle::print() const
{
    std::cout << "First point:";
    point1.print();


    std::cout << "Second point:";
    point2.print();


    std::cout << "Third point:";
    point3.print();
}

bool Triangle::valid() const { return point1.valid() && point2.valid() && point3.valid()
            && !point1.equal(point2) && !point1.equal(point3) && !point2.equal(point3)
            && !IsThreePointsOnOneLine(point1, point2, point3); }

bool Triangle::equal(const Triangle& another_triangle) const
{
    if(!another_triangle.valid())
        return false;

    if (point1.equal(another_triangle.point1) && point2.equal(another_triangle.point2)
    &&  point3.equal(another_triangle.point3))
        return true;

    return false;
}
