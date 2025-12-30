/*
Conditional Operator
    The conditional operator, sometimes called an arithmetic "if", appears as an "?:".
    It is also called the ternary operator, because it is the only existing operator that is ternary (i.e. that accepts 3 operands). 

    It takes the following form: condition ? expression1 : expression2;
    When the condition is true, it evaluates expression 1. otherwise, it evaluates expression 2.

    Since the operator is evaluated as a part of an expression, it can be placed where statements cannot, such as part of an initialization.

    Using the conditional operator with conditions and operands that have multiple parts can lead to some parts being evaluated in orders that do not align with the programmer's intentions
    To avoid this, parenthesize the entire conditional operation (including operands) when used in a compound expression (an expression with other operators).
        For readability, consider parenthesizing the condition if it contains any operators (other than the function call operator).

    In order to abide with type checking, the type of the second and third operand (expressions 1 and 2) must match. The compiler can find ways to do this, but it is best for the programmer to do so.

    Use cases for conditional operator:
        Initializing an object with one of two values.
        Assigning one of two values to an object.
        Passing one of two values to a function.
        Returning one of two values from a function.
        Printing one of two values.
    
    Keep it simple when using the conditional operator, as they can be hard to read otherwise.
*/

#include <iostream>

int getValue()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
    int x { getValue() };
    int y { getValue() };
    int max { (x > y) ? x : y }; // an if-statement would be impossible to place inside the initializer
    std::cout << "The max of " << x <<" and " << y << " is " << max << ".\n";

    return 0;
}