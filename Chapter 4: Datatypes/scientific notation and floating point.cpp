/*
Scientific Notation
    Scientific notation serves as shorthand for lengthy numbers. They take the form of significant * 10 ^ (exponent)
        Exponents can be difficult to display, so 5.99 * 10^24 is instead written as 5.99e24.
        This exponent is negative for numbers whose magnitude is less than 1.
        
        The significand has one digit before (to the left of) the decimal point.
        The number of digits in the significand is known as the number of significant digits/figures. 
            More sig figs -> more precise
    Decimal numbers -> Scientific Notation
        Your exponent starts at zero.
        If the number has no explicit decimal point (e.g. 123), it is implicitly on the right end (e.g. 123.)
        Slide the decimal point left or right so there is only one non-zero digit to the left of the decimal.
        Each place you slide the decimal point to the left increases the exponent by 1.
        Each place you slide the decimal point to the right decreases the exponent by 1.
        Trim off any leading zeros (on the left end of the significand)
        Trim off any trailing zeros (on the right end of the significand) only if the original number had no decimal point. We’re assuming they’re not significant. If you have additional information to suggest they are significant, you can keep them
*/

/*
Floating Point Numbers
    A floating point type variable holds a number that includes a fractional component. They are always signed, and the decimal separator must be a period.
    There are three fundamental floating point data types: float, double, and long double. A float is usually 4 bytes, and a double is usually 8.
    Floating point literally default to double. Adding a suffix of 'f' forces a float.

Floating Point Precision
    Some values can technically go on forever -- a classic example is 1/3 = 0.333333.... 
    It would require an infinite amount of memory to store the infinite digits, so floating point numbers must have some limit as to the number of significant digits that can be represented without corruption.
    The precision of a floating point type defines how many significant digits it can represent without information loss.
    Precision depends on the size of the floating point type and the value being stored.

    Interpreting:
        A float has 6 to 9 digits of precision. This means a float can represent any number with up to 6 significant figures without loss of precision.
        A number with 7 to 9 significant digits may or may not be represented accurately, depending on the value. And any more than 9 is guaranteed to not be represented exactly.
        
    std::cout has a default precision of 6, and will truncate after that.
    This can be overidden using an output manipulator function called std::setprecision(). These manipulators are found in the <iomanip> header.

    If we lose precision since a number cannot be stored precisely, it is known as a rounding error.
    As such, unless the extra memory is needed, it is safer to use a double since it is much less prone to these errors than a float.
    
    Note that mathematical operations tend to make rounding errors grow. Never assume that floating point numbers are exact.
*/


#include <iomanip> // for output manipulator std::setprecision()
#include <iostream>

int main() {
    float f;
    double d;
    long double ld;

    int a { 5 };      // 5 means integer
    double b { 5.0 }; // 5.0 is a floating point literal (no suffix means double type by default)
    float c { 5.0f }; // 5.0 is a floating point literal, f suffix means float type

    int e { 0 };      // 0 is an integer
    double g { 0.0 }; // 0.0 is a double

    std::cout << 5.0 << '\n'; // prints 5, as the fractional component is 0 and is omitted
	std::cout << 6.7f << '\n'; // prints 6.7
	std::cout << 9876543.21 << '\n'; // prints 9.87654e+06 (scientific notation)

    // std::cout truncates after 6 digits
    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << '\n';

    // output manipulator
    std::cout << std::setprecision(17); // show 17 digits of precision
    std::cout << 3.33333333333333333333333333333333333333f <<'\n'; // f suffix means float. prints 3.3333332538604736
    std::cout << 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double. prints 3.3333333333333335. These are not precise, since we are using a float!

    float fs { 123456789.0f }; // f has 10 significant digits
    std::cout << std::setprecision(9); // to show 9 digits in f
    std::cout << fs << '\n'; // prints 123456792

    // IEEE edge cases
    double zero { 0.0 };

    double posinf { 5.0 / zero }; // positive infinity
    std::cout << posinf << '\n';

    double neginf { -5.0 / zero }; // negative infinity
    std::cout << neginf << '\n';

    double z1 { 0.0 / posinf }; // positive zero
    std::cout << z1 << '\n';

    double z2 { -0.0 / posinf }; // negative zero
    std::cout << z2 << '\n';

    double nan { zero / zero }; // not a number (mathematically invalid)
    std::cout << nan << '\n';

	return 0;
}