/*
Before consteval
    It can be useful to form a constexpr function to evaluate at compile-time. Prior to C++20, this was done by ensuring the return value is used where a constant expression is required.
        This has to be done per function call. This was done often by using the return value to initialize a constexpr variable. Doing this just to ensure compile-time evaluation is a bit gross.
*/

/*
Consteval
    Consteval forces a function to be evaluated at compile-time. Such functions are known as immediate functions.
    There are currently no C++ mechanisms that determine if a constexpr function call is evaluated at compile or runtime.

*/

#include <iostream>

consteval int greater(int x, int y) // function is now consteval (constexpr fallback if not supported)
{
    return (x > y ? x : y);
}


int main()
{
    constexpr int g { greater(5, 6) };              // ok: will evaluate at compile-time
    std::cout << g << '\n';

    std::cout << greater(5, 6) << " is greater!\n"; // ok: will evaluate at compile-time

    int x{ 5 }; // not constexpr
    //std::cout << greater(x, 6) << " is greater!\n"; // error: consteval functions must evaluate at compile-time

    return 0;
}