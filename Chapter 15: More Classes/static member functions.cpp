/*
Static Member Functions
    A private static member variable is not directly accessible outside of a class using the scope resolution operator and the class type's name.
    Instead, we can use a public static member function to access the value.

    Since static member functions are not tied to an object, they have no "this" pointer.
    They can directly access other static members but not non-static members.
        This is because non-static members must belong to a class object, and static member functions have no class object to work with.
    As with other member functions, static member functions can be defined outside of the class (as long as they are declared inside it).

Monostates
    A class with all static types is known as a monostate, or pure static class.
    All static members are only initialized once, meaning that multiple copies of a pure static class is not possible without cloning and renaming the class.
    Also, these static members share the same downside as normal global variables in that they can be modified and accessed from anywhere.

    Instead of writing a class with all static members, consider writing a normal class and instantiating a global instance of it (global variables have static duration).

    Monostates are quite similar to namespaces, although they have access control while namespaces do not.
        If these access controls are not needed, a namespace might be a better choice.

Static Constructors
    Unlike some other modern languages, C++ does not support static constructors.
    No constructor is needed for direct initialization, as it can be done at the point of definition.

    If the value requires executing code, this can be done in multiple ways.
        One such way is to  is to use a function to create an object, fill it with data, and return it to the caller.
        The returned value can be used to initialize the variable. This works with both statics and non-statics.
        Another option is to use a lambda.
*/

#include <iostream>


class Something
{
private:
    static inline int s_value { 1 };

public:
    static int getValue() { return s_value; } // static member function
};

struct Chars
{
    char first{};
    char second{};
    char third{};
    char fourth{};
    char fifth{};
};

struct MyClass
{
	static inline Chars s_mychars { 'a', 'e', 'i', 'o', 'u' }; // initialize static variable at point of definition
    static Chars generate()
    {
        Chars c{}; // create an object
        c.first = 'a'; // fill it with values however you like
        c.second = 'e';
        c.third = 'i';
        c.fourth = 'o';
        c.fifth = 'u';

        return c; // return the object
    }
};

int main()
{
    std::cout << Something::getValue() << '\n';
    std::cout << MyClass::s_mychars.third; // print i
}