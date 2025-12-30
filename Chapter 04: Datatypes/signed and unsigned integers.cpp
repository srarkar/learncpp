/*
Integers
    By default, integers in C++ are signed, meaning that the number's sign (positive or negative) is stored as part of the value.
    Four types of signed integers, which vary by the amount of space they occupy in memory:
        short s;      // prefer "short" instead of "short int"
        int i;
        long l;       // prefer "long" instead of "long int"
        long long ll; // prefer "long long" instead of "long long int"
    An optional, but highly redundant "signed" can be pre-pended.

    The set of values an integer can take is known as its range. For example, an 8-bit integer ranges from -128 to +127, using the two's complement representation.

Overflow
    But what about when we try to assign a value that is beyond the range of the data type? For example, putting 150 in an 8-bit integer.
    This is known overflow, and can lead to undefined behavior. It causes a loss of information, and can be avoided by using a data type with a wider range.

Integer Division
    When doing division of two integers, the result is only the quotient. That is, the fractional component is dropped entirely
*/

/*
Unsigned Integers
    Unsigned integers can only hold non-negative values. We use the "unsigned" keyword to do so.
        unsigned short us;
        unsigned int ui;
        unsigned long ul;
        unsigned long long ull;

    This also affects the range. An 8-bit number now ranges from 0 to 255 -- still 256 values, but shifted to only be non-negative.
    When no negative values are needed, unsigned can be useful for networking and system with limited memory, unsigned integers may be preferred since more positive numbers can be stored without taking up more space.

    Overflow doesn't happen for unsigned integers. Rather, the remainder is what the final value is.
    For example, if we try to put 356 into an 8-bit uint (which has range 0 to 255) then we will end up with 100, since that is the remainder of 356 / 256.
    Negative values will also wrap around to the top of the range.

    This has caused many notable bugs in history, and is related to the controversy over the usage of unsigned integers.

    Compared to 2's complement, it is very easy to overflow unsigned integers from the bottom of the range (i.e. close to 0).
    It can very tedious/difficult to prevent this from happening, as say we print an integer from the user, and they input a negative value.
    Another simple example is having some value count down 1 by 1, and eventually goes into negative, which would go back to the top of the range.

    Often times, the compiler may not even complain about this being a possibility.

    Some cases where unsigned may be preferred (but generally try to avoid unsigned):
        - bit manipulation
        - array indexing
        - embedded systems for the sake of performance
*/