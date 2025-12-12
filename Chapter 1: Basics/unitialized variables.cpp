/*
Uninitialized Variables
    When a variable that is not initialized is given a memory address to use, the default variable value is the garbage already in that location.
    An uninitialized variable is one that has not been given a known value. 
        - Initialized = The object is given a known value at the point of definition.
        - Assignment = The object is given a known value beyond the point of definition.
        - Uninitialized = The object has not been given a known value yet.

    Not initializing is a performance optimization for the cases when some data is going to be overwritten anyways. 
    However, it is dangerous to use uninitialized variables, as they can lead to undefined behavior
*/

/*
Undefined Behavior
    UB is the result of executing code whose behavior is not well defined. 
    From the previous example, since C++ doesn't have rules about outputted an uninitialized value, it is undefined behavior.
    Some signs of UB:
        - Your program produces different results every time it is run.
        - Your program consistently produces the same incorrect result.
        - Your program behaves inconsistently (sometimes produces the correct result, sometimes not).
        - Your program seems like it’s working but produces incorrect results later in the program.
        - Your program crashes, either immediately or later.
        - Your program works on some compilers but not others.
        - Your program works until you change some other seemingly unrelated code.
        - Or, your code may actually produce the correct behavior anyway.

Implementation-defined Behavior
    Code behavior can sometimes depend on the specific compiler and associated standard library associated with it (i.e. its implementation)
    This behavior must be consistent and documented for this implementation
    Unspecified behavior is very similar, but does not require documentation
    These should be avoided since a project may unexpectedly fail when run with a different implementation
*/
#include <iostream>
int main() {
    int x;
    std::cout << x;

    std::cout << sizeof(int) << '\n'; // this is implementation-defined behavior
}