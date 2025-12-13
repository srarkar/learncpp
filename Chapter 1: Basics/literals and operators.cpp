/*
Literals
    A literal, or literal constant, is a fixed value that has been inserted directly into source code.
    They have a value and type (like a variable), but this value cannot be changed (unlike a variable)

Operators
    An operation is a process involving zero or more input values, known as operands, that produces an output value, often called a return value.
    The operation to be performed is denoted by a symbol called an operator
    Outside of the familiar ones such as =, +, <<, >>, some are keywords such as new, delete, and throw

    The number of operands an operator accepts (known as arity) varies, and gives birth to 4 categories:
        - Unary operators apply to one operand. For example, operator- can be applied to a single value of 5 to have a return value of -5
        - Binary operators apply to 2 operands. For example, 1 + 2 has return value 3
        - Ternary operators apply to 3 operands. There is only one such operator, known as the conditional operator.
        - Nullary operators apply to 0 operands. There is only one such operator, which is throw

        Operators can have multiple contexts. For example, operator- can be applied to 1, or 2 operands (sign inversion vs subtraction)
*/


#include <iostream>;

int main() {
    std::cout << "Hello world!"; // literal text
    int x { 5 }; // copy the literal 5 into the memory location associated with variable identified as x

    std::cout << 5 << '\n'; // print the value of a literal
    return 0;
}