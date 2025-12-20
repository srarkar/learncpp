/*
    std::string_view   
        When initializing an std::string with a literal, we must allocate memory for the std::string object, copy over the data from the initializer
        If we only printed this data, it would be inefficient to do so much work (since std::string is not a fundamental data type) compared to the result

        C++17 introduced std::string_view in the <string_view> header, which provides a read-only view of to an already existing string.
        Best practice is to use std::string_view when we need to just read/access a string without modifying it, especially for function parameters

        Note that they can be initialized with a C-style string, std::string (both of which will be implicity converted), or another std::string_view.
        On the other hand, an std::string_view is not implicitly converted to an std::string since the copy operation is expensive
            If intentional, we can convert an existing string_view to a string via static_cast, or an initializer
        
        Changing the std::string_view to another string does not modify the previous one, but simply points the object to the new string instead

        We can declare one using an "sv" suffix added to a c-style string literal. Since it is read-only, it also supports constexpr (unlike std::string).
 
*/


#include <iostream>
#include <string>

void printString(std::string str) // str makes a copy of its initializer
{
    std::cout << str << '\n';
}

void printSV(std::string_view str) // now a std::string_view
{
    std::cout << str << '\n';
}

int main()
{
    std::string s{ "Hello, world!" }; // s makes a copy of its initializer, just to print it and be destroyed afterwards
    std::cout << s << '\n';
    printString(s); // we make two copies: one for s, and one for the parameter

    std::string_view s{ "Hello, world!" }; // now a std::string_view. we do not copy the literal, but rather have read-only access to it
    printSV(s);

    std::string name { "Alex" };
    std::string_view sv { name }; // sv is now viewing name
    std::cout << sv << '\n'; // prints Alex

    sv = "John"; // sv is now viewing "John" (does not change name)
    std::cout << sv << '\n'; // prints John

    std::cout << name << '\n'; // prints Alex

    using namespace std::string_literals;      // access the s suffix
    using namespace std::string_view_literals; // access the sv suffix

    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal
    std::cout << "moo\n"sv; // sv suffix is a std::string_view literal



    return 0;
}