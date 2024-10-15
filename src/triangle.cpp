#include <iostream>
#include <cmath>

#include "utilities.h"
#include "triangle.h"
#include "interval.h"
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


bool CheckTrianglesIntersection2D(Triangle& triangle0, Triangle& triangle1)
{
    return true;
}

bool CheckTrianglesIntersection3D(Triangle& triangle0, Triangle& triangle1)
{
    if(!triangle0.valid() || !triangle1.valid())
        return false;

    Plane plane0 {triangle0};

    float sign_dist_1_0 = GetSignDistBetweenPlaneAndPoint(plane0, triangle1.point0);
    float sign_dist_1_1 = GetSignDistBetweenPlaneAndPoint(plane0, triangle1.point1);
    float sign_dist_1_2 = GetSignDistBetweenPlaneAndPoint(plane0, triangle1.point2);

    if(!HasDifferentSign(sign_dist_1_0, sign_dist_1_1, sign_dist_1_2))
        return false;

    Plane plane1 {triangle1};

    if(plane0.parallel(plane1))
    {
        if(plane0.equal(plane1))
            return CheckTrianglesIntersection2D(triangle0, triangle1);
        else
            return false;
    }

    float sign_dist_0_0 = GetSignDistBetweenPlaneAndPoint(plane1, triangle0.point0);
    float sign_dist_0_1 = GetSignDistBetweenPlaneAndPoint(plane1, triangle0.point1);
    float sign_dist_0_2 = GetSignDistBetweenPlaneAndPoint(plane1, triangle0.point2);

    if(!HasDifferentSign(sign_dist_0_0, sign_dist_0_1, sign_dist_0_2))
        return false;

    Line int_line = GetIntersectionLineOfPlanes(plane0, plane1);

    Interval interval0;
    Interval interval1;

    float vec_proj_0_0 = Dot(int_line.distance, triangle0.point0 - int_line.point);
    float vec_proj_0_1 = Dot(int_line.distance, triangle0.point1 - int_line.point);
    float vec_proj_0_2 = Dot(int_line.distance, triangle0.point2 - int_line.point);

    interval0.t0 = (vec_proj_0_0 + (vec_proj_0_2 - vec_proj_0_0) * sign_dist_0_0)
                    / (sign_dist_0_0 - sign_dist_0_2);

    interval0.t1 = (vec_proj_0_1 + (vec_proj_0_2 - vec_proj_0_1) * sign_dist_0_1)
                    / (sign_dist_0_1 - sign_dist_0_2);

    float vec_proj_1_0 = Dot(int_line.distance, triangle1.point0 - int_line.point);
    float vec_proj_1_1 = Dot(int_line.distance, triangle1.point1 - int_line.point);
    float vec_proj_1_2 = Dot(int_line.distance, triangle1.point2 - int_line.point);

    interval1.t0 = (vec_proj_1_0 + (vec_proj_1_2 - vec_proj_1_0) * sign_dist_1_0)
                    / (sign_dist_1_0 - sign_dist_1_2);

    interval1.t1 = (vec_proj_1_1 + (vec_proj_1_2 - vec_proj_1_1) * sign_dist_1_1)
                    / (sign_dist_1_1 - sign_dist_1_2);

    return interval0.overlap(interval1);
}
