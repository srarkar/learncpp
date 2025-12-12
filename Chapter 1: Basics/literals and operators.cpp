/*
Literals
    A literal, or literal constant, is a fixed value that has been inserted directly into source code.
    They have a value and type (like a variable), but this value cannot be changed (unlike a variable)

*/


#include <iostream>;

int main() {
    std::cout << "Hello world!"; // literal text
    int x { 5 }; // copy the literal 5 into the memory location associated with variable identified as x

    std::cout << 5 << '\n'; // print the value of a literal
    return 0;
}