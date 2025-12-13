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

/*
Expressions
    An expression is a non-empty sequence of literals, variables, operators, and function calls that calculates a value.
    The process of executing an expression is an evaluation, and the value calculated is a result or return value.
    
    Expressions can also have side effects. 
        While "x = 5" evaluates to x, it has the side effect of assigning 5 to the variable identified as x
        In many cases, we use an expression for the side effect rather than the value it produces
        An expression statement is a statement that consists of an expression followed by a semicolon. 
            When the expression statement is executed, the expression will be evaluated.
            The value of the expression itself is discarded. Ex: For x = 5, the operator= value is discarded

    Simplifying a bit, a subexpression is an expression used as an operand. 
        For example, the subexpressions of x = 4 + 5 are x and 4 + 5. The subexpressions of 4 + 5 are 4 and 5.
    A full expression is an expression that is not a subexpression. 
    In casual language, a compound expression is an expression that contains two or more uses of operators. 
        x = 4 + 5 is a compound expression because it contains two uses of operators (operator= and operator+). 2 and 2 + 3 are not compound expressions.
*/


#include <iostream>;

int main() {
    std::cout << "Hello world!"; // literal text
    int x { 5 }; // copy the literal 5 into the memory location associated with variable identified as x

    std::cout << 5 << '\n'; // print the value of a literal
    /*
    2               // 2 is a literal that evaluates to value 2
    2 + 3           // 2 + 3 uses operator+ to evaluate to value 5
    x = 4 + 5       // 4 + 5 evaluates to value 9, which is then assigned to variable x
    */
    return 0;
}