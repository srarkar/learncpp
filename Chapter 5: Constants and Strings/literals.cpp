/*
Literals
    Literals are values inserted directly into code. Their type is determined by the literal's value.
    If the assumed type is not desired, they can be modified with specific suffixes.
        For example, double is the default for floating point literals, which can be adjusted to a float by appending an 'f'.

String Literals
    Strings are not a fundamental type in C++ due to historical reasons.
    Rather, C strings have an implicit null terminator -- a null value that signifies the end of the string, and is included in the length of the string. 
    In addition, C-style string literals are const objects created at the start of the program, and guaranteed to exist for the lifetime of the program itself.

    On the other hand, std::string and std::string_view create temporary objects that must be used immediately, not C-style strings.

Magic Numbers
    A magic number is a literal (usually a number) whose meaning is unclear or needs to be changed later.
    They can be misleading and prone to causing errors when updating a value or multiple occurences of the same value.
    The lack of context and resilience is easily fixed by using symbolic constants, since the name provides context and the same value is automatically propagated everywhere needed.
*/ 

#include <iostream>

int main()
{   
    // Integer Literals
    std::cout << 5 << '\n';  // 5 (no suffix) is type int (by default)
    std::cout << 5L << '\n'; // 5L is type long
    std::cout << 5u << '\n'; // 5u is type unsigned int

    int a { 5 };          // ok: types match
    unsigned int b { 6 }; // ok: compiler will convert int value 6 to unsigned int value 6
    long c { 7 };         // ok: compiler will convert int value 7 to long value 7

    std::cout << 5.0 << '\n';  // 5.0 (no suffix) is type double (by default)
    std::cout << 5.0f << '\n'; // 5.0f is type float

    // standard and scientific notation
    double pi { 3.14159 }; // 3.14159 is a double literal in standard notation
    double d { -1.23 };    // the literal can be negative
    double why { 0. };     // syntactically acceptable, but avoid this because it's hard to see the decimal point (prefer 0.0)

    double avogadro { 6.02e23 }; // 6.02 x 10^23 is a double literal in scientific notation
    double protonCharge { 1.6e-19 }; // charge on a proton is 1.6 x 10^-19  

    std::cout << "Hello, world!"; // String literal! this is const char[14] due to the null terminator

    // magic numbers. what does 30 mean?
    // const int maxStudentsPerSchool{ numClassrooms * 30 };
    // setMax(30);

    return 0;
}