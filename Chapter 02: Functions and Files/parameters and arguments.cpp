#include <iostream>

/*
Parameters and Arguments
    Oftentimes, we want to provide functions with values that it can use to accomplish something. 
    A function parameter is a variable used in the header of a function. 
    Function parameters work almost identically to variables defined inside the function, but with one difference: 
        they are initialized with a value provided by the caller of the function.

    An argument is a value that is passed from the caller to the function when a function call is made.

    When a function is called, all of the parameters of the function are created as variables, and the value of each of the arguments is copied into the matching parameter (using copy initialization).
    This process is called pass by value. Function parameters that utilize pass by value are called value parameters.


*/

int getValueFromUser() {
    std::cout << "Enter an integer: ";
    int input{ };
    std::cin >> input;
    return input;
}

// We can abstract the print as well, but it needs to obtain the return value of getValueFromUser() somehow
// This can be accomplished by passing the input to printDouble, which is stated to be an integer parameter of printDouble()
void printDouble(int input) {
    std::cout << "Double of " << input << " is " << input * 2 << '\n';
}

// leaving parameters unnamed is also allowed. used in cases where the parameter must be there but is not used.
// May be useful if we change the code to not need the parameter and do not want to break all uses of the function
// Google C++ guide recommends commenting what the parameter was, like so
void nothingBurger(int /*count*/) {
}

int main() {
    // int input{ getValueFromUser() };
    // printDouble(input); // input is the argument
    printDouble(getValueFromUser()); // even more concise, although some may argue as harder to read

    return EXIT_SUCCESS;
}