#pragma once

#include <cmath>

class Interval final
{
public:
    Interval() = default;
    Interval(float t1, float t2) : t1(t1), t2(t2) {}

    bool overlap(const Interval& another_interval) const;

    bool valid() const;
    void print() const;

    float t1 = NAN;
    float t2 = NAN;
};
