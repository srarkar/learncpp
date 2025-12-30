/*
If Statements
    An if statement allows us to execute one (or more) lines of code only if some condition is true.

    The simplest if statement takes the following form:
        if (condition) true_statement;
    A condition (also called a conditional expression) is an expression that evaluates to a Boolean value.

    Non-zero values evalute to true
*/


#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    if (x == 0)
        std::cout << "The value is zero\n";
    else if (x > 0)
        std::cout << "The value is positive\n";
    else
        std::cout << "The value is negative\n";

    int y { 4 };

    if (y) // non-zero is evaluated as true
        std::cout << "hi\n";
    else
        std::cout << "bye\n";

    return 0;
}