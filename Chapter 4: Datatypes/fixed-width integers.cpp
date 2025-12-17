/*
Fixed-width Integers
    C++ only guarantees that integer variables have a minimum size. This does not mean we can assume the exact size that an integer occupies.
    Assuming 32-bit integers means we can run into overflow, and assuming 16-bit means we may be neglecting to take advantage of half the bits available to us.
    Integers not being a fixed size is carried over from C, where the size of an integer depends on the compiler and computer architecture.
    However, the lack of consistent ranges for integral types is problematic, and gave birth to an alternate set of integer types.

    This set of integer types, known as fixed-width integers, are guaranteed to be the same size on any architecture.
    They are found in the <cstdint> header. Note that std::int8_t and std::uint8_t are treated like signed and unsigned chars due to an oversight in the C++ specification -- they are typedef'd to be chars

    Interestingly, these fixed-width integers do not define new types. Rather, they are aliases for existing ones. 
    For example, on a platform where an int is 16 bits and a long is 32, a fixed width 32 bit integer is an alias for a long.

Other Downsides
    They are not guaranteed to be defined on all architectures -- they require the existence of fundamental integral types that match their widths and follow a certain binary representation.  
*/

/*
Fast and least integral types
    Since the previously mentioned types are not guaranteed to exist, there are alternative integer sets that are
    # = 8, 16, 32, or 64
    The fast types (std::(u)int_fast#_t) provides the fastest signed unsigned integer type with a width of at least # bytes.
        "Fastest" means the integral type that is processed most quickly by the CPU
    The least types (std::(u)int_least#_t) provides the smallest signed/unsigned type with at least # bytes.

    These are implementation-defined (meaning they can resolve to varying sizes), relatively unknown, and the fast types can cause memory wastage.
*/

/*
Best Practice
    Prefer int when the size of the integer doesn’t matter (e.g. the number will always fit within the range of a 2-byte signed integer). For example, if you’re asking the user to enter their age, or counting from 1 to 10, it doesn’t matter whether int is 16-bits or 32-bits (the numbers will fit either way). This will cover the vast majority of the cases you’re likely to run across.
    Prefer std::int#_t when storing a quantity that needs a guaranteed range.
    Prefer std::uint#_t when doing bit manipulation or well-defined wrap-around behavior is required (e.g. for cryptography or random number generation).

    Avoid the following when possible:
        short and long integers (prefer a fixed-width integer type instead).
        The fast and least integral types (prefer a fixed-width integer type instead).
        Unsigned types for holding quantities (prefer a signed integer type instead).
        The 8-bit fixed-width integer types (prefer a 16-bit fixed-width integer type instead).
        Any compiler-specific fixed-width integers (for example, Visual Studio defines __int8, __int16, etc…)

Google C++ on Integer Types:

The standard library header <stdint.h> defines types like int16_t, uint32_t, int64_t, etc. You should always use those in preference to short, unsigned long long, and the like, when you need a guarantee on the size of an integer. Prefer to omit the std:: prefix for these types, as the extra 5 characters do not merit the added clutter. Of the built-in integer types, only int should be used. When appropriate, you are welcome to use standard type aliases like size_t and ptrdiff_t.

We use int very often, for integers we know are not going to be too big, e.g., loop counters. Use plain old int for such things. You should assume that an int is at least 32 bits, but don't assume that it has more than 32 bits. If you need a 64-bit integer type, use int64_t or uint64_t.

For integers we know can be "big", use int64_t.

You should not use the unsigned integer types such as uint32_t, unless there is a valid reason such as representing a bit pattern rather than a number, or you need defined overflow modulo 2^N. In particular, do not use unsigned types to say a number will never be negative. Instead, use assertions for this.

If your code is a container that returns a size, be sure to use a type that will accommodate any possible usage of your container. When in doubt, use a larger type rather than a smaller type.

Use care when converting integer types. Integer conversions and promotions can cause undefined behavior, leading to security bugs and other problems.
*/

#include <cstdint> // for fast and least types
#include <iostream>

int main()
{
	std::cout << "least 8:  " << sizeof(std::int_least8_t)  * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  "  << sizeof(std::int_fast8_t)   * 8 << " bits\n";
	std::cout << "fast 16: "  << sizeof(std::int_fast16_t)  * 8 << " bits\n";
	std::cout << "fast 32: "  << sizeof(std::int_fast32_t)  * 8 << " bits\n";

	return 0;
}