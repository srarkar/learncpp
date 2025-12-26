/*
Introduction to Control Flow
    The CPU begins execution at the top of main() and proceeds downwards/sequentially by default until it terminates at the end of main().
    The sequence of statements executed by the CPU is called the program's execution path.

    A straight-line program takes the same path every time it is ran. 
    This is rarely the case, and we use control flow statements to change the normal path of execution based on certain conditions occuring.
    When such a statements causes the execution path to lead to a non-sequential statement, it is known as branching.
*/

/*
If-statements
    There is some debate on whether to include curly braces/blocks when using single-statement if-elses.
    Doing so is easier to read and understand, but placing them in a single line can be more space-conservative for more experienced devs.
*/

#include <iostream>

void ifelse(bool a, bool b, bool c)
{
    if (a)      // always evaluates
        std::cout << "a";
    else if (b) // only evaluates when prior if-statement condition is false
        std::cout << "b";
    else if (c) // only evaluates when prior if-statement condition is false
        std::cout << "c";
    std::cout << '\n';
}

void ifif(bool a, bool b, bool c)
{
    if (a) // always evaluates
        std::cout << "a";
    if (b) // always evaluates
        std::cout << "b";
    if (c) // always evaluates
        std::cout << "c";
    std::cout << '\n';
}

int main()
{
    ifelse(false, true, true);
    ifif(false, true, true);

    return 0;
}

