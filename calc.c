#include "calc.h"

double calc_add(double a, double b)
{
    return a + b;
}

double calc_sub(double a, double b)
{
    return a - b;
}

double calc_mul(double a, double b)
{
    return a * b;
}

int calc_div(double a, double b, double *result)
{
    if (b == 0)
        return 0;

    *result = a / b;
    return 1;
}
