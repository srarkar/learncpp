/*
Constexpr Functions
    Constexpr/consteval functions can use non-const local variables, and the values of these variables can change.
    Also, a constexpr or consteval function can use its non-constexpr function parameters or local variables in a function call to another constexpr function.
        This still depends on whether the parameters/locals' values are known at compile-time
    
    A constexpr function can call a non-constexpr function so long as the constexpr function is being evaluated in a non-constant context.
    Prior to C++23, the C++ standard says that a constexpr function must return a constexpr value for at least one set of arguments, otherwise it is technically ill-formed. 
        Calling a non-constexpr function unconditionally in a constexpr function makes the constexpr function ill-formed. 
    However, compilers are not required to generate errors or warnings for such cases -- therefore, the compiler probably won’t complain unless you try to call such a constexpr function in a constant context. 
    In C++23, this requirement was rescinded.

    Best practice:
        Avoid calling non-constexpr functions from within a constexpr function if possible.
        If your constexpr function requires different behavior for constant and non-constant contexts, conditionalize the behavior with if (std::is_constant_evaluated()) (in C++20) or if consteval (C++23 onward).
        Always test your constexpr functions in a constant context, as they may work when called in a non-constant context but fail in a constant context.
    
    If a function can be evaluated as part of a required constant expression, it should be constexpr.
    
    A pure function is one that:
        The function always returns the same return result when given the same arguments
        The function has no side effects (e.g. it doesn’t change the value of static local or global variables, doesn’t do input or output, etc…).
    Pure functions should be constexpr.
    
    Note that constexpr functions can be harder to debug since you can’t breakpoint or step through them in a debugger.
*/

#include <iostream>

constexpr int goo(int c) // goo() is now constexpr
{
    return c;
}

constexpr int foo(int b) // b is not a constant expression within foo()
{
    return goo(b);       // if foo() is resolved at compile-time, then `goo(b)` can also be resolved at compile-time
}

consteval int doSomething(int x, int y) // function is consteval
{
    x = x + 2;       // we can modify the value of non-const function parameters

    int z { x + y }; // we can instantiate non-const local variables
    if (x > y)
        z = z - 1;   // and then modify their values

    return z;
}

int main()
{
    std::cout << foo(5);

    constexpr int g { doSomething(5, 6) };
    std::cout << g << '\n';

    return 0;
}