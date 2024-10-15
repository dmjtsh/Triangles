#include <cmath>

#include "utilities.h"

bool CheckFloatsEqual(float f1, float f2)
{
    return (std::abs(f1-f2)) < FLOAT_TOLERANCE;;
}
