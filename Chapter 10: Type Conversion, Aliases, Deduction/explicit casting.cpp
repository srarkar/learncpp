/*
    Explicit type conversion
        C++ has 5 types of cast
            - static_cast, which performs compile-time type conversions between related types (safe)
            - dynamic_cast, which performs runtime type conversions on pointers or references in an polymorphic (inheritance) hierarchy	(safe)
            - const_cast, which adds or removes const (safe only for adding const)
            - reinterpret_cast, which reinterprets the bit-level representation of one type as if it were another type (unsafe)
            - C-style cast, which performs some combination of static_cast, const_cast, or reinterpret_cast (unsafe)
        
        static_cast should be used in most cases. Static casting a value to another type of value returns a temporary object that has been direct-initialized with the converted value.
        It provides compile-time checking, and will prevent many kinds of dangerous conversions (unlike C-style casting)
        When involved with narrowing conversions, it is best to use static_cast to make it explicit that it is intended to happen.
*/

#include <iostream>

int main()
{
    char c { 'a' };
    std::cout << static_cast<int>(c) << '\n'; // prints 97 rather than a

    return 0;
}