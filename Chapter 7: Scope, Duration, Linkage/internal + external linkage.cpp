/*
Internal Linkage
    We mentioned earlier how local variables have no linkage. Global variables and function identifiers can have either internal linkagae or external linkage.
    
    An identifier with internal linkage can be seen and used within a single translation unit, but is not accessible from others.
        As a reminder, a translation unit is a source code file after the preprocessor stage (meaning all #includes have been replaced with the appropriate declarations)
    This means that if two source files have identically named identifiers with internal linkage, those identifiers will be treated as independent.

    To make a non-constant global variable internal, use the static keyword. Const/constexpr globals have internal linkage by default.
    The use of the static keyword above is an example of a storage class specifier, which sets both the name’s linkage and its storage duration.
        The most commonly used storage class specifiers are static, extern, and mutable.

    Functions default to external linkage, but can be similarly set to internal via the static keyword.

    In modern C++, use of the static keyword for giving identifiers internal linkage is falling out of favor. 

    Unnamed namespaces can give internal linkage to a wider range of identifiers (e.g. type identifiers), and they are better suited for giving many identifiers internal linkage.
    Many guides recommend giving any function or variable not meant to be accessed by another file internal linkage.
*/


/*
External Linkage
    An identifier with external linkage can be seen and used both from the file it is defined in, and from other files through a forward declaration.
    They are truly "global" in the sense they can be used anywhere in a multi-file program.

    To make a global variable external, use the extern keyword. Non-const global vars are external by default.
    Avoid using extern on a non-const global variable with an initializer


*/

#include <iostream>

int add(int x, int y); // forward declaration

// Internal global variables definitions:
static int g_x;          // defines non-initialized internal global variable (zero initialized by default)
static int g_x{ 1 };     // defines initialized internal global variable

const int g_y { 2 };     // defines initialized internal global const variable
constexpr int g_z { 3 }; // defines initialized internal global constexpr variable


// Global variable forward declarations (extern w/ no initializer):
extern int g_y;                 // forward declaration for non-constant global variable
extern const int g_y;           // forward declaration for const global variable
//extern constexpr int g_y;       // not allowed: constexpr variables can't be forward declared

// External global variable definitions (no extern)
int g_x;                        // defines non-initialized external global variable (zero initialized by default)
int g_x { 1 };                  // defines initialized external global variable

// External const global variable definitions (extern w/ initializer)
extern const int g_x { 2 };     // defines initialized const external global variable
extern constexpr int g_x { 3 }; // defines initialized constexpr external global variable
// Internal function definitions:
static int foo() {};     // defines internal function

// This function is declared as static, and can now be used only within this file
// Attempts to access it from another file via a function forward declaration will fail
[[maybe_unused]] static int add(int x, int y)
{
    return x + y;
}


int main()
{
    std::cout << g_x << ' ' << g_y << ' ' << g_z << '\n';
    return 0;

    std::cout << add(3, 4) << '\n';
}