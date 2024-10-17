#include "utilities.h"

#include <cmath>

bool CheckFloatsEqual(float f1, float f2)
{
    return (std::abs(f1-f2)) < FLOAT_TOLERANCE;;
}

bool HasDifferentSign(float a, float b, float c)
{
    bool signA = std::signbit(a);
    bool signB = std::signbit(b);
    bool signC = std::signbit(c);

    return (signA != signB) || (signA != signC) || (signB != signC);
}
