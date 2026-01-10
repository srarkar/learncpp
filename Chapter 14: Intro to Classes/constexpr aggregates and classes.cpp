/*
Constexpr Aggregates and Classes
    For an aggregate's member functions, we can make them constexpr the same way we would for a non-member function.
    This allows the function to be evaluated at either compile-time or runtime.

    But for a non-aggregate, which has a constructor and/or private member variables, we get a compile error.
    This is because our class type would not be a literal type, a special category of types that can be evaluated at compile-time.
    The reason it is not a literal type is because its constructor would be called on. If that constructor is not constexpr, then we cannot perform compile-time evaluation.
    Literal types include:  
        - Scalar types (those holding a single value, such as fundamental types and pointers)
        - Reference types
        - Most aggregates
        - Classes that have a constexpr constructor
    Thus, if we want your class to be able to be evaluated at compile-time, we need constexpr constructors and member functions.

    Normally you won’t see constexpr and const used right next to each other, but one case where this does happen is when you have a constexpr member function that returns a const reference (or (const) pointer-to-const).
    The constexpr indicates that the member function can be evaluated at compile-time. The const int& is the return type of the function. The rightmost const means the member-function itself is const so it can be called on const objects.
*/

#include <iostream>

class Pair
{
private:
    int m_x {};
    int m_y {};

public:
    constexpr Pair(int x, int y): m_x { x }, m_y { y } {}

    constexpr int greater() const // constexpr and const
    {
        return (m_x > m_y  ? m_x : m_y);
    }

    constexpr void reset() // constexpr but non-const
    {
        m_x = m_y = 0; // non-const member function can change members
    }

    constexpr const int& getX() const { return m_x; }
};

// This function is constexpr
constexpr Pair zero()
{
    Pair p { 1, 2 }; // p is non-const
    p.reset();       // okay to call non-const member function on non-const object
    return p;
}

int main()
{
    Pair p1 { 3, 4 };
    p1.reset();                     // okay to call non-const member function on non-const object
    std::cout << p1.getX() << '\n'; // prints 0

    Pair p2 { zero() };             // zero() will be evaluated at runtime
    p2.reset();                     // okay to call non-const member function on non-const object
    std::cout << p2.getX() << '\n'; // prints 0

    constexpr Pair p3 { zero() };   // zero() will be evaluated at compile-time
//    p3.reset();                   // Compile error: can't call non-const member function on const object
    std::cout << p3.getX() << '\n'; // prints 0

    return 0;
}