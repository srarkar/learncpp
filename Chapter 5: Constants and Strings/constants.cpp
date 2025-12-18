/*
Constants
    A constant is a value that cannot be changed during the program's execution.
    There are two kinds of constants supported by C++:
        - Named constants: constant values associated with an identifier, also known as a symbolic constant
        - Literal constants: constant values not associated with an identifier

Named constants
    Named constants can be defined in three ways:
        - Constant variables
        - Object-like macros with substitution text
        - Enumerated constants
Constant Variables
    
        A variable whose value cannot be changed after initialization is known as a constant variable.
        We can declare it by adding a "const" prefix as a keyword. Const must be initialized when they are declared. They can be initialized from another non-const variable.

        Function parameters can be const, but it is redundant if they are value parameters, since they will be torn down later anyways even if they are modified
        Const is also ignored when returning by value.
Benefits
    Making a variable constant reduces the chance of bugs, as it prevents the value from being changed accidentally.
    It provides opportunity for the compiler to optimize, as it can leverage constant propagation 
    (Most importantly) it reduces program complexity since we know what a value is for certain when we using a constant variable, rather than being uncertain if the variable was altered at some point

Macros
    When using a macro, the substitution text serves as a constant, since it replaces all occurrences of the macro's name.
    These are not preferred over constant variables, however, since they don't follow scoping rules, and can cause unintentional macro substitution elsewhere and is difficult to debug.

Type qualifiers
    A type qualifier is a keyword applied to a type that modifies how it behaves. There are only 2 in C++: const and volatile.
    Volatile means that the value of the object can change at any time, which disables certain types of compiler optimizations on that variable.
    These qualifiers can be reffered to in documentation as cv-qualifiers.
        A cv-unqualified type is a type with no type qualifiers (e.g. int).
    A cv-qualified type is a type with one or more type qualifiers applied (e.g. const int).
    A possibly cv-qualified type is a type that may be cv-unqualified or cv-qualified.
*/



#include <iostream>

#define MY_NAME "Alex"


void printInt(const int x)
{
    std::cout << x << '\n';
}

int main()
{

    // const double gravity; // error: const variables must be initialized
    // gravity = 9.9;        // error: const variables can not be changed

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    const int constAge { age }; // initialize const variable using non-const value
    
    age = 5;      // ok: age is non-const, so we can change its value
    // constAge = 6; // error: constAge is const, so we cannot change its value

    return 0;
}