#include "interval.h"

#include <iostream>

bool Interval::overlap(const Interval& another_interval) const
{
    return !(t1 < another_interval.t0 || another_interval.t1 < t0);
}

bool Interval::valid() const { return !std::isnan(t0) && !std::isnan(t1); }

void Interval::print() const { std::cout << "t0:" << t0 << " " << "t1:" << t1 << std::endl; }
