#include "func.h"

int far(const int& cel)
{
    return (cel * 9) / 5 + 32;
}
double far(const double& cel)
{
    return cel * 9.0 / 5.0 + 32.0;
}