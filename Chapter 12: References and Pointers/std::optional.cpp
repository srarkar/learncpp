/*
std::optional
    Handling special/invalid cases in a function with sentinel values or exceptions can sometimes encourage other errors, or simply be overkill for the problem at hand.

    C++17 introduced std::optional<T>, which can either have a value of type T, or none at all.
    To check if an std::optional has a value, we can use <identifier.has_value() or use implicit bool conversion (i.e. just if(identifier)).

    Accessing the value of an std::optional is very similar to that of a pointer.
    It can be de-referenced, accessed with .value(), or use .value_or(value), which will provide the argument if the optional does not have a value.

    A std::optional has value semantics, meaning it actually contains its value, and assignment copies the value. 
    If we return a std::optional by value, the std::optional (including the contained value) is copied back to the caller. 
        This means we can return a value from the function back to the caller using std::optional

    While std::optional is convenient and removes the need for a sentinel, the caller does not know why something went wrong, and cannot de-reference it safely without checking that it has a value first.

std::optional for function parameter
    Rather than using a nullptr argument to function as an optional parameter (which requires an lvalue), std::optional can also serve the purpose of an optional in-parameter.
    This clearly documents that the parameter is optional, and accepts rvalues since std::optional makes a copy of them.

    std::optional does not support references, and are best used when T would be passed by value anyways.
        Use const *T if it is expensive to copy.
*/

#include <iostream>
#include <optional> // for std::optional (C++17)

// Our function now optionally returns an int value
std::optional<int> doIntDivision(int x, int y)
{
    if (y == 0)
        return {}; // or return std::nullopt
    return x / y;
}

int main()
{
    std::optional<int> result1 { doIntDivision(20, 5) };
    if (result1) // if the function returned a value
        std::cout << "Result 1: " << *result1 << '\n'; // get the value
    else
        std::cout << "Result 1: failed\n";

    std::optional<int> result2 { doIntDivision(5, 0) };

    if (result2)
        std::cout << "Result 2: " << *result2 << '\n';
    else
        std::cout << "Result 2: failed\n";


    std::optional<int> o1 { 5 };            // initialize with a value
    std::optional<int> o2 {};               // initialize with no value
    std::optional<int> o3 { std::nullopt }; // initialize with no value

    std::cout << *o1;             // dereference to get value stored in o1 (undefined behavior if o1 does not have a value)
    std::cout << o2.value();      // call value() to get value stored in o2 (throws std::bad_optional_access exception if o2 does not have a value)
    std::cout << o3.value_or(42); // call value_or() to get value stored in o3 (or value `42` if o3 doesn't have a value)


    return 0;
}