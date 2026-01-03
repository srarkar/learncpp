/*
Return by reference
    When returning by value, this makes a (sometimes expensive) copy of the return value to pass back to the caller.
    Return by reference returns a reference that is bound to the object being returned, which avoids making a copy of the return value.
    To do so, we simply define the return value as a reference type.

    There is an important caveat: the object must outlast the reference being returned, to prevent the returned reference from becoming dangling.
    Never return a (non-static) local variable or temporary by reference. Reference lifetime extension does not work across function boundaries.
        If parameter is passed into a function by reference, it’s safe to return that parameter by reference. This makes sense since we know it will remain in scope after the return.
        When an argument for a const reference parameter is an rvalue, it’s still okay to return that parameter by const reference.
            This is because rvalues are not destroyed until the end of the full expression in which they are created.
    If a function returns a reference, and that reference is used to initialize or assign to a non-reference variable, the return value will be copied (as if it had been returned by value)z

    Prefer return by reference over return by address unless the ability to return “no object” (using nullptr) is important.
*/

#include <iostream>
#include <string>

const std::string& getProgramName() // returns a const reference
{
    static const std::string s_programName { "Calculator" }; // has static duration, destroyed at end of program

    return s_programName;
}

int main()
{
    std::cout << "This program is named " << getProgramName();

    return 0;
}