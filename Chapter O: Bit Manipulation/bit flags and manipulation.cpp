/*
Bit Manipulation
    Rather than working in bytes, we can instead treat each of the 8 bits it contains as a value. Modifying the individual bits in an object is known as bit manipulation.
    It is used especially in optimization, compression, and encryption.

    When the individual bits of an object are treated as boolean values, they are known as bit flags, where a flag signals when a condition is met or not.

    When defining a set of bit flags, we use either an unsigned integer, or a bitset via std::bitset<#> {};
    std::bitset has 4 key functions:
        test() allows us to query whether a bit is a 0 or 1.
        set() allows us to turn a bit on (this will do nothing if the bit is already on).
        reset() allows us to turn a bit off (this will do nothing if the bit is already off).
        flip() allows us to flip a bit value from a 0 to a 1 or vice versa.

    Literals can be used as arguments to these functions, but each flag can also be assigned names via constexpr integer variables to give each flag meaning.

    Some others are:
        size() returns the number of bits in the bitset.
        count() returns the number of bits in the bitset that are set to true.
        all() returns a Boolean indicating whether all bits are set to true.
        any() returns a Boolean indicating whether any bits are set to true.
        none() returns a Boolean indicating whether no bits are set to true.

    
    Setting or obtaining multiple bits at once is difficult with std::bitset. In addition, it is optimized for speed, not memory, meaning even a bitset of 8 can occupy far more than 1 byte.
*/

/*
Bitwise Operators
    There are 6 bit manipulation operators: |, &, ~, <<, >>, ^. They do not modify their operand.
    << and >> are also the insertion and extraction operators. Whether they serve to shift or deal with input/output depends on the type of the operands.
        If there is ambiguity, use parentheses. This is a case of operator overloading.
    
    Bitwise operators perform integral promotion. If their operands are an integral type smaller than an int, they will be converted into an int or unsigned int, and so will the returned result.
    In these cases, be mindful of how operator~ and operator<< are width-sensitive and may produce different results depending on the width of the operand.
        Also, initializing or assigning the result to a variable of the smaller integral type is a narrowing conversion (since converting an int or unsigned int to a smaller integral type may result in data loss). 
            This is disallowed in list initialization, and your compiler may or may not complain about a narrowing assignment.

*/


#include <bitset>
#include <iostream>

int main()
{
    std::bitset<8> bits{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
    bits.set(3);   // set bit position 3 to 1 (now we have 0000 1101)
    bits.flip(4);  // flip bit 4 (now we have 0001 1101)
    bits.reset(4); // set bit 4 back to 0 (now we have 0000 1101)

    std::cout << "All the bits: " << bits<< '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';

    [[maybe_unused]] constexpr int  isHungry   { 0 };
    [[maybe_unused]] constexpr int  isSad      { 1 };
    [[maybe_unused]] constexpr int  isMad      { 2 };
    [[maybe_unused]] constexpr int  isHappy    { 3 };
    [[maybe_unused]] constexpr int  isLaughing { 4 };
    [[maybe_unused]] constexpr int  isAsleep   { 5 };
    [[maybe_unused]] constexpr int  isDead     { 6 };
    [[maybe_unused]] constexpr int  isCrying   { 7 };

    std::bitset<8> me{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
    me.set(isHappy);      // set bit position 3 to 1 (now we have 0000 1101)
    me.flip(isLaughing);  // flip bit 4 (now we have 0001 1101)
    me.reset(isLaughing); // set bit 4 back to 0 (now we have 0000 1101)

    std::cout << "All the bits: " << me << '\n';
    std::cout << "I am happy: " << me.test(isHappy) << '\n';
    std::cout << "I am laughing: " << me.test(isLaughing) << '\n';

    std::bitset<4> x { 0b1100 };

    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
    std::cout << (x << 1) << '\n'; // shift left by 1, yielding 1000

    std::uint8_t c { 0b00001111 };

    // all would be incorrect without the static_cast
    std::cout << std::bitset<32>(static_cast<std::uint8_t>(~c)) << '\n';     // correct: prints 00000000000000000000000011110000
    std::cout << std::bitset<32>(static_cast<std::uint8_t>(c << 6)) << '\n'; // correct: prints 0000000000000000000011000000
    std::uint8_t cneg { static_cast<std::uint8_t>(~c) };                     // compiles
    c = static_cast<std::uint8_t>(~c);                                       // no warning
    return 0;
}