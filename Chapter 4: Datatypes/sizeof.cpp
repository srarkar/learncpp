/*
Sizeof
    Most objects take more than just one byte in memory, depending on the data type.
    The size of an object affects how many unique such objects can exist. 
    For example, if an integer is 1 byte / 8 bits, then we can represent 2^8 unique integers.

    Even for fundamental data types, it is not standardized exactly how many bytes each takes up.
    There are some standards, however;
        - All objects must occupy at least 1 byte
        - A byte must be at least 8 bits
        - Integral types char, short, int, long, and long long have a minimum size of 8, 16, 32, and 64 bits, respectively
        - char and char8_t occupy exactly 1 byte

    The unary sizeof operator is used to check the number of bytes an object takes up (cannot be used on incomplete types)

    Fundamental data types are often optimized for performance, and some CPUs are also optimized for specific sizes (such as 32-bit).
    As such, using less memory does not necessarily mean better performance.
*/

#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <iostream>
#include <climits> // for CHAR_BIT

int main()
{
    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    std::cout << std::left; // left justify output

    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

    return 0;
}
/*
Prints:
    bool:           1 bytes
    char:           1 bytes
    short:          2 bytes
    int:            4 bytes
    long:           8 bytes
    long long:      8 bytes
    float:          4 bytes
    double:         8 bytes
    long double:    8 bytes
*/