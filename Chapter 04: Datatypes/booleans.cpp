/*
Booleans
    Booleans are a type that can only hold the values True or False. They are declared using the keyword "bool".
    A logical not (!) operator flips the value of a boolean variable.

    However, they are stored as integral values, with true being an integer 1, and false an integer 0.
    To output "true" or "false" when printing, simply output std::boolalpha beforehand.

    Booleans and std::cin can have unexpected interactions.
        By default, std::cin only accepts numeric values for booleans (0 for false, 1 for true). 
        Any other numeric value is interpreted as true, and causes std::cin to enter failure mode.
        Also, any non-numeric value (including the "true" string) is interpreted as false, also causing failure mode.

        One workaround is first inputting std::boolalpha
*/
#include <iostream>

int main() {
    bool b1 { true };
    bool b2 { false };
    // bool b4 { 2 };  Not allowed! This is a narrowing conversion. 0 or 1 is allowed, but t/f is good practice
    b1 = false;
    bool b3 {}; // default initialize to false
    std::cout << b3 << '\n'; // prints 0
    std::cout << !b3 << '\n'; // prints 1

    // std::boolalpha 
    std::cout << true << '\n';
    std::cout << false << '\n';

    std::cout << std::boolalpha; // print bools as true or false

    std::cout << true << '\n';
    std::cout << false << '\n';

    std::cout << std::noboolalpha; // revert back

    bool b{};
	std::cout << "Enter a boolean value: ";
    std::cin >> std::boolalpha;
    std::cin >> b; // Note that it must be "true" or "false" (case-sensitive). Numeric values are no longer accepted, and default to false

    return 0;
}