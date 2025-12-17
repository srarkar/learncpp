/*
Bits, Bytes, Memory Addressing
    The smallest unit of memory is a binary digit, or bit, which holds either a 0 or 1.
    Memory is organized into sequential units called memory addresses. Each address is unique, and serves as a location for some piece of data.
    Each memory address holds a byte, which modern standard dictates to be 8 bits.

Fundamental Data Types
    Data types tell us how to interpret the 1s and 0s in memory.
    float/double/long double -> floating point (a number with a fractional part)
    bool -> Integral (boolean i.e. true/false)
    char/wchar_t/char8_t (C++20)/char16_t (C++11)/char32_t (C++11) -> Integral (a single character of text)
    short int/int/long int/long long int(C++ 11) -> Integral (integer / positive and negative whole numbers, as well as 0)
    std::nullptr (C++11) -> Null Pointer 
    void -> no type

    "Integral" means "like an integer", since all the integral types (char, bool, int) are stored as integers in memory.

    There are three sets of types: fundamental, compound, and those available in the C++ standard library (such as strings)
    Note that some modern types have a "_t" suffix
*/

/*
Void
    Void means no type -- one example of an incomplete type: a type that has been declared by not defined.
    This means the compiler is aware of them, but does not yet know how much memory to allocate for it.
    Incomplete types cannot be instantiated, but still find use in specific contexts.

    Void is primarily used as the return type for a function that doesn't return anything.
    Also, (deprecated) in C it could be used for a function that doesn't take parameters

    int getValue(void) // void here means no parameters
    {
        int x{};
        std::cin >> x;
        return x;
    }
    However, it is preferred to simply leave the () empty in C++.
*/