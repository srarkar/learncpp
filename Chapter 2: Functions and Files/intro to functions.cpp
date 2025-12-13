/*
Functions
    A function is a reusable sequence of statements designed to perform a particular job.
    Placing all our code in main() is possible, but quickly becomes difficult to manage. 
        Instead we can break our code into modular chunks that are much easier to organize and test individually
    As opposed to those provided in libraries, functions written ourselves are user-defined functions.
    A function call is sometimes called an invocation, with the caller invoking the callee


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