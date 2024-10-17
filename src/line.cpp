#include "point.h"
#include "vector.h"
#include "line.h"

#include <iostream>

bool Line3D::valid() const { return distance.valid() && point.valid();}

void Line3D::print() const
{
    std::cout << "Distance: ";

    distance.print();

    std::cout << "Point3D: ";

    point.print();
}
