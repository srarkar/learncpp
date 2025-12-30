/*
Function Overloading
    Often, we will define multiple functions that are similar, but vary slightly.
    Function overloading allows us to define multiple functions of the same name, so long as they can be differentiated in other ways, such as the type of their parameters.

    When calling an overloaded function, the compiler will perform overload resolution to determine which version of the function the call applies to.

Function Differentiation
    It is essential that overloaded functions are distinguishable so that it is not unclear which function is being called.
    This is done using the type and number of parameters, as well as const/volatile and ref function qualifiers.
        Note that return type is not used for function differentiation. This was done since given a function call, we want to be able to decide which function to call independent of the expression it is a part of.
        Note: For the type of parameters, this excludes typedefs, type aliases, and const qualifier on value parameters. Includes ellipses.
    In summary, a function's type signature is composed of the function name, number of parameters, parameter type, and function-level qualifiers. These are all the qualities used to  differentiate between functions.

    Ellipsis parameters are considered to be a unique type of parameter


    When the compiler compiles a function, it performs name mangling, which means the compiled name of the function is altered (“mangled”) based on various criteria, such as the number and type of parameters, so that the linker has unique names to work with.
        This is not standardized -- the way it does so can be different for every compiler.
*/

#include <iostream>

// all of the following are different
int add(int x, int y); // integer version
double add(double x, double y); // floating point version
double add(int x, double y); // mixed version
double add(double x, int y); // mixed version

int add(int x, int y)
{
    return x + y;
}

int add(int x, int y, int z)
{
    return x + y + z;
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