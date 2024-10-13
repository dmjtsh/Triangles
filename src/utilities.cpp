#include "utilities.h"

bool CheckFloatsEqual(float f1, float f2)
{
    return (f1-f2) < FLOAT_TOLERANCE;
}
