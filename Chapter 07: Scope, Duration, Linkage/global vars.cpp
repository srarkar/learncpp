/*
Global Variables
    As opposed to local variables, global variables are declared outside of a function.
    By convention, they are declared at the top of the file (but below includes) within the global namespace.
    Global namespace scope, or file scope, means that these identifiers are visible from the point of definition to the end of the file.
    

    Consider using a 'g' or "g_" prefix when declaring them.
    Global variables can also be declared as part of a user-defined namespace, and are still accessible via the scope resolution operator.
    Global variables are created when the program starts (before main() begins execution), and destroyed when it ends. 
        This is called static duration. Variables with static duration are sometimes called static variables.
        Variables with static duration are zero-initialized by default.
    Constant global variables must be initialized. It is also best to avoid non-constant global variables.
    

*/

#include <iostream>

// Variables declared outside of a function are global variables
// Non-constant global variables
int g_x;                 // defines non-initialized global variable (zero initialized by default)
int g_x {};              // defines explicitly value-initialized global variable
int g_x { 1 };           // defines explicitly initialized global variable

// Const global variables
const int g_y;           // error: const variables must be initialized
const int g_y { 2 };     // defines initialized global const

// Constexpr global variables
constexpr int g_y;       // error: constexpr variables must be initialized
constexpr int g_y { 3 }; // defines initialized global constexpr

namespace Foo {
int g_x; // also a global variable, but in the namespace Foo
}

void doSomething()
{
    // global variables can be seen and used everywhere in the file
    g_x = 3;
    std::cout << g_x << '\n';
}

int main()
{
    doSomething();
    std::cout << g_x << '\n';

    // global variables can be seen and used everywhere in the file
    g_x = 5;
    std::cout << g_x << '\n';
    
    Foo::g_x = 4;
    std::cout << Foo::g_x << '\n';


    return 0;
}
// g_x goes out of scope here, at EOF