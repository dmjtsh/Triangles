#include "utilities.h"

#include <cmath>

bool CheckDoublesEqual(double d1, double d2)
{
    return (std::abs(d1 - d2)) < DOUBLE_TOLERANCE;
}

bool CheckLessOrZero(double a, double b)
{
    if ( a < b || (CheckDoublesEqual(a, 0.0) && CheckDoublesEqual(b, 0.0)))
        return true;

    return false;
}

bool HasDifferentSign(double a, double b, double c)
{
    if(CheckDoublesEqual(a,0) || CheckDoublesEqual(b,0) || CheckDoublesEqual(c,0))
        return true;

    int signA = std::signbit(a);
    int signB = std::signbit(b);
    int signC = std::signbit(c);

    return (signA != signB) || (signA != signC) || (signB != signC);
}
