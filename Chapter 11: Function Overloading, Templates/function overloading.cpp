/*
Function Overloading
    Often, we will define multiple functions that are similar, but vary slightly.
    Function overloading allows us to define multiple functions of the same name, so long as they can be differentiated in other ways, such as the type of their parameters.

    When calling an overloaded function, the compiler will perform overload resolution to determine which version of the function the call applies to.

*/

#include <iostream>

int add(int x, int y)
{
    return x + y;
}

double add(double x, double y)
{
    return x + y;
}

int main()
{
    std::cout << add(1, 2); // calls add(int, int)
    std::cout << '\n';
    std::cout << add(1.2, 3.4); // calls add(double, double)

    return 0;
}