/*
Preprocessor
    Prior to compilation, the preprocessor makes changes to the text of a code file.
        These changes are made to temporary files or temporarily in-memory.
    It ensures code files end in a newline, and removes comments. It also processes #include directives.
    Once the preprocessor is done, the result is a translation unit, which is passed to the compiler.

    The preprocessor scans for preprocessor directives, which start with a # and end in a newline (not a semicolon)
        this means using is not a preprocessor directive (from namespaces)
    These directives tell the preprocessor to do certain text manipulations, although the preprocessor does not know C++ syntax.
    They are valid from the point of definition until the end of the file. Being inside functions doesn't matter, since the preprocessor is not aware of such things.

#include
    When reaching a #include, the preprocessor replaces it with the contents of the included file, and then processes any directives in those contents

#define
    #define directive can be used to create a macro: a rule that defines how input text is converted/replaced into some output text
    Typically, macro names are written in all caps

    Macros are somewhat outdated as a means of assigning names to literals (from C).

Conditional directives
    #ifdef -> checks if an identifier has already been defined via #define. if it has, then the associated code block (from the #ifdef to the #endif) is included in compilation.
    #ifndef -> simply the opposite of ifdef (compile the code if the identifier has NOT yet been defined)

    Macro substitution does not occur when a macro identifier is used within another preprocessor command, except for #if / #elif
*/

#include <iostream>

#define MY_NAME "Alex"
#define PRINT_JOE

int main()
{
    std::cout << "My name is: " << MY_NAME << '\n';

    #ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
    #endif

    #ifdef PRINT_BOB
        std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined
    #endif


    #if 0 // Don't compile anything starting here. use #if 1 to allow the code to compile
        std::cout << "Bob\n";
        std::cout << "Steve\n";
    #endif // until this point


    return 0;
}