/*
Constexpr Functions
    One difficulty with using constant expressions is the inability to include function calls. 
    A constexpr function is allowed to be used as part of a constant expression. They are created by adding "constexpr" to the return type.

    These functions must evaluate at compile-time. Meaning:
        The call to the constexpr function must have arguments that are known at compile time (e.g. are constant expressions).
        All statements and expressions within the constexpr function must be evaluatable at compile-time.
        (along with some other, less commonly encountered criteria: https://en.cppreference.com/w/cpp/language/constexpr.html
    They can also still be evaluated at runtime, if the prior conditions are not met.
*/

#include <iostream>

constexpr double calcCircumference(double radius)
{
    constexpr double pi { 3.14159265359 };
    return 2.0 * pi * radius;
}

constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{

    constexpr double circumference { calcCircumference(3.0) }; // now compiles

    std::cout << "Our circle has circumference " << circumference << "\n";

    
    int x{ 5 }; // not constexpr
    int y{ 6 }; // not constexpr

    std::cout << greater(x, y) << " is greater!\n"; // will be evaluated at runtime

    return 0;
}