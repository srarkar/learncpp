/*
Constexpr If-statements
    It is possible for the conditional portion of an if statement to be evaluated at compile-time instead of runtime.
    That is, our condition is a constant expression, meaning the compiler can optimize by replacing the if statement and its body with such the true statement or nothing (if the constant expression evaluates to false).

    The constexpr if statement requires the conditional to be a constant expression.
        If constexpr is not specified but the condition is a constant expression, the compiler may either give a nudge to set it as constexpr, or simply treat it as one to ensure it is not evaluated at runtime.
*/

#include <iostream>

int main()
{
	constexpr double gravity{ 9.8 };

	// reminder: low-precision floating point literals of the same type can be tested for equality
	if (gravity == 9.8) // constant expression, always true
		std::cout << "Gravity is normal.\n";   // will always be executed
	else
		std::cout << "We are not on Earth.\n"; // will never be executed

	return 0;
}