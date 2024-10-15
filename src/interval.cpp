#include <iostream>

#include "interval.h"

bool Interval::overlap(const Interval& another_interval) const
{
    return !(t2 < another_interval.t1 || another_interval.t2 < t1);
}

bool Interval::valid() const { return !std::isnan(t1) && !std::isnan(t2); }

void Interval::print() const { std::cout << "t1:" << t1 << " " << "t2:" << t2 << std::endl; }
