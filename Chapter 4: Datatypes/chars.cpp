/*
Chars
    The char data type holds a single character -- a singular letter, number, symbol, or even whitespace. 
    The value actually stored is an integer, and is interpreted according to an ASCII representation. 
        ASCII defines a way to represent English characters and some other symbol with the numbers 0 through 127. Only 32 - 126 are printable.

    Chars can be initialized with character literals, using single quotes, or with the equivalent ASCII decimal value.

    When accepting an input for a character with std::cin, only the first character of the inputted text is extracted, with the rest remaining the input buffer.
    
    By default, std::cin skips whitespace. To include it, use std::cin.get()

    Chars are always defined to be 1 byte in size. Even though they can be signed or unsigned, when holding an ASCII it doesn't matter since 0 to 127 fits in both ranges

    Many C++ compilers support single-quoting multicharacter literals (e.g. '56') for backwards compatibility, but they should be avoided and are not part of the C++ standard.

Escape Sequences
    Some sequences of characters hold special meaning, known as escape sequences. They start with a \ (backslash), followed by certain letters or numbers.
    Examples:
        - \n -> newline
        - \t -> horizontal tab
        - \" -> double quote (single quote follows same format)
        - \a -> alert (makes a beep sound). try with "printf '\a'" in bash
        and many more
*/



#include <iostream>

int main() {
    std::cout << '\a';
    char ch1{ 'a' }; // initialize with code point for 'a' (stored as integer 97) (preferred)
    std::cout << ch1; // cout prints character 'a'
    char ch2{ 98 }; // initialize with integer 98 ('b') (not preferred)
    std::cout << ch2; // cout prints character 'b'

    std::cout << "Input a keyboard character: ";

    char ch3{};
    std::cin >> ch3;
    std::cout << "You entered: " << ch3 << '\n';

        std::cout << "Input a keyboard character: "; // assume the user enters "a b" (without quotes)

    char ch4{};
    std::cin.get(ch4); // extracts a, leaves " b\n" in stream
    std::cout << "You entered: " << ch4 << '\n';

    std::cin.get(ch4); // extracts space, leaves "b\n" in stream
    std::cout << "You entered: " << ch4 << '\n';



    return 0;
}