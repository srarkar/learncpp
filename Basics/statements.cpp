/*
Statements:
    - A computer program is a sequence of instructions that tell the computer what to do
    - A statement is a type of instruction (and the most common type, in C++) that tells the program to perform some action.
    - Statements are the smallest independent unit of computation in the C++ language
        - In other words, a statement is the smallest piece of code that can be executed on its own, and treated as an instruction
        - This also means that the pieces of a statement cannot execute independently
    Types of statements (more on this later):
        - Declaration statements
        - Jump statements
        - Expression statements
        - Compound statements
        - Selection statements (conditionals)
        - Iteration statements (loops)
        - Try blocks
*/

/* 
This is a preprocessor directive that states that the program wants to use the contents of the iostream library.
Part of the C++ standard library, and allows us to read/write text to/from the console.
If this was not included, we would get a compile error from the "std::cout".
*/
#include <iostream>


// Every C++ program requires a main() function in order for it to successfully link.
int main() {
    std::cout << "Hello World!";

    return 0;
}