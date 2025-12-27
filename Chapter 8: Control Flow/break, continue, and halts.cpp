/*
Break
    The break statement causes a while loop, do-while loop, for loop, or switch statement to end, with execution continuing with the next statement after the loop or switch being broken out of.
    On the other hand, a return ends the entire function, not the current block.

    Within a switch statement, it is typically used at the end of each case to prevent fallthrough.
    In a loop, break can end the loop early. This also makes it a standard way to leave an infinite loop.
*/

/*
Continue
    Continue is a convenient way to skip an iteration of a loop without terminating it completely.
    When a continue is reached, it skips to the end of the loop (but still inside of it). 
        This means that if used in a for-loop, the end statement is still run even if a continue is executed.
    Continues are most effective at the beginning of a for loop to check conditions before proceeding with the statements. 
*/

/*
Halt
    A halt simply terminates the program. C++ implements halts as functions rather than keywords.
        When main returns, after local variables and parameters are destroyed, std::exit() is called with main's return code.
    
    std::exit() is a function that causes a normal termination of the program. Normal means that it happened in an expected way.
    It also performs some cleanup.
        Variables with static storage duration are destroyed, miscellaneous file cleanup, and control is returned to the OS with the status code being the return value of main.
    std::exit() can be called explicitly, and requires the cstdlib header. Note that std::exit() does not clean up local variables!

    To faciliate this, the std::atexit() function allows the programmer to specify a function that will be called automatically on program termination.


    C++ also has std::abort, which causes abnormal termination. This is used when there is an unusual runtime error that prevents the program from continuing to run.
    An example is a divide-by-zero, or a failed assert. This does not do any cleanup.

    The std::terminate() function is typically used in conjunction with exceptions

    Explicit uses of halts should be minimized, as exceptions are generally better due to support for cleaning up variables.
*/

#include <iostream>
#include <cstdlib> // for std::exit()

void cleanup()
{
    // code here to do any kind of cleanup required
    std::cout << "cleanup!\n";
}

int main()
{
    int sum{ 0 };

    // Allow the user to enter up to 10 numbers
    for (int count{ 0 }; count < 10; ++count)
    {
        std::cout << "Enter a number to add, or 0 to exit: ";
        int num{};
        std::cin >> num;

        // exit loop if user enters 0
        if (num == 0)
            break; // exit the loop now

        // otherwise add number to our sum
        sum += num;
    }

    // execution will continue here after the break
    std::cout << "The sum of all the numbers you entered is: " << sum << '\n';

    while (true) // infinite loop
    {
        std::cout << "Enter 0 to exit or any other integer to continue: ";
        int num{};
        std::cin >> num;

        // exit loop if user enters 0
        if (num == 0)
            break;
    }

    std::cout << "We're out!\n";

    for (int count{ 0 }; count < 10; ++count)
    {
        // if the number is divisible by 4, skip this iteration
        if ((count % 4) == 0)
            continue; // go to next iteration

        // If the number is not divisible by 4, keep going
        std::cout << count << '\n';

        // The continue statement jumps to here
    }

    // register cleanup() to be called automatically when std::exit() is called
    std::atexit(cleanup); // note: we use cleanup rather than cleanup() since we're not making a function call to cleanup() right now

    std::cout << 1 << '\n';

    std::exit(0); // terminate and return status code 0 to operating system

    // The following statements never execute
    std::cout << 2 << '\n';

    return 0;
}