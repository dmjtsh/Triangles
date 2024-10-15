#pragma once

#include <cmath>

class Interval final
{
public:
    Interval() = default;
    Interval(float t0, float t1) : t0(t0), t1(t1) {}

    bool overlap(const Interval& another_interval) const;

    bool valid() const;
    void print() const;

    float t0 = NAN;
    float t1 = NAN;
};
