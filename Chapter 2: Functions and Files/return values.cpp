#include <iostream>

/*
Return Values
    Often, we want to get some value back from a function to use in the rest of our program. This is done in 2 steps
        - First, we state in the function header what type the return value is -- the return type. A function that does not return anything
           has a return value of void
        - Second, we use a return statement (composed of return + the return expression) inside the function.
            When the return statement is executed:
                - The return expression is evaluated to produce a value.
                - The value produced by the return expression is copied back to the caller.
                - The function exits, and control returns to the caller.
        Not returning a value inside a value-returning function can cause compile errors and undefined behavior
*/

int getValueFromUser() {
    std::cout << "Enter an integer: ";
    int input{ };
    std::cin >> input;
    return input;
}

/*
Main
    Main has 2 special requirements.
        - It cannot be explicitly called, as only the OS calls main() itself. This does not necessarily mean main() is the first function that executes, however
            Note that since C allows calls to main(), some C++ compilers will allow it
        - It must return an integer 
    The return value of main is also known as a status code or exit code. Conventionally, a status code of 0 is that everything executed smoothly.
    C++ pre-defines EXIT_SUCCESS as 0 and EXIT_FAILURE as 1 in the <cstdlib>.
*/
int main() {
    int input{ getValueFromUser() };
    std::cout << "Double of " << input << " is " << input * 2 << '\n';

    // main automatically returns 0 when it finishes, but it is best to do it explicitly
    return EXIT_SUCCESS;
}