/*
Narrowing Conversions
    A narrowing conversion is a potentially unsafe numeric conversion where the destination type may not be able to hold all the values of the source type.
    That means the following:
        From a floating point type to an integral type.
        From a floating point type to a narrower or lesser ranked floating point type, unless the value being converted is constexpr and is in range of the destination type (even if the destination type doesn’t have the precision to store all the significant digits of the number).
        From an integral to a floating point type, unless the value being converted is constexpr and whose value can be stored exactly in the destination type.
        From an integral type to another integral type that cannot represent all values of the original type, unless the value being converted is constexpr and whose value can be stored exactly in the destination type. This covers both wider to narrower integral conversions, as well as integral sign conversions (signed to unsigned, or vice-versa).
    They will usually cause compiler warnings since they are unsafe.

    When doing so intentionally, a narrowing conversion should be done explicitly with static_cast. This can be the case for function parameters.
    Brace initialization disallows them.

    In some cases, the values involved are unknown until runtime, meaning there is uncertainty on whether it is indeed a narrowing conversion.
    Conversion from a constexpr floating point type to a narrower floating point type is not considered narrowing even when a loss of precision results.
    Also weirdly, conversions from a floating point to an integral type are always considered narrowing conversions even when the value to be converted is constexpr and fits in the range of the destination type
*/

void someFcn(int i)
{
}

int main()
{
    double d{ 5.0 };

    someFcn(d); // bad: implicit narrowing conversion will generate compiler warning

    // good: we're explicitly telling the compiler this narrowing conversion is intentional

    someFcn(static_cast<int>(d)); // no warning generated
    constexpr int n1{ 5 };   // note: constexpr
    unsigned int u1 { n1 };  // okay: conversion is not narrowing due to exclusion clause

    constexpr int n2 { -5 }; // note: constexpr
    unsigned int u2 { n2 };  // compile error: conversion is narrowing due to value change

    unsigned int u { 5 }; // okay (we don't need to use `5u`)
    float f { 1.5 };      // okay (we don't need to use `1.5f`)

    // We can avoid static_casts
    constexpr int n{ 5 };
    double d { n };       // okay (we don't need a static_cast here)
    short s { 5 };        // okay (there is no suffix for short, we don't need a static_cast here)

    return 0;
}