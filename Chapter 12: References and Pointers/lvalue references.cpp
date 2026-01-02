/*
lvalue references
    A reference is an alias for an existing object. This means a reference can be used to read or modify the object being referenced.
    Modern C++ contains lvalue references and rvalue references. Note that references are not objects, and cannot be used when an object is required.

    An lvalue reference acts as a reference to an existing lvalue. They can be identified by an & in the type specifier.
    // regular types
    int        // a normal int type (not an reference)
    int&       // an lvalue reference to an int object
    double&    // an lvalue reference to a double object
    const int& // an lvalue reference to a const int object

    Const and non-const lvalue references are differentiated by if the value they reference are const or not.
    We can create an lvalue reference variable from an lvalue reference. 
        An lvalue reference variable is a variable that acts as a reference to an lvalue (usually another variable).
    
    Much like constants, references must be initialized. When initialized with a function or object (sometimes known as the referent), the reference is considered bound to it.
    Non-const lvalue references can only be bound to a modifiable lvalue. Otherwise, we would be able to use the reference to alter a const lvalue.
    Lvalue references to void are disallowed (this would be pointless anyways).

    Once bound, a reference cannot be reseated onto a different object. Reference variables also follow the same scoping and duration rules that normal variables do.
    Trying to initialize a reference to a reference results in just referring to the original referent.

    Generally, a reference will only bind to an object whose type matches the referenced type.
    If you try to bind a reference to an object that does not match its referenced type, the compiler will try to implicitly convert the object to the referenced type and then bind the reference to that.
    Since the result of a conversion is an rvalue, and a non-const lvalue reference can’t bind to an rvalue, trying to bind a non-const lvalue reference to an object that does not match its referenced type will result in a compilation error.

Dangling Reference
    Since the lifetime of a reference and referent are independent (with one exception), it is possible for the referent to be destroyed before the reference.
    This leaves the reference as "dangling", referring to an object that no longer exists.
*/

#include <iostream>

int main()
{
    int x { 5 };    // x is a normal integer variable
    int& ref { x }; // ref is an lvalue reference variable that can now be used as an alias for variable x
    // inf &ref is also fine, but better to put the ampersand with the type rather than the identifier.

    std::cout << x << '\n';  // print the value of x (5)
    std::cout << ref << '\n'; // print the value of x via ref (5)

    int x { 5 };
    int& ref { x };            // okay: referenced type (int) matches type of initializer

    // double d { 6.0 };
    // int& invalidRef { d };     // invalid: conversion of double to int is narrowing conversion, disallowed by list initialization
    // double& invalidRef2 { x }; // invalid: non-const lvalue reference can't bind to rvalue (result of converting x to double)

    return 0;
}