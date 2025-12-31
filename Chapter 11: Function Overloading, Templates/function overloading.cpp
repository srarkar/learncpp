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

/*
Overload Resolution
    Overload resolution is the process of matching a function call to an overloaded function.
    It is easy when there is an exact match for number and type of parameters, but what if there is not?

    The compiler will apply type conversions in steps to see if there is exactly one matching function.
    There are three possible results:
        No matching functions were found. The compiler moves to the next step in the sequence.
        A single matching function was found. This function is considered to be the best match. The matching process is now complete, and subsequent steps are not executed.
        More than one matching function was found. The compiler will issue an ambiguous match compile error.
    If the compiler reaches the end of the entire sequence without finding a match, it will generate a compile error that no matching overloaded function could be found for the function call.

    The argument matching sequence:
        1. The compiler tries to find an exact match. 
        This happens in two phases.
            First, the compiler will see if there is an overloaded function where the type of the arguments in the function call exactly matches the type of the parameters in the overloaded functions.
            Second, the compiler can applies trivial conversions, some examples being
                    lvalue to rvalue conversions
                    qualification conversions (e.g. non-const to const)
                    non-reference to reference conversions
        2. If no exact match is found, the compiler tries to find a match by applying numeric promotion to the arguments.
        3. If no match is found via numeric promotion, the compiler tries to find a match by applying numeric conversions to the arguments.
        4. If no match is found via numeric conversion, the compiler tries to find a match through any user-defined conversions.
        5. If no match is found via user-defined conversion, the compiler will look for a matching function that uses ellipsis.
        6. If no matches have been found by this point, the compiler gives up and will issue a compile error about not being able to find a matching function.

    If there are multiple arguments, the compiler applies the matching rules to each argument in turn. The function chosen is the one for which each argument matches as least as well as any other function's argument.
        In other words, the function chosen must provide a better match than all the other candidate functions for at least one parameter, and no worse for all of the other parameters.
    
    An ambiguous match occurs when two or more matching functions are found in the same step.
    An easy example would be in the numeric conversion step (step 3). If multiple function match their parameter types after numeric conversions, then it becomes ambiguous as to which to choose.
        Note that default arguments can also cause ambiguous matches
        They can be resolved by:
            Often, the best way is simply to define a new overloaded function that takes parameters of exactly the type you are trying to call the function with. 
                Then C++ will be able to find an exact match for the function call.
            Alternatively, explicitly cast the ambiguous argument(s) to match the type of the function you want to call. 


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

void print(int x)
{
     std::cout << x << '\n';
}

void print(double d)
{
     std::cout << d << '\n';
}


// We haven't covered classes yet, so don't worry if this doesn't make sense
class X // this defines a new type called X
{
public:
    operator int() { return 0; } // Here's a user-defined conversion from X to int
};

void foo(int)
{
}

void foo(double)
{
}
int main()
{
    std::cout << add(1, 2); // calls add(int, int)
    std::cout << '\n';
    std::cout << add(1.2, 3.4); // calls add(double, double)

    print('a'); // char does not match int or double, so what happens?
    //print(5L); // long does not match int or double, so what happens?

    X x; // Here, we're creating an object of type X (named x)
    foo(x); // x is converted to type int using the user-defined conversion from X to int

    return 0;
}
