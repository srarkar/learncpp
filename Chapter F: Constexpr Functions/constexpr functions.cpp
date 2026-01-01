/*
Constexpr Functions
    One difficulty with using constant expressions is the inability to include function calls. 
    A constexpr function is allowed to be used as part of a constant expression. They are created by adding "constexpr" to the return type.

    These functions must evaluate at compile-time. Meaning:
        The call to the constexpr function must have arguments that are known at compile time (e.g. are constant expressions).
        All statements and expressions within the constexpr function must be evaluatable at compile-time.
        (along with some other, less commonly encountered criteria: https://en.cppreference.com/w/cpp/language/constexpr.html
    They can also still be evaluated at runtime, if the prior conditions are not met.

    Parameters of constexpr functions are not implicitly constexpr, nor can they be declared as such. Doing so would prevent the function from being called with non-constexpr variables (and evaluate at runtime instead)

    These functions are implicitly inline, meaning they often should be defined in header files.
        If a constexpr/consteval function is only used in a single source file then it is better to define it in the source file as opposed to the header.
    
    If using a forward declaration, in order for it to be evaluated at compile-time, the constexpr function must be defined prior to the outermost evaluation that eventually results in the invocation.
*/

/*
We can categorize the likelihood that a function will actually be evaluated at compile-time as follows:

    Always (required by the standard):
        Constexpr function is called where constant expression is required.
        Constexpr function is called from other function being evaluated at compile-time.

    Probably (there’s little reason not to):
        Constexpr function is called where constant expression isn’t required, all arguments are constant expressions.

    Possibly (if optimized under the as-if rule):
        Constexpr function is called where constant expression isn’t required, some arguments are not constant expressions but their values are known at compile-time.
        Non-constexpr function capable of being evaluated at compile-time, all arguments are constant expressions.

    Never (not possible):
        Constexpr function is called where constant expression isn’t required, some arguments have values that are not known at compile-time.
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



// consteval int goo(int c)    // c is not constexpr, and cannot be used in constant expressions
// {
//     return c;
// }

// // constexpr int foo(int b)    // b is not constexpr, and cannot be used in constant expressions
// // {
// //     constexpr int b2 { b }; // compile error: constexpr variable requires constant expression initializer

// //     return goo(b);          // compile error: consteval function call requires constant expression argument
// // }

constexpr int foo(int);

constexpr int goo(int c)
{
	return foo(c);   // note that foo is not defined yet
}

constexpr int foo(int b) // okay because foo is still defined before any calls to goo
{
	return b;
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

    constexpr int a{ goo(5) }; // this is the outermost invocation

    constexpr int g { greater(5, 6) };              // case 1: always evaluated at compile-time
    std::cout << g << " is greater!\n";

    std::cout << greater(5, 6) << " is greater!\n"; // case 2: may be evaluated at either runtime or compile-time

    int x{ 5 }; // not constexpr but value is known at compile-time
    std::cout << greater(x, 6) << " is greater!\n"; // case 3: likely evaluated at runtime

    std::cin >> x;
    std::cout << greater(x, 6) << " is greater!\n"; // case 4: always evaluated at runtime

    return 0;
}