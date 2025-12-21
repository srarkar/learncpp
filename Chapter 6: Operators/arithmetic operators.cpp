/*
Arithmetic Operators
    The two unary arithmetic operators are + and -. The unary - operator returns its operand multiplied by -1. The unary plus returns its operand unchanged.   
    There are five binary arithmetic operators (+, -, *, /, % (remainder)).

    The division operator can be thought of as having different modes depending on the type of the operands.
        If one or both of its operators are floating point numbers, it performs floating point division, which returns a floating point value (rounding errors may occur, naturally)
        If both operands are integers, it performs integer division which ignores the fractional component of the result entirely.
    To get around integer division, we can static_cast one of the integers to a float to trigger floating point division, so the fractional part of the result is kept.

    The remainder / modulo operator returns the remainder after doing integer division. It is most useful for checking divisibility.
    With negative operands, x % y always has the sign of x. Thus, if checking for an odd integer, check that x % 2 != 0, since checking if it is equal to 1 will fail the case when x is negative (which has remainder -1)
    
    Exponents are calculated using the pow() function, found in the <cmath> header. It may not be precise, even when using whole numbers, since its parameters and return type are doubles.

    Overloaded operators can be redefined to have different behavior than built-in operators, and this may include modifying the left operand even if the built-in version does not (or vice-versa). 
        For example, the overloaded version of operator<< used for output modifies its left operand (the output stream object).
*/

#include <iostream>

/* Practice:
Write a program that asks the user to input an integer, and tells the user whether the number is even or odd.
Write a constexpr function called isEven() that returns true if an integer passed to it is even, and false otherwise.
Use the remainder operator to test whether the integer parameter is even. Make sure isEven() works with both positive and negative numbers.
*/

int getInteger() {
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;
    return x;
}

constexpr bool isEven(int x) {
    return x % 2 == 0;
}

void evenOrOdd() {
    // get integer from user
    int input {getInteger()};

    // check parity
    if (isEven(input))
        std::cout << input << " is an even number.\n";
    else
        std::cout << input << " is an odd number.\n";
}


int main()
{

    constexpr int a{ 7 };
    constexpr int b{ 4 };

    std::cout << "int / int = " << a / b << '\n';
    std::cout << "double / int = " << static_cast<double>(a) / b << '\n';
    std::cout << "int / double = " << a / static_cast<double>(b) << '\n';
    std::cout << "double / double = " << static_cast<double>(a) / static_cast<double>(b) << '\n';

    std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;

	std::cout << "The remainder is: " << x % y << '\n';

	if ((x % y) == 0)
		std::cout << x << " is evenly divisible by " << y << '\n';
	else
		std::cout << x << " is not evenly divisible by " << y << '\n';

    return 0;
}