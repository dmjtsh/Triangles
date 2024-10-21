#include "interval.h"
#include "utilities.h"

#include <iostream>
#include <cmath>

Interval::Interval(double t0, double t1)
{
    double max_t01 = std::max(t0, t1);
    double min_t01 = std::min(t0, t1);

    this->t0 = min_t01;
    this->t1 = max_t01;
}

bool Interval::overlap(const Interval& another_interval) const
{
    if (!this->valid() || !another_interval.valid())
        return false;

    return !(t1 + DOUBLE_TOLERANCE < another_interval.t0  || another_interval.t1 + DOUBLE_TOLERANCE < t0);
}

bool Interval::valid() const { return !std::isnan(t0) && !std::isnan(t1); }

void Interval::print() const { std::cout << "t0:" << t0 << " " << "t1:" << t1 << std::endl; }
