/*
Compile-Time Programming
    Expressions by default evaluate at runtime. But in some cases, the compiler can choose to evaluate it at compile-time for the sake of optimization.

    There are also cases where it is required for an expression to have a known value at compile-time.
    Constexpr variables require an initializer that can be evaluted at compile-time.
    Some other cases are a non-type template argument and the defined length of an std::array

    The as-if rule is beneficial for performance, but it relies on the compiler to choose what is to be evaluated at compile-time.
    Compile-time programming involves the usage of language features (by the programmer) that result in compile-time evaluation.
        It creates predictability that some portion of code will either be evaluated at compile-time time, or the compiler will halt (rather than silently evalutating at runtime)
    This can also improve code quality and avoid undefined behavior that compilers may miss.
    All compile-time programming makes use of constant expressions.

Constant Expressions
    A constant expression is a non-empty sequence of literals, constant variables, operators, and function calls, all of which must be evaluatable at compile-time.
    That is, every part of a constant expression must be able to be evaluated at compile-time.
        The opposite of this is a non-constant expression, or a runtime expression
    Constant expressions usually contain:
        Literals
        Most operators with constant expression operands (e.g. 3 + 4, 2 * sizeof(int)).
        Const integral variables with a constant expression initializer (e.g. const int x { 5 };). This is a historical exception -- in modern C++, constexpr variables are preferred.
        Constexpr variables
        Constexpr function calls with constant expression arguments
    
    Even if a constant expression can be evaluated at compile-time, this does not guarantee that it will be. 
    The compiler is only required to evaluate constant expressions at compile-time in contexts that require a constant expression.
        An expression that must be evaluated at compile-time is known as a manifestly constant-evaluated expression (rarely heard of, but could be in some documentation)

    
    The likelihood that an expression is fully evaluated at compile-time can be categorized as follows:
        Never: A non-constant expression where the compiler is not able to determine all values at compile-time.
        Possibly: A non-constant expression where the compiler is able to determine all values at compile-time (optimized under the as-if rule).
        Likely: A constant expression used in a context that does not require a constant expression.
        Always: A constant expression used in a context that requires a constant expression.

Constexpr
    The const keyword does not mandate that a variable is usable in a constant expression, nor does its creation of compile-time constant variables extend to non-integral types.
    It is also not always immediately clear whether or not a variable is usable in a constant expression or not, depending on how it is initialized.

    The constexpr keyword dictates that the variable is always a compile-time constant. 
        Thus, it must be initialized with a constant expression. Failing to do so will cause a compilation error.
    In addition, constexpr works for non-integral types. constexpr is implicitly const, but not vice versa

    A constexpr function is one that that can called inside a constant expression. The function must evaluate at compile-time when the expression it is a part of evaluates.
        All arguments must be constant expressions, naturally.

*/

#include <iostream>

int getNumber()
{
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y; // can only execute at runtime

    return y;      // this return expression is a runtime expression
}
int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

constexpr int cmax(int x, int y) // this is a constexpr function
{
    if (x > y)
        return x;
    else
        return y;
}

int main() {
    const double x { 1.2 };
    const double y { 3.4 };
    const double z { x + y }; // x + y may evaluate at runtime or compile-time, depending on if their values are known or not

    // constexpr int x {expr}; // expr must evaluate at compile-time 

    // Literals can be used in constant expressions
    5;                           // constant expression
    1.2;                         // constant expression
    "Hello world!";              // constant expression

    // Most operators that have constant expression operands can be used in constant expressions
    5 + 6;                       // constant expression
    1.2 * 3.4;                   // constant expression
    8 - 5.6;                     // constant expression (even though operands have different types)
    sizeof(int) + 1;             // constant expression (sizeof can be determined at compile-time)

    // The return values of non-constexpr functions can only be used in runtime expressions
    // getNumber();                 // runtime expression
    // five();                      // runtime expression (even though the return expression is a constant expression)

    // Operators without constant expression operands can only be used in runtime expressions
    std::cout << 5;              // runtime expression (std::cout isn't a constant expression operand)

    // Const integral variables with a constant expression initializer can be used in constant expressions:
    const int a { 5 };           // a is usable in constant expressions
    const int b { a };           // b is usable in constant expressions (a is a constant expression per the prior statement)
    const long c { a + 2 };      // c is usable in constant expressions (operator+ has constant expression operands)

    // Other variables cannot be used in constant expressions (even when they have a constant expression initializer):
    int d { 5 };                 // d is not usable in constant expressions (d is non-const)
    const int e { d };           // e is not usable in constant expressions (initializer is not a constant expression)
    const double f { 1.2 };      // f is not usable in constant expressions (not a const integral variable)

    const int x { 3 + 4 }; // constant expression 3 + 4 must be evaluated at compile-time
    int y { 3 + 4 };       // constant expression 3 + 4 may be evaluated at compile-time or runtime

    constexpr double gravity { 9.8 }; // ok: 9.8 is a constant expression
    constexpr int sum { 4 + 5 };      // ok: 4 + 5 is a constant expression
    constexpr int something { sum };  // ok: sum is a constant expression

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    // constexpr int myAge { age };      // compile error: age is not a constant expression
    // constexpr int f { five() };       // compile error: return value of five() is not constexpr
    constexpr double d { 1.2 }; // d can be used in constant expressions!

    int m1 { max(5, 6) };            // ok
    const int m2 { max(5, 6) };      // ok
    // constexpr int m3 { max(5, 6) };  // compile error: max(5, 6) not a constant expression

    int m4 { cmax(5, 6) };           // ok: may evaluate at compile-time or runtime
    const int m5 { cmax(5, 6) };     // ok: may evaluate at compile-time or runtime
    constexpr int m6 { cmax(5, 6) }; // okay: must evaluate at compile-time

    return 0;

    return 0;

}