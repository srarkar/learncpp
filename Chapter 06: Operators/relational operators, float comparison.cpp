/*
Relational operators
    Relational operators allow for comparisons between two values. The 6 of them are >, >=, <, <=, ==, and !=.

    By default, condition inside an if-statement or conditional operator evaluate as booleans.

Floating Point Comparison
    Comparing floating point numbers using the relational operators is risky, as floating point numbers are not precise.
    Rounding errors can mean the value stored in memory is slightly more or less than expected, which throws off the comparisons.

    This is most true when comparing two floating point numbers that are alomst identical. 
        It is worth considering if the program being wrong when the two values are very close is acceptable, in the case of >, >=, <, <=.
    Things get tricker with the == and !=. 
        One of the few times when it is okay to use them for floating points is when comparing a floating point literal with a variable of the same type that was initialized with a literal.
        Keep digits of precision in mind, as per the data type in question (float is 6 to 9, double is ~15?)
    It is mostly not safe to compare floating point literals of different types. For example, comparing 9.8f to 9.8 will return false.

    Instead, some programmers use epsilon (some very small value) as a "good-enough" estimate of when two values are equal. 
*/

/*
Logical Operators
    Often, we want to verify multiple conditons at once. The 3 such operators at our disposal is !, &&, and ||.
    The logical NOT evalutes as true when its operand is false and vice versa.
    The logical AND (&&) evaluates as true only when both its operands are true, false otherwise.
    The logical OR (||) evaluates as true so long as at least one of its two operands is true, false otherwise.

Short Circuit Evaluation
    When we have two operands with a logical OR or AND, evaluating the first one can sometimes guarantee the value of the expression.
    For example, if the first operand in an OR is true, then we do not need to evaluate the second. The same is true for AND, but the first one evaluating to false.
    This is primarily for optimization purposes. 
    In addition, it means that operands should not have side effects (such as a postfix increment), since it is possible for an operand to not be evaluated if the expression short circuits.
*/

#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    if (x == y)
        std::cout << x << " equals " << y << '\n';
    if (x != y)
        std::cout << x << " does not equal " << y << '\n';
    if (x > y)
        std::cout << x << " is greater than " << y << '\n';
    if (x < y)
        std::cout << x << " is less than " << y << '\n';
    if (x >= y)
        std::cout << x << " is greater than or equal to " << y << '\n';
    if (x <= y)
        std::cout << x << " is less than or equal to " << y << '\n';

    constexpr double d1{ 100.0 - 99.99 }; // should equal 0.01 mathematically
    constexpr double d2{ 10.0 - 9.99 }; // should equal 0.01 mathematically

    if (d1 == d2)
        std::cout << "d1 == d2" << '\n';
    else if (d1 > d2)
        std::cout << "d1 > d2" << '\n';
    else if (d1 < d2)
        std::cout << "d1 < d2" << '\n';

    if (!x > y) // wrong! the '!' evaluates before the >
        std::cout << x << " is not greater than " << y << '\n';
    else
        std::cout << x << " is greater than " << y << '\n';

    return 0;
}