#include <iostream>
#include <cmath>

#include "utilities.h"
#include "triangle.h"
#include "plane.h"

void Triangle::print() const
{
    std::cout << "First point:";
    point0.print();


    std::cout << "Second point:";
    point1.print();


    std::cout << "Third point:";
    point2.print();
}

bool Triangle::valid() const {
    return point0.valid() && point1.valid() && point2.valid()
    && !point0.equal(point1) && !point0.equal(point2) && !point1.equal(point2)
    && !IsThreePointsOnOneLine(point0, point1, point2);
}

bool Triangle::equal(const Triangle& another_triangle) const
{
    if(!another_triangle.valid())
        return false;

    if (point0.equal(another_triangle.point0) && point1.equal(another_triangle.point1)
    &&  point2.equal(another_triangle.point2))
        return true;

    return false;
}


// bool CheckTrianglesIntersection(Triangle& triangle1, Triangle& triangle2)
// {
//     if(!triangle1.valid() || !triangle2.valid())
//         return false;
//
//     Plane plane0 {triangle1};
//
//     float signed_dist_1_0 = GetDistBetweenPlaneAndPoint(plane0, triangle
//
//
//     Plane plane1 {triangle2};
// }
