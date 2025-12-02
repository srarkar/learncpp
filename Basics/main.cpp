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

/*
Objects and Variables:
    - Rather than accessing memory directly, we instead use objects to access stored values
    - An object is a region of storage (like RAM or a register) that can hold a value, and these objects have associated properties.
    - We allow the compiler and operating system to abstract away knowing where to retrieve a value in memory from
    - Objects can be unnamed/anonymous, but usually they are given a name/identifier. An object with a name is known as a variable.

To create a variable, we tell the compiler we want one through a special type of declaration: a definition.
Runtime is when the variable is provided a storage location. This is when the object is actually created.
*/

/*
Data Types
    - A data type determines what kind of value an object will store
    - The type must be known at compile-time, and this type cannot be changed without recompilation.
    - Multiple variables of the same type can be declared on the same line
*/

// Every C++ program requires a main() function in order for it to successfully link.
int main() {
    /*
    Data is information that can be moved, processed, or stored by a computer.
    A single piece of data is sometimes called a value. Some examples are:
        - Numbers
        - Characters, which are placed in single quotes
        - Text (strings) which are placed in double quotes
    Improper quotations can cause the compiler to try to interpret it as C++ code

    Values directly placed in program code are known as literals. They are loaded into RAM when the program itself is loaded into the RAM.
    Some additional RAM is allocated for the program to store values that might be calculated, read from the user or from a file, etc. during runtime
    */
    std::cout << "Hello World!";

    std::cout << 5;       // print the literal number `5`
    std::cout << -6.7;    // print the literal number `-6.7`
    std::cout << 'H';     // print the literal character `H`
    std::cout << "Hello"; // print the literal text `Hello`

    // define a variable named x (of type int).
    // at compile-time, the compiler will note the definition (data type is int, identifier is x), and any following usages of its identifier, x, will be known as referring to this variable
    int x; 

    int a;
    int b;
    // above and below are equivalent
    int a, b;
    // int a, int b; wrong!
    // int a, double b; wrong!

    return 0;
}