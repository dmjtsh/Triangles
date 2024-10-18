#include "utilities.h"
#include "triangle.h"
#include "interval.h"
#include "plane.h"

#include <iostream>
#include <vector>
#include <cmath>

//
// Triangle3D Block
//

void Triangle3D::print() const
{
    std::cout << "First point:";
    point0.print();


    std::cout << "Second point:";
    point1.print();


    std::cout << "Third point:";
    point2.print();
}

bool Triangle3D::valid() const
{
    return point0.valid() && point1.valid() && point2.valid()
    && !point0.equal(point1) && !point0.equal(point2) && !point1.equal(point2)
    && !IsThreePointsOnOneLine(point0, point1, point2);
}

bool Triangle3D::equal(const Triangle3D& another_triangle) const
{
    if(!another_triangle.valid())
        return false;

    if (point0.equal(another_triangle.point0) && point1.equal(another_triangle.point1)
    &&  point2.equal(another_triangle.point2))
        return true;

    return false;
}

bool CheckTrianglesIntersection(const Triangle3D& triangle0, const Triangle3D& triangle1)
{
    if(!triangle0.valid() || !triangle1.valid())
        return false;

    Plane3D plane0 {triangle0};

    float sign_dist_1_0 = GetSignDistBetweenPlaneAndPoint(plane0, triangle1.point0);
    float sign_dist_1_1 = GetSignDistBetweenPlaneAndPoint(plane0, triangle1.point1);
    float sign_dist_1_2 = GetSignDistBetweenPlaneAndPoint(plane0, triangle1.point2);

    if(!HasDifferentSign(sign_dist_1_0, sign_dist_1_1, sign_dist_1_2))
        return false;

    Plane3D plane1 {triangle1};

    if(plane0.parallel(plane1))
    {
        if(plane0.equal(plane1))
        {
            if(CheckFloatsEqual(plane0.normal.x, plane1.normal.x))
            {
                Triangle2D triangle0_2D = Triangle2D {Point2D(triangle0.point0.y, triangle0.point0.z),
                                                      Point2D(triangle0.point1.y, triangle0.point1.z),
                                                      Point2D(triangle0.point2.y, triangle0.point2.z)};
                Triangle2D triangle1_2D = Triangle2D {Point2D(triangle1.point0.y, triangle1.point0.z),
                                                      Point2D(triangle1.point1.y, triangle1.point1.z),
                                                      Point2D(triangle1.point2.y, triangle1.point2.z)};

                return CheckTrianglesIntersection(triangle0_2D, triangle1_2D);
            }
            else if (CheckFloatsEqual(plane0.normal.y, plane1.normal.y))
            {
                Triangle2D triangle0_2D = Triangle2D {Point2D(triangle0.point0.x, triangle0.point0.z),
                                                      Point2D(triangle0.point1.x, triangle0.point1.z),
                                                      Point2D(triangle0.point2.x, triangle0.point2.z)};
                Triangle2D triangle1_2D = Triangle2D {Point2D(triangle1.point0.x, triangle1.point0.z),
                                                      Point2D(triangle1.point1.x, triangle1.point1.z),
                                                      Point2D(triangle1.point2.x, triangle1.point2.z)};

                return CheckTrianglesIntersection(triangle0_2D, triangle1_2D);
            }
            else if (CheckFloatsEqual(plane0.normal.z, plane1.normal.z))
            {
                Triangle2D triangle0_2D = Triangle2D {Point2D(triangle0.point0.y, triangle0.point0.x),
                                                      Point2D(triangle0.point1.y, triangle0.point1.x),
                                                      Point2D(triangle0.point2.y, triangle0.point2.x)};
                Triangle2D triangle1_2D = Triangle2D {Point2D(triangle1.point0.y, triangle1.point0.x),
                                                      Point2D(triangle1.point1.y, triangle1.point1.x),
                                                      Point2D(triangle1.point2.y, triangle1.point2.x)};

                return CheckTrianglesIntersection(triangle0_2D, triangle1_2D);
            }
        }
        else
        {
            return false;
        }
    }

    float sign_dist_0_0 = GetSignDistBetweenPlaneAndPoint(plane1, triangle0.point0);
    float sign_dist_0_1 = GetSignDistBetweenPlaneAndPoint(plane1, triangle0.point1);
    float sign_dist_0_2 = GetSignDistBetweenPlaneAndPoint(plane1, triangle0.point2);

    if(!HasDifferentSign(sign_dist_0_0, sign_dist_0_1, sign_dist_0_2))
        return false;

    Line3D int_line = GetIntersectionLineOfPlanes(plane0, plane1);

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

//
// Triangle2D Block
//

bool IsPointInTriangle(const Triangle2D& triangle, const Point2D& point)
{
    Vector2D OA = Vector2D{point, triangle.point0};
    Vector2D OB = Vector2D{point, triangle.point1};
    Vector2D OC = Vector2D{point, triangle.point2};
    Vector2D AB = Vector2D{triangle.point0, triangle.point1};
    Vector2D CA = Vector2D{triangle.point2, triangle.point0};
    Vector2D BC = Vector2D{triangle.point1, triangle.point2};

    float OAxAB = Cross(OA, AB);
    float OBxBC = Cross(OB, BC);
    float OCxCA = Cross(OC, CA);

    if(!HasDifferentSign(OAxAB, OBxBC, OCxCA) || point.equal(triangle.point0)
    || point.equal(triangle.point1) || point.equal(triangle.point2))
        return true;

    return false;
}

inline double Det2D(const Triangle2D& triangle)
{
    return triangle.point0.x * (triangle.point1.y- triangle.point2.y)
         + triangle.point1.x * (triangle.point2.y - triangle.point0.y)
         + triangle.point2.x * (triangle.point0.y - triangle.point1.y);
}

bool DoesPointLayOnExternalSide(const Point2D& triangle1_p0, const Point2D& triangle1_p1, const Point2D& triangle2_p)
{
    Triangle2D triangle = { triangle1_p0, triangle1_p1, triangle2_p };

    return Det2D(triangle) < 0;
}
bool CheckSide(const Point2D& p0, const Point2D& p1, const Triangle2D& triangle)
{
    return DoesPointLayOnExternalSide(p0, p1, triangle.point0) &&
           DoesPointLayOnExternalSide(p0, p1, triangle.point1) &&
           DoesPointLayOnExternalSide(p0, p1, triangle.point2);
}

void CheckTriangleWinding(Triangle2D& triangle)
{
    if (Det2D(triangle) < 0.0)
    {
            Point2D tmp = triangle.point0;

            triangle.point0 = triangle.point2;
            triangle.point2 = tmp;
    }
}

bool CheckTrianglesIntersection(Triangle2D& triangle0, Triangle2D& triangle1)
{
    CheckTriangleWinding(triangle0);
    CheckTriangleWinding(triangle1);

    if (CheckSide(triangle0.point0, triangle0.point1, triangle1) ||
        CheckSide(triangle0.point1, triangle0.point2, triangle1) ||
        CheckSide(triangle0.point2, triangle0.point0, triangle1))
    {
        return false;
    }

    if (CheckSide(triangle1.point0, triangle1.point1, triangle0) ||
        CheckSide(triangle1.point1, triangle1.point2, triangle0) ||
        CheckSide(triangle1.point2, triangle1.point0, triangle0))
    {
        return false;
    }

    return true;
}


void Triangle2D::print() const
{
    std::cout << "First point:";
    point0.print();


    std::cout << "Second point:";
    point1.print();
}

bool Triangle2D::valid() const
{
    return point0.valid() && point1.valid() && point2.valid()
    && !point0.equal(point1) && !point0.equal(point2) && !point1.equal(point2)
    && !IsThreePointsOnOneLine(point0, point1, point2);
}

bool Triangle2D::equal(const Triangle2D& another_triangle) const
{
    if(!another_triangle.valid())
        return false;

    if (point0.equal(another_triangle.point0) && point1.equal(another_triangle.point1)
    &&  point2.equal(another_triangle.point2))
        return true;

    return false;
}
