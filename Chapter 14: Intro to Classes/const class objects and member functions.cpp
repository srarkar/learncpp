/*
Const Class Objects
    Class type objects can be made const, and must be initialized when created.
    Once made const, any attempt to alter the data values of the object's members is disallowed. 
    
    Const objects also cannot call non-const member functions. 
    As such, member functions that we want to allow our object to call must also be const.
    A const member function guarantees it will not modify the object or itself call a non-const member function.
    A const member function may still modify objects that aren’t the implicit object, call const member functions, and call non-member functions.

    Const member functions may also be called on non-const objects, meaning it is best to make a member function const if it doesn't modify the object at hand.
        It is possible to overload a member function to have a const and non-const version of the same function, since const is part of a function's signature.

    Although instantiating const local variables is one way to create const objects, a more common way to get a const object is by passing an object to a function by const reference.

*/

#include <iostream>

struct Date
{
    int year {};
    int month {};
    int day {};

    void print() const
    {
        std::cout << year << '/' << month << '/' << day << '\n';
    }
};

int main()
{
    const Date today { 2020, 10, 14 }; // const

    today.print();  // compile error: can't call non-const member function

    return 0;
}