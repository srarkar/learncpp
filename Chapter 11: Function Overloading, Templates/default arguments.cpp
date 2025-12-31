/*
Default Arguments
    A default argument is a default value provided for a function argument.
        The value of the default argument is used if the caller does not provide a value.
    The default arguments in the function header must be to the right, since function calls cannot "skip" an argument.

    Default arguments cannot be declared more than once. This means that if a function has a definiton and a separate forward declaration, only one of them can contain the default argument value.
        Best practice is to do so in the forward declaration so that the default argument appears in header files and can be readily shared.
    
    Functions with default arguments can be overloaded. Note that default values are not part of a function signature, and therefore not part of overload resolution.
    This means it is very easy to cause ambiguity with default values. Consider two versions of foo, one which takes an int and the other a double. Both have a default value.
        Which version should be called if foo() is called (with no arguments)?
    
    Note that default arguments don’t work for functions called through function pointers
*/

#include <iostream>

// some examples where a default argument makes sense
int rollDie(int sides=6);
void openLogFile(std::string filename="default.log");

void print(int x, int y=4) // 4 is the default argument. note that it must be =, not parantheses or brace initialization
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

void print(char c = ' ') {
    std::cout << c << '\n';
}

void print(std::string_view s)
{
    std::cout << s << '\n';
}



// void print(int x=10, int y); // not allowed

int main()
{
    print(1, 2); // y will use user-supplied argument 2
    print(3); // y will use default argument 4, as if we had called print(3, 4)
    print('a');            // resolves to print(char)
    print();               // resolves to print(char)

    return 0;
}