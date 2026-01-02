/*
Value Categories (lvalue and rvalue)
    Expressions have two properties:
        The type of an expression is the type of value / object / function that results from the evaluated expression.
        The value category of an expression indicates whether the expression resolves to a value, object, or function.
            This helps the compiler determine where an expression can legally appear to align with correct syntax.

    Before C++11, the only two value categories were lvalue and rvalue.
    C++ 11 added gvalue, prvalue, and xvalue to support move semantics.

lvalue
    An lvalue is an expression that evaluates to an identifiable object or bit field.
        An entity with an identity can be differentiated from similar ones, usually by comparing their addresses.
    Entities with identities can be accessed via an identifier, reference, or pointer, and typically have a lifetime longer than a single expression or statement.

    lvalues have two subtypes:
        - modifiable
        - non-modifiable (i.e. const or constexpr)

rvalue
    rvalues are expressions that are not lvalues -- they evaluate to a value. This includes literals (but not C-style string literals, which decay to a pointer since they're effectively arrays) and temporary objects.
    rvalues are not identifiable and must be used immediately, only existing in the scope of the expression they are used in.

    Operators expect their operands to be rvalues unless otherwise specified.

Something like the assigment operator (=) requires its left operand to be an lvalue, since it needs to be a modifiable, identifiable object that can be given a value.
When an lvalue is provided when an rvalue is expected, the lvalue is converted by being evaluated to produce its value. This value is an rvalue that is used as an operand.

*/

#include <iostream>
#include <string>

// T& is an lvalue reference, so this overload will be preferred for lvalues
template <typename T>
constexpr bool is_lvalue(T&)
{
    return true;
}

// T&& is an rvalue reference, so this overload will be preferred for rvalues
template <typename T>
constexpr bool is_lvalue(T&&)
{
    return false;
}

// A helper macro (#expr prints whatever is passed in for expr as text)
#define PRINTVCAT(expr) { std::cout << #expr << " is an " << (is_lvalue(expr) ? "lvalue\n" : "rvalue\n"); }

int getint() { return 5; }

int main()
{
    PRINTVCAT(5);        // rvalue
    PRINTVCAT(getint()); // rvalue
    int x { 5 };
    PRINTVCAT(x);        // lvalue
    PRINTVCAT(std::string {"Hello"}); // rvalue
    PRINTVCAT("Hello");  // lvalue
    PRINTVCAT(++x);      // lvalue
    PRINTVCAT(x++);      // rvalue
}