/*
Struct Miscellany
    A struct can be defined inside another if it is only to be used within the outer struct. They can also be defined separately, and one struct can be a member of another.

    In most cases, we want our structs (and classes) to be owners. 
        The easiest way to enable this is to ensure each data member has an owning type (e.g. not a viewer, pointer, or reference).
        We want to avoid a dangling member that would lead to undefined behavior.
        This is why string members are almost always std::string and not std::string_view (which is a viewer)
    
    The size of a struct is greater than or equal to the sum of the size of its members. It can be more due to a concept called padding, where gaps are added into the structure to improve performance.
    Padding can be minimized by declaring members in the order of decreasing size, as the compiler cannot reorder them.
*/

#include <iostream>
#include <string>
#include <string_view>

// struct Employee
// {
//     int id {};
//     int age {};
//     double wage {};
// };

// struct Company
// {
//     int numberOfEmployees {};
//     Employee CEO {}; // Employee is a struct within the Company struct
// };

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

struct Company
{
    int numberOfEmployees {};
    Employee CEO {}; // Employee is a struct within the Company struct
};

struct Owner
{
    std::string name{}; // std::string is an owner
};

struct Viewer
{
    std::string_view name {}; // std::string_view is a viewer
};

// getName() returns the user-entered string as a temporary std::string
// This temporary std::string will be destroyed at the end of the full expression
// containing the function call.
std::string getName()
{
    std::cout << "Enter a name: ";
    std::string name{};
    std::cin >> name;
    return name;
}

int main()
{
    Owner o { getName() };  // The return value of getName() is destroyed just after initialization
    std::cout << "The owners name is " << o.name << '\n';  // ok

    Viewer v { getName() }; // The return value of getName() is destroyed just after initialization
    std::cout << "The viewers name is " << v.name << '\n'; // undefined behavior

    Company myCompany{ 7, { 1, 32, 55000.0 } }; // Nested initialization list to initialize Employee
    std::cout << myCompany.CEO.wage << '\n'; // print the CEO's wage

    return 0;
}