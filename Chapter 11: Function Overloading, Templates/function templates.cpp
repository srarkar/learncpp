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
    The normal function call syntax will prefer a non-template function over an equally viable function instantiated from a template.

    When a static local variable is used in a function template, each function instantiated from that template will have a separate version of the static local variable.
    For a non-const static local variable, this can lead to unexpected behavior.

    Generally, use function templates to write generic code that can work with a wide variety of types whenever you have the need.
    We can use multiple template type parameters if we have multiple parameter types

    When overloading function templates, the compiler will choose the most restricted/specialized one available.

Function Templates Across Files
    When using a function template across files, it is often best to put the function definition in the header file. Otherwise, the versions of the function will not be instantiated, causing linker errors.
    This doesn't violate ODR since having multiple inline functions is fine so long as they are identical, which they are since the header files give all of them copies.
        This is because functions implicitly instantiated from function templates are implicitly inline
    
    

*/

/* Say we want to make a template for the following:
int max(int x, int y)
 {
     return (x < y) ? y : x;
 }


// Only one type (int) needs replacing, so we can replace any instances of it that we want to generalize with some placeholder type T
T max(T x, T y) // won't compile because we haven't defined T
{
    return (x < y) ? y : x;
}

// Thus, we need a template parameter declaration so that the existence of T is known.
*/

#include <iostream>

template <typename T> // template parameter declaration for T
T max(T x, T y)
{
    std::cout << "called max<int>(int, int)\n";
    return (x < y) ? y : x;
}

template <typename T, typename U> // We're using two template type parameters named T and U
T max(T x, U y) // x can resolve to type T, and y can resolve to type U
{
    return (x < y) ? y : x; // uh oh, we have a narrowing conversion problem here
}

int max(int x, int y)
{
    std::cout << "called max(int, int)\n";
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max<int>(1, 2) << '\n'; // calls max<int>(int, int)
    std::cout << max<>(1, 2) << '\n';    // deduces max<int>(int, int) (non-template functions not considered)
    std::cout << max(1, 2) << '\n';      // calls max(int, int)

    return 0;
}