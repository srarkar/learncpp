/*
Type Deduction
    Type deduction, also known as type inference, allows a compiler to deduce the type of an object from its initializer.
    It can be invoked with the auto keyword in place of the object's type.
    Also, type deduction doesn't work for function parameters. It may still compile after C++20, due to function templates (not type deduction).

    The compiler needs something to actually deduce the type from. Objects with no initializer, an empty initializer, or incomplete types (like void) cannot be deduced.
    Type deduction will usually drop the const (if the initializer is another const variable).

Downsides
    Type deduction can obscure an object's type information. Unexpected type changes in the initializer will directly cause unexpected changes in the deduced object.
*/

/*
Return Type Deduction
    The compiler already has to deduce types from certain return statements. Thus, the auto keyword was extended to apply to function return types.
    Note that even when using auto, all return statements within the function must return the same type.
    
    
    The main benefit lies in the negation of the risk of a mismatched return type, which could lead to unexpected conversions.

Downsides
    Functions with an auto return type must be fully defined before they are used -- forward declarations are not sufficient.
    Also, it is often not immediately obvious what a function's return type should be, so using auto can obscure understanding of the function.

Trailing Return Type Syntax
    This is where the function's return type is specified after the rest of the function prototype.
    In this case, no type deduction is performed; rather, auto is just part of the trailing return type syntax.

    It is primarily useful for readability and alignment. 
    Also, if we have a function whose return type must be deduced based on the type of the function parameters, a normal return type will not suffice.
*/    



#include <string>
#include <string_view>

auto add(int x, int y)
{
    return x + y;
}

// trailing return syntax
auto add2(int x, int y) -> int
{
  return (x + y);
}

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