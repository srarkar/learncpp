/*
Structs and Members
    Structs allow us to bundle multiple variables into a single type. The variables that belong to a struct are known as its data members, or member variables.
        In C++, a member is a variable, function, or type that belongs to a struct (or class). All members must be declared within the struct (or class) definition.
    
    To access a member variable, we use the member selection operator (.) between the struct identifier and the member name.
*/

/*
Aggregate Data Types
    Generally, aggregate data types are those that contain multiple data members. Some may contain a variety of data types (structs) while others are limited to all members sharing a type (arrays).
    In C++, aggregates are either C-style arrays, or a class type (struct, union, class) that has no user-declared constructors, no private or protected non-static data members, and no virtual functions.

    With structures, we can perform aggregate initialization in order to initialize multiple members in the same line.
    This can be done with copy-list initialization or list initialization (preferred)
*/

#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

int main() {
    Employee bob {};
    bob.age = 50; // unc

    std::cout << "bob's age: " << bob.age << '\n';
    
    return 0;
}