#include <iostream>


int main() {
    // execution begins here and proceeds from top to bottom
    int width; // define width, which allocates memory for the variable
    width = 5; // copy assignment that gives width a value of 5

    std::cout << width; // prints 5

    width = 7; // changes value in width to 7

    std::cout << width; // prints 7


    // {6} is the initializer, 6 is the initial value
    int length { 6 };

    /// 5 common forms of initialization
    int a; // no initializer (default)

    // Traditional ways
    int b = 5; // copy-initialization
    int c (6); // direct-initialization

    // Modern ways
    int d { 5 };   // direct-list-initialization (preferred)
    int e = { 6 }; // copy-list-initialization (rarely used)
    int f {}; // value-initialization

    int g = 4.5; // both of these will drop the .5 (a narrowing conversion/loss of information)
    int h (4.5); // compiler might give warning, but not error

    int i {4.5}; // this will not compile, requires explicit cast to allow it

    return 0;
}
