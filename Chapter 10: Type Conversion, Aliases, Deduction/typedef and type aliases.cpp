/*
Type Aliases
    using is a keyword used to define aliases for existing data types.
    Using the alias is equivalent to using the name of the original type.
    The compiler will not prevent semantic errors and the aliases can be used interchangably, meaning these aliases are not type safe.

    They follow the same scope as variable identifiers. They have global scope if defined in the global namespace, and block scope otherwise.
    They can be kept in a header file.

    There are three naming conventions for type aliases:
        - Ending in a "_t" suffix. Inherited from C, and often used for globally scoped type names.
        - Ending in a "_type" suffix, used by some standard library types (such as std::string) for nested type aliases
        - no suffix
    Modern C++ indicates to use a capital letter with no suffix.

    Aliases are useful to make complex types easier to understand. 

Typedef
    An older way to create aliases that was inherited from C is the typedef.
    Note that it does not create a new type, despite the somewhat misleading name. Prefer type aliases.
*/

#include <iostream>

int main()
{
    // The following aliases are identicalzz
    typedef long Miles;
    using Miles = long;
    
    using Distance = double; // define Distance as an alias for type double. note the capital letter

    Distance milesToDestination{ 3.4 }; // defines a variable of type double

    std::cout << milesToDestination << '\n'; // prints a double value

    return 0;
}