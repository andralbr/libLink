#include "mathLib.h"
#include "addNumbers.h"
#include <iostream>


double MathLib::add(double a, double b)
{
    std::cout << "[MathLib::add] Adding numbers ... " << "\n";
    return addNumbers(a, b);
}
