#include <iostream>

#include "point.h"
#include "vector.h"
#include "line.h"

bool Line::valid() const { return distance.valid() && point.valid();}

void Line::print() const
{
    std::cout << "Distance: ";

    distance.print();

    std::cout << "Point: ";

    point.print();
}
