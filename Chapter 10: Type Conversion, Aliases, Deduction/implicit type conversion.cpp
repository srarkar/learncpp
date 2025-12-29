/*
Implicit Type Conversion
    Type conversion starts at the binary level. The bits that represent some integer will not represent the equivalent float.
    Thus, we need to preserve the value of some expression when converting its type.

    Implicit type conversion, also known as automatic type conversion or coercion, is performed automatically by the compiler when a provided expression's type does not match the expected one.
    Standard conversions deal with fundamental types (as well as certain compound types, including arrays, references, pointers, and enumerations) converting to other types in the same group.

    The 14 standard conversions can be roughly grouped into about 5 categories:
        Numeric Promotions: Conversions of small integral types to int or unsigned int, and of float to double.
        Numeric Conversions: Other integral and floating point conversions that aren’t promotions.
        Qualification Conversions: Conversions that add or remove const or volatile.
        Value Transformations: Conversions that change the value category of an expression
        Pointer Conversions: Conversions from std::nullptr to pointer types, or pointer types to other pointer types

*/
float doSomething()
{
    return 3.0; // double value 3.0 implicitly converted to type float
}

int main() {
    double d{ 3 }; // int value 3 implicitly converted to type double
    d = 6; // int value 6 implicitly converted to type double

    // int x { "14" }; // this will fail (i.e. not compile). compiler cannot convert a string literal to an integer

    return 0;
}