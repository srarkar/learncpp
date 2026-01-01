/*
Non-type Template Parameters
    A non-type template parameter is a fixed type serving as a placeholder for a constexpr value passed as a template argument.
    They can be any of the following types: 
        An integral type
        An enumeration type
        std::nullptr_t
        A floating point type (since C++20)
        A pointer or reference to an object
        A pointer or reference to a function
        A pointer or reference to a member function
        A literal class type (since C++20)

    Much like T is the convention for type template parameters, N is the standard for non-type template parameters.

    Non-type template parameters are useful because, as of C++20, function parameters cannot be constexpr. 
        This is true for normal functions, constexpr functions (which makes sense, as they must be able to be run at runtime), and even consteval functions.
    Non-type template parameters are used primarily when we need to pass constexpr values to functions (or class types) so they can be used in contexts that require a constant expression.
*/

#include <bitset>
#include <iostream>

template <int N> // declare a non-type template parameter of type int named N
void print()
{
    std::cout << N << '\n'; // use value of N here
}


int main()
{
    std::bitset<8> bits{ 0b0000'0101 }; // The <8> is a non-type template argument

    print<5>(); // 5 is the non-type template argument

    return 0;
}