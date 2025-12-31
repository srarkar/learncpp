/*
Deleting Functions
    Say we wanted to prevent a function from being called with a certain type of parameter.
    The "= delete" specifier marks a function as deleted. The compiler will halt compilation if it detects a call to a deleted function.
    By specifying the type of the parameter, calls that match one or more of the deleted functions will prevent compilation.

    If there is a function call that does not exactly match any of the deleted or non-deleted functions, there may be ambiguity errors, assuming that none of the non-deleted functions are a best match.

    An alternative and less verbose way of forcing certain parameter types can be done with function templates.
*/

#include <iostream>

void printInt(int x)
{
    std::cout << x << '\n';
}

void printInt(char) = delete; // calls to this function will halt compilation
void printInt(bool) = delete; // calls to this function will halt compilation

template <typename T>
void printInt(T x) = delete;


int main()
{
    printInt(97);   // okay

    // printInt('a');  // compile error: function deleted. function template will also prevent
    // printInt(true); // compile error: function deleted. function template will also prevent

    // printInt(5.0);  // compile error: ambiguous match

    return 0;
}