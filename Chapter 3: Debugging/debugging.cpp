/*
Debugging
    All bugs stem from a simple premise: something that is assumed to be correct, isn't.
    A debugging process looks something like:
        - Find the cause of the problem (usually a specific line)
        - Understand why the issue is occurring
        - Determine how to fix it
        - Repair the issue
        - Retest to ensure problem is fixed
        - Retest to ensure no other problems emerged 
*/

/*
Finding the cause
    - This is often difficult, as simply inspecting the code can simply lead to making the same assumptions that caused the bug in the first place.
    
    - First, try to reproduce the problem. 
        Observing the problem occurring is key to solving it, and we can use reproduction steps to generate the issue again consistently.
    - Hi-lo approach
        The bug must lie somewhere between the start and end of the program. 
        We can start at some part of the code, and check if the error exists at runtime at that part.
        If it doesn't then the bug exists somewhere below it, and if it does then it exists above it.
    
    Tactics 
        - Comment out code -> reduces the amount of code needed to search through. if issue persists, bug is likely not in commented code
        - Validate code flow -> adding prints at the top of functions shows when they are called, and if they are being called too little or too much
        - Printing values -> we can also print the values of variables and verify they are as expected, using std::cerr and an insertion operator.
    
        However, debug prints can clutter code, and must be removed before actually running the program. 

        One strategy is to use preprocessor directives (#define, #ifdef) to conditionally allow debug prints to run.
        This makes code even more cluttered, but gives control over when debugs should be ran or not.

    Logging
        A log is a sequential record of events that have happened. They are typically written to a portion of disk called a log file.
        C++ has an output stream called std::clog intended for writing logging info. By default, it shares a stream with std::cerr
        Many logging tools have built-in support for enabling/disabling debugging, removing the need for directives for it
        Some examples are plog and, in some large/performance-sensitive projects, spdlog
*/

/*
Using a Debugger
    When running a program, the value of the variables you’re using, which functions have been called, and the current point of execution within the program are known as the program state.

    Currently we have only explored what to do with information after the program has run to completion, not in the middle of execution.
    A debugger allows us to step through a program and view or even modify program state to control its execution and determine where a bug is occurring.
*/

/*
Testing
    It is harder to debug code than it is to write it.
    As such, it is better to write readable and maintainable code, and defensively anticipate what might go wrong and code workarounds for them.
    In addition, some tools such as static analysis tools look for semantic errors without executing (hence why they are static)
    Unit tests, using things like assert or static assert, can verify some result of a function is what it is expected to be.
*/


#include <iostream>

#define ENABLE_DEBUG // comment this line out to disable debug prints

int main() {
    #ifdef ENABLE_DEBUG
    std::cerr << "Beginning of main";
    #endif

    std::cout << "goodbye world" << '\n';

    #ifdef ENABLE_DEBUG
    std::cerr << "End of main";
    #endif
    return 0;
}
