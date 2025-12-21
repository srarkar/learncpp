/*
Increment and Decrement Operators
    Increasing a value by 1 and decreasing a value of 1 are such common operations that they have their own specific operators.
    ++ and --. They can be placed before (pre-increment and pre-decrement) or after (post-increment and post-decrement) its operator.

    The prefix version first increments/decrements the value of the operand, and then the expression it is a part of is evaluated.
    The postfix is trickier. It creates a copy of the old value, updates the operand, but uses the old (un-incremented/un-decremented) value in the expression.
        Due to these additional steps, the postfix version may be less performant than the prefix version.
    Note that the value being modified is a side effect, since it primarily returns either the old or the new value.
*/

#include <iostream>

int add(int x, int y) {
    return x + y;
}

int main()
{
    int x { 5 };
    int y { 5 };
    std::cout << x << ' ' << y << '\n';
    std::cout << ++x << ' ' << --y << '\n'; // prefix
    std::cout << x << ' ' << y << '\n';
    std::cout << x++ << ' ' << y-- << '\n'; // postfix
    std::cout << x << ' ' << y << '\n';

    int value{ add(x, ++x) }; // undefined behavior, due to the side effect of the pre-increment.
    // value's contents depends on what order your compiler evaluates the function arguments in

    std::cout << value << '\n'; // unknown value! if x was originally 5, this could be 11 or 12

    return 0;
}

