/*
Before consteval
    It can be useful to form a constexpr function to evaluate at compile-time. Prior to C++20, this was done by ensuring the return value is used where a constant expression is required.
        This has to be done per function call. This was done often by using the return value to initialize a constexpr variable. Doing this just to ensure compile-time evaluation is a bit gross.
*/

/*
Consteval
    Consteval forces a function to be evaluated at compile-time. Such functions are known as immediate functions.

    There are currently no C++ mechanisms that determine if a constexpr function call is evaluated at compile or runtime.
        std::is_constant_evaluated(), found in the <type_traits> header, returns a bool indicating whether the current function is executing in a constant-evaluated context.
            A constant(-evaluated) context is one in which a constant expression is required.
            This means that std::is_constant_evaluated() is checking whether the compiler is forced to evaluate it at compile-time (which can already be determined normally), not if it actually is
        if consteval is simply a nicer replacement for std::is_constant_evaluated() (introduced in C++23)
    
    #include <type_traits> // for std::is_constant_evaluated()

    constexpr int someFunction()
    {
        if (std::is_constant_evaluated()) // if evaluating in constant context
            //doSomething();
        else
            //doSomethingElse();
    }

    Constexpr functions can still be forced to evaluate at compile-time, since they are generally more flexible than consteval functions due to the possibility of runtime evaluation.

*/

#include <iostream>
// This uses a variadic preprocessor macro (the #define, ..., and __VA_ARGS__) to define an consteval lambda that is immediately invoked (by the trailing parentheses).
#define CONSTEVAL(...) [] consteval { return __VA_ARGS__; }()               // C++20 version per Jan Scultke (https://stackoverflow.com/a/77107431/460250)
#define CONSTEVAL11(...) [] { constexpr auto _ = __VA_ARGS__; return _; }() // C++11 version per Justin (https://stackoverflow.com/a/63637573/460250)

// This function returns the greater of the two numbers if executing in a constant context
// and the lesser of the two numbers otherwise
constexpr int compare(int x, int y) // function is constexpr
{
    if (std::is_constant_evaluated())
        return (x > y ? x : y);
    else
        return (x < y ? x : y);
}



consteval int greater(int x, int y) // function is now consteval (constexpr fallback if not supported)
{
    return (x > y ? x : y);
}


int main()
{
    int x { 5 };
    std::cout << compare(x, 6) << '\n';                  // will execute at runtime and return 5

    std::cout << compare(5, 6) << '\n';                  // may or may not execute at compile-time, but will always return 5
    std::cout << CONSTEVAL(compare(5, 6)) << '\n';       // will always execute at compile-time and return 6
    constexpr int g { greater(5, 6) };              // ok: will evaluate at compile-time
    std::cout << g << '\n';

    std::cout << greater(5, 6) << " is greater!\n"; // ok: will evaluate at compile-time

    // int x{ 5 }; // not constexpr
    //std::cout << greater(x, 6) << " is greater!\n"; // error: consteval functions must evaluate at compile-time

    return 0;
}