#include "addNumbers.h"
#include <iostream>

double addNumbers( double a, double b)
{
    std::cout << "[addNumbers] Adding numbers a = " << a
        << ", b = " << b << "\n";

    return a + b;
}