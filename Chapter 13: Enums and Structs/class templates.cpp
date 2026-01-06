/*
Class Templates
    Much like with writing functions, it can become repetitive to write multiple versions of an aggregate in order for it to work with different data types.
    The solution is a class template used to instantiate class types.

    There is good reason to stick to simple template parameter names, such a T, U, N, as they are less likely to shadow a class type name.
    Working with pairs of data is common, so the Pair class template is already defined in the <utility> header 

CTAD
    When initializing an object from a class template, the compiler can determine the template types from the types of the object's initializer. 
    This is known as class template argument deduction (CTAD).
        CTAD is only performed if no template argument list is present.
    
    We can provide a deduction guide to deduce the template arguments for aggregate class templates, which is otherwise not possible in C++17.
        Non-aggregates don’t need deduction guides in C++17 because the presence of a constructor serves the same purpose
        C++20 added the ability for the compiler to automatically generate deduction guides for aggregates

    CTAD does not work with non-static member initialization or function parameters.
*/

#include <iostream>

template <typename T, typename U>
struct Pair
{
    T first{};
    U second{};
};

// Here's a deduction guide for our Pair (needed in C++17 only)
// Pair objects initialized with arguments of type T and U should deduce to Pair<T, U>
// In orther words, if the compiler sees a declaration of a Pair with two arguments (of types T and U respectively), it should deduce the type to be a Pair<T, U>.
template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;


int main()
{
    Pair<int, int> p1{ 5, 6 };        // instantiates Pair<int> and creates object p1
    std::cout << p1.first << ' ' << p1.second << '\n';

    Pair<double, double> p2{ 1.2, 3.4 }; // instantiates Pair<double> and creates object p2
    std::cout << p2.first << ' ' << p2.second << '\n';

    Pair<double, double> p3{ 7.8, 9.0 }; // creates object p3 using prior definition for Pair<double>
    std::cout << p3.first << ' ' << p3.second << '\n';


    std::pair<int, double> p1{ 1, 2.3 }; // a pair holding an int and a double
    std::pair<double, int> p2{ 4.5, 6 }; // a pair holding a double and an int
    std::pair<int, int> p3{ 7, 8 };      // a pair holding two ints

    // std::pair<> p1 { 1, 2 };    // error: too few template arguments, both arguments not deduced
    // std::pair<int> p2 { 3, 4 }; // error: too few template arguments, second argument not deduced

    std::pair p1 { 3.4f, 5.6f }; // deduced to pair<float, float>
    std::pair p2 { 1u, 2u };     // deduced to pair<unsigned int, unsigned int>

    Pair<int, int> p1{ 1, 2 }; // explicitly specify class template Pair<int, int> (C++11 onward)
    Pair p2{ 1, 2 };           // CTAD used to deduce Pair<int, int> from the initializers (C++17)
    

    return 0;
}