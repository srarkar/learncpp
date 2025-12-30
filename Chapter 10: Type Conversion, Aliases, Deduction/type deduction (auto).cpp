/*
Type Deduction
    Type deduction, also known as type inference, allows a compiler to deduce the type of an object from its initializer.
    It can be invoked with the auto keyword in place of the object's type.

    The compiler needs something to actually deduce the type from. Objects with no initializer, an empty initializer, or incomplete types (like void) cannot be deduced.
    Type deduction will usually drop the const (if the initializer is another const variable).

Downsides
    Type deduction can obscure an object's type information. Unexpected type changes in the initializer will directly cause unexpected changes in the deduced object.
*/
#include <string>
#include <string_view>

int main()
{
    auto d { 5.0 }; // 5.0 is a double literal, so d will be deduced as a double
    auto i { 1 + 2 }; // 1 + 2 evaluates to an int, so i will be deduced as an int
    auto x { i }; // i is an int, so x will be deduced as an int

    using namespace std::literals; // easiest way to access the s and sv suffixes

    auto s { "Hello, world" }; // s will be type const char*, not std::string
    
    auto s1 { "goo"s };  // "goo"s is a std::string literal, so s1 will be deduced as a std::string
    auto s2 { "moo"sv }; // "moo"sv is a std::string_view literal, so s2 will be deduced as a std::string_view

    // auto a;           // The compiler is unable to deduce the type of a
    // auto b { };       // The compiler is unable to deduce the type of b
    // auto c { foo() }; // Invalid: c can't have type incomplete type void
    

    return 0;
}