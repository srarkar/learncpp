/*
Temporary Class Objects
    Sometimes, we can replace a created variable with just the expression where it is needed, almost like value propagation but with the whole expression.
    This is only possible where rvalue expressions are accepted.

    The same can be done for class objects, where we can create a temporary object (or anonymous or unnamed object) instead of a named variable.
        These objects have no name and live within a single expression.
    
    When converting between one type and another (and disregarding narrowing conversions), there comes a choice between using static_cast and explicit instantiation.
    static_cast returns a temporary that was direct-initialized with the provided value, while explicit instantiation does the same but with list initialization.

    Some guidelines on when to use one over the other:
        As a quick rule of thumb: Prefer static_cast when converting to a fundamental type, and a list-initialized temporary when converting to a class type.

        Prefer static_cast when to create a temporary object when any of the following are true:

        We need to performing a narrowing conversion.
        We want to make it really obvious that we’re converting to a type that will result in some different behavior (e.g. a char to an int).
        We want to use direct-initialization for some reason (e.g. to avoid list constructors taking precedence).
        Prefer creating a new object (using list initialization) to create a temporary object when any of the following are true:

        We want to use list-initialization (e.g. for the protection against narrowing conversions, or because we need to invoke a list constructor).
        We need to provide additional arguments to a constructor to facilitate the conversion
    
*/

#include <iostream>
#include <string>
#include <string_view>

class IntPair
{
private:
    int m_x{};
    int m_y{};

public:
    IntPair(int x, int y)
        : m_x { x }, m_y { y }
    {}

    int x() const { return m_x; }
    int y() const{ return m_y; }
};

void print(IntPair p)
{
    std::cout << "(" << p.x() << ", " << p.y() << ")\n";
}

void printString(const std::string &s)
{
    std::cout << s << '\n';
}

int main()
{
    // Case 1: Pass variable
    IntPair p { 3, 4 };
    print(p);

    // Case 2: Construct temporary IntPair and pass to function
    print(IntPair { 5, 6 } );

    // Case 3: Implicitly convert { 7, 8 } to a temporary Intpair and pass to function
    print( { 7, 8 } );


    std::string_view sv { "Hello" };

    
    // We want to print sv using the printString() function
//  printString(sv); // compile error: a std::string_view won't implicitly convert to a std::string

    printString( static_cast<std::string>(sv) ); // Case 1: static_cast returns a temporary std::string direct-initialized with sv
    printString( std::string { sv } );           // Case 2: explicitly creates a temporary std::string list-initialized with sv
    printString( std::string ( sv ) );           // Case 3: C-style cast returns temporary std::string direct-initialized with sv (avoid this one!)
    return 0;
}