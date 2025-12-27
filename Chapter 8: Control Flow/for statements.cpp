/*
For Statements
    A for loop is preferred when there is an obvious loop variable. That is, a for loop is often best when we know how many iterations our loop will run.
    Its structure is as follows:
        for (init-statement; condition; end-expression)
            statement;
    The init statement is only ran once, when the loop is initiated. Variables initialized here have loop scope, meaning they are in-scope until the loop terminates.
    The condition is evaluated, and if it is true then the statement is ran. After the statement runs, the end-expression is executed.
    After this, the condition is re-checked, and so on. The end-expression is usually some kind of increment or decrement of a loop variable.

    An off-by-one error occurs when our loop runs one too many or one too few times. The error is often found in either the loop condition (< vs <=) or using a pre versus post increment.

    Any part of the for loop can be omitted. Note that an omitted condition evaluates to true, meaning that an empty for loop is equivalent to a while(true).
    If a variable is only needed in a loop, it should be defined within it (or as part of the init statement).

    Prefer for loops for obvious loop variables, and while loops otherwise.
*/

#include <iostream>

int main()
{
    for (int i{ 1 }; i <= 10; ++i)
        std::cout << i << ' ';

    std::cout << '\n';

    // for (;;) // equivalent to a while(true)
    //     statement;

    return 0;
}
