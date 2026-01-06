/*
Alias Templates
    As a reminder, type aliases are used to define aliases for existing types. We can use alias templates to instantiate them conveniently.

    Alias templates must be defined in the global scope (as with all other templates).
    Also like other templates, we must specify the template arguments when instantiating an object prior to C++20.
    C++20 introduces alias template deduction, which determines the type of the template arguments from an initializer where the aliased type works with CTAD.
    
    
*/

#include <iostream>

template <typename T>
struct Pair
{
    T first{};
    T second{};
};

// Here's our alias template
// Alias templates must be defined in global scope
template <typename T>
using Coord = Pair<T>; // Coord is an alias for Pair<T>

// Our print function template needs to know that Coord's template parameter T is a type template parameter
template <typename T>
void print(const Coord<T>& c)
{
    std::cout << c.first << ' ' << c.second << '\n';
}

// CTAD doesn't work for function parameters so we must specify the type
template <typename T>
void print(const Coord<T>& c)
{
    std::cout << c.first << ' ' << c.second << '\n';
}

int main()
{
    Coord<int> p1 { 1, 2 }; // Pre C++-20: We must explicitly specify all type template argument
    Coord p2 { 1, 2 };      // In C++20, we can use alias template deduction to deduce the template arguments in cases where CTAD works

    std::cout << p1.first << ' ' << p1.second << '\n';
    print(p2);

    return 0;
}