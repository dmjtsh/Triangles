#pragma once

#include <cmath>

class Interval final
{
public:
    Interval() = default;
    Interval(double t0, double t1);

    bool overlap(const Interval& another_interval) const;

    bool valid() const;
    void print() const;

    double t0 = NAN;
    double t1 = NAN;
};
