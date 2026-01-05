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
    This can be done with copy-list initialization or list initialization (preferred).

    If the initializer list is missing some members, then either the default member initializer is used, or the member is copy-initialized from an empty initializer list.
    The copy-initialization will usually perform list initialization, or use a default constructor for class types, even when a list constructor is available.
        This means we can generally use an empty initialization list to value-initialize all members of the struct:
    
    While standard list initialization fills the members in the order they appear in the struct, members can also be specified with designated initializers.
    These must match the order they appear in the struct definition.

    Initialization Summary
        If an aggregate is defined with an initialization list:
            If an explicit initialization value exists, that explicit value is used.
            If an initializer is missing and a default member initializer exists, the default is used.
            If an initializer is missing and no default member initializer exists, value initialization occurs.

        If an aggregate is defined with no initialization list:
            If a default member initializer exists, the default is used.
            If no default member initializer exists, the member remains uninitialized.
        Members are always initialized in the order of declaration.
*/

#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {70000};
    double misc {};
};

struct Foo
{
    int a{ };
    int b{ };
    int c{ };
};

struct Something
{
    int x;       // no default initialization value (bad)
    int y {};    // value-initialized by default
    int z { 2 }; // explicit default value
};


// overloading the insertion operator to print a struct
std::ostream& operator<<(std::ostream& out, const Employee& e)
{
    out << e.id << ' ' << e.age << ' ' << e.wage;
    return out;
}

int main() {
    Employee bob {};
    bob.age = 50; // unc

    std::cout << "bob's age: " << bob.age << '\n';

    // memberwise initialization
    Employee frank = { 1, 32, 60000.0, 50.0 }; // copy-list initialization using braced list
    Employee joe { 2, 28, 45000.0, 60.0 };     // list initialization using braced list (preferred)

    Employee bill { 2, 28 }; // bill.misc will be value-initialized to 0.0
    
    Foo f1{ .a{ 1 }, .c{ 3 } }; // ok: f1.a = 1, f1.b = 0 (value initialized), f1.c = 3
    Foo f2{ .a = 1, .c = 3 };   // ok: f2.a = 1, f2.b = 0 (value initialized), f2.c = 3
    //Foo f3{ .b{ 2 }, .a{ 1 } }; // error: initialization order does not match order of declaration in struct

    // initialize a struct with another struct
    Foo foo { 1, 2, 3 };

    Foo x = foo; // copy-initialization
    Foo y(foo);  // direct-initialization
    Foo z {foo}; // direct-list-initialization

    Something s1;             // No initializer list: s1.x is uninitialized, s1.y and s1.z use defaults
    Something s2 { 5, 6, 7 }; // Explicit initializers: s2.x, s2.y, and s2.z use explicit values (no default values are used)
    Something s3 {};          // Missing initializers: s3.x is value initialized, s3.y and s3.z use defaults
    
    return 0;
}