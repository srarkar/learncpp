/*
Templates
    Say we had two overloaded versions of a function, where the function body is the same, but the only difference is the type of parameters.
    What we want is to combine them into a single version that accepts any type as the parameters.

    A template definition describes what a function or class looks like. We can use placeholder types which are not known when the template is defined and will be provided later when used.
    This template allows the compiler to generate multiple overloaded functions or classes as needed that use different types.

Function Templates
    A function template is a function-like definition that is used to generate one or more overloaded functions, each with a different set of actual types.
    The original template is called the primary template, and the functions it generates are known as instantiated functions.

    Placeholder types, also known as type template parameters (or template types) for any parameters, return type, or types used in the function body that we want to be specified later.

    C++ supports 3 different kinds of template parameters:
        Type template parameters (where the template parameter represents a type).
        Non-type template parameters (where the template parameter represents a constexpr value).
        Template template parameters (where the template parameter represents a template).
*/

/// Say we want to make a template for the following:
/* 
int max(int x, int y)
 {
     return (x < y) ? y : x;
 }
*/

// Only one type (int) needs replacing, so we can replace any instances of it that we want to generalize with some placeholder type T

/*
T max(T x, T y) // won't compile because we haven't defined T
{
    return (x < y) ? y : x;
}
*/

// Thus, we need a template parameter declaration so that the existence of T is known.

template <typename T> // this is the template parameter declaration defining T as a type template parameter
T max(T x, T y) // this is the function template definition for max<T>
{
    return (x < y) ? y : x;
}