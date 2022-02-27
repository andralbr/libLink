#include <iostream>
#include "mathLib.h"

int main()
{
    std::cout << "-- Demo \n";

    MathLib mathLib;
    double res = mathLib.add( 2.5, 0.8 );
    std::cout << "Result = " << res << "\n";

    return 0;
}