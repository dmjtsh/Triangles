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
    auto getSignCategory = [](double x) -> int
    {
        if (CheckDoublesEqual(x, 0.0))
            return 0;
        else if (x > 0.0)
            return 1;
        else
            return -1;
    };

    int signA = getSignCategory(a);
    int signB = getSignCategory(b);
    int signC = getSignCategory(c);

    return (signA != signB) || (signA != signC) || (signB != signC);
}
