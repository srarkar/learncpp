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

Common Problems
    A dangling else problem occurs primarily with nested if statements, where it is unclear which "if" the "else" is matched to.
    The answer is that the else will match the last unmatched if-statement. The best way to avoid this issue is using blocks to explicitly show what the else pertains to.
    
    Logical operators are often useful to "flatten" nested if-statements to make them easier to understand.

    A null statement is an expression statement that consists only of a semicolon. It accomplishes nothing, but can mean that minor typos have large effects on program behavior.
    We can mimic Python and #define PASS in order to serve as a "do-nothing" statement

*/

#include <iostream>
#define PASS

void foo(int x, int y)
{
    if (x > y)
        PASS; // does nothing, but is far easier to see and understand than an empty null statement. 
    else
        PASS;
}

int main()
{
    foo(4, 7);

    return 0;
}

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

    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    if (x >= 0) // outer if-statement
        // it is bad coding style to nest if statements this way
        if (x <= 20) // inner if-statement
            std::cout << x << " is between 0 and 20\n";

    // which if statement does this else belong to? it belongs to the last unmatched if (the inner one, in this case)
    else
        std::cout << x << " is negative\n";

    if (x > 10)
    ; // this is a null statement. it does nothing!

    return 0;
}