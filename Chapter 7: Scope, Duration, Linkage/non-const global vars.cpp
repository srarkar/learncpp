/*
Non-Const Global Variables
    Many programmers cite global variables, specifically non-constant ones, as a pitfall to avoid.
    The convenience of global variables is that they can be accessed from everywhere -- which is precisely what makes them dangerous.

    It is very easy for a global variable to be modified unintentionally, which is very difficult to track down.
        One would need to find all the places a global variable is modified (which can be anywhere in a program!) 
    Local variables are safer since no other function can modify them.

    Static variables, which includes globals, are initialized in two stages before the execution of main.
        First, static initialization occurs.
            Constant initialization occurs, where global variables with constexpr initializers (including literals) are initialized to those values
            Then global variables without initializers are zero-initialized.
        Second, dynamic initialization occurs
            Global variables with non-constexpr initializers are initialized.
    Since global variables are generally initialized in the order of definition, it is important to be careful about trying to use a variable that will not be initialized until later.

    Avoid initializing objects with static duration using other objects with static duration from a different translation unit.
    Dynamic initialization of global variables is also susceptible to initialization order issues and should be avoided whenever possible.

    An idea is to ensure the global variable is only accessible within the file it is declared in (via static or const) and providing external access functions (getter and setters) for other files to use
*/


#include <iostream>

int init()
{
    return 5;
}

int g_something{ init() }; // non-constexpr initialization

int g_mode; // declare global variable (will be zero-initialized by default)

void doSomething()
{
    g_mode = 2; // set the global g_mode variable to 2
}

int main()
{
    g_mode = 1; // note: this sets the global g_mode variable to 1.  It does not declare a local g_mode variable!

    doSomething();

    // Programmer still expects g_mode to be 1
    // But doSomething changed it to 2!

    if (g_mode == 1)
    {
        std::cout << "No threat detected.\n";
    }
    else
    {
        std::cout << "Launching nuclear missiles...\n";
    }

    return 0;
}