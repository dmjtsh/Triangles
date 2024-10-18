#include "utilities.h"

#include <cmath>

bool CheckFloatsEqual(float f1, float f2)
{
    return (std::abs(f1-f2)) < FLOAT_TOLERANCE;;
}

bool HasDifferentSign(float a, float b, float c)
{
    auto getSignCategory = [](float x) -> int
    {
        if (CheckFloatsEqual(x, 0.0f))
            return 0;
        else if (x > 0.0f)
            return 1;
        else
            return -1;
    };

    int signA = getSignCategory(a);
    int signB = getSignCategory(b);
    int signC = getSignCategory(c);

    return (signA != signB) || (signA != signC) || (signB != signC);
}
