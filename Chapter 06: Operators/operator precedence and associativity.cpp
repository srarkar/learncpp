/*
Operator Precedence
    When evalutating a complex expression like 2 + 3 * 4, how do we decide between that being (2 + 3) * 4 or 2 + (3 * 4)?
    At compile-time, the compiler determines how operands are grouped with operands by following operator precedence and associativity.
    Those operators with a higher precedence are grouped first. 1 is the highest precedence level, and 17 is the lowest.
    
    But what about when we have operators of the same precedence? Should 2 + 4 + 1 be grouped as (2 + 4) + 1 or 2 + (4 + 1).
    In this case, we then look at the operator's associativity. If the associativity of that precedence group is left-to-right, then we would group (2 + 4) + 1. 

    Parentheses let us decide the order of groupings, since parantheses have a very high operator precedence (2). 
    They also help make complex expressions easier to understand. Even if the value of an expression is known since operator precedence takes care of it, paratheses make it much easier to break down the parts and order of evaluation.
    Expressions and function calls should be written in a way that is not dependent on operand or argument evaluation order.
*/


#include <iostream>

int getValue()
{
    std::cout << "Enter an integer: ";

    int x{};
    std::cin >> x;
    return x;
}

void printCalculation(int x, int y, int z)
{
    std::cout << x + (y * z);
}

int main()
{
    int a{ getValue() }; // will execute first
    int b{ getValue() }; // will execute second
    int c{ getValue() }; // will execute third

    printCalculation(a, b, c); // this line is now unambiguous, as opposed to "printCalculation(getValue(), getValue(), getValue());""

    return 0;
}