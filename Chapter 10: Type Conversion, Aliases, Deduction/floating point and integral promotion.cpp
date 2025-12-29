/*
Numeric Promotion
    A numeric promotion is a category of type conversion.
    It involves converting from narrower numeric types such as char to some wider numeric types like int or double that may be processed more efficiently by the CPU.

    All numeric promotions are value-preserving (or safe) conversions, meaning every possible source value can be converted into a destination type of equal value

    With floating point promotions, a float can be converted into a double. This means a function can be written as taking a double, but in practice take either a double or float safely.
    With integral promotions, the following can be done:
        signed char or signed short can be converted to int.
        unsigned char, char8_t, and unsigned short can be converted to int if int can hold the entire range of the type, or unsigned int otherwise.
        If char is signed by default, it follows the signed char conversion rules above. If it is unsigned by default, it follows the unsigned char conversion rules above.
        bool can be converted to int, with false becoming 0 and true becoming 1. 
    Generally, we can write a function to take an int parameter, but it can really accept a wide variety of integral types (bool, char, signed char, unsigned char, signed short, and unsigned short)
    
    Some widening type conversions (such as char to short, or int to long) are not considered to be numeric promotions in C++.
        These are numeric conversions, which do not assist in making smaller types into larger ones for more efficient processing.
*/

#include <iostream>

void printInt(int x)
{
    std::cout << x << '\n';
}

void printDouble(double d)
{
    std::cout << d << '\n';
}

int main()
{
    printInt(2);

    short s{ 3 }; // there is no short literal suffix, so we'll use a variable for this one
    printInt(s); // numeric promotion of short to int

    printInt('a'); // numeric promotion of char to int
    printInt(true); // numeric promotion of bool to int

    printDouble(5.0); // no conversion necessary
    printDouble(4.0f); // numeric promotion of float to double

    return 0;
}