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
