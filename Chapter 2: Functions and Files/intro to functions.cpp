/*
Functions
    A function is a reusable sequence of statements designed to perform a particular job.
    Placing all our code in main() is possible, but quickly becomes difficult to manage. 
        Instead we can break our code into modular chunks that are much easier to organize and test individually
    As opposed to those provided in libraries, functions written ourselves are user-defined functions.
    A function call is sometimes called an invocation, with the caller invoking the callee
    Functions help reduce repeated code (DRY)

Basic Template of a Function:
    returnType functionName() // This is the function header (tells the compiler about the existence of the function)
    {
        // This is the function body (tells the compiler what the function does)
    }

    Nested functions are not allowed. Example:
    int main()
    {
        void foo() // Illegal: this function is nested inside function main()
        {
            std::cout << "foo!\n";
        }

        foo(); // function call to foo()

        return 0;
    }
*/

/*
A few basic guidelines for writing functions:
    - Groups of statements that appear more than once in a program should generally be made into a function. For example, if we’re reading input from the user multiple times in the same way, that’s a great candidate for a function. If we output something in the same way in multiple places, that’s also a great candidate for a function.
    - Code that has a well-defined set of inputs and outputs is a good candidate for a function, (particularly if it is complicated). For example, if we have a list of items that we want to sort, the code to do the sorting would make a great function, even if it’s only done once. The input is the unsorted list, and the output is the sorted list. Another good prospective function would be code that simulates the roll of a 6-sided dice. Your current program might only use that in one place, but if you turn it into a function, it’s ready to be reused if you later extend your program or in a future program.
    - A function should generally perform one (and only one) task.
    - When a function becomes too long, too complicated, or hard to understand, it can be split into multiple sub-functions. This is called refactoring.
*/

#include <iostream>

// without a forward declaration, a function must be defined before it is called
void doPrint() {
    std::cout << "inside doPrint()" << '\n';
}

int main() {
    std::cout << "before doPrint() call" << '\n';
    doPrint();
    std::cout << "after doPrint() call" << '\n';
    return 0;
}