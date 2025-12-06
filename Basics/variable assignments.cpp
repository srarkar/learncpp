#include <iostream>

/*
Variable Assignment
    After defining a variable, it can be given a value through an assignment, with the assignment operator being an '='. 
    Copy assignment involves the value of the right side of the operator being copied to the variable identified on the left side of the operator.

    The definiton and initialization steps can be combined. The sytax used to do so is called an initializer.

    Common forms of initialization:
        Default-initialization:
            - no initializer is provided
            - leaves variable holding indeterminate/garbage value
        Copy-initialization:
            - inherited from C
            - somewhat fallen out of favor as modern initializers are more efficient
            - also used whenever values are implicitly copied, passing arguments by value, returning from a function by value, or catching exceptions by value
        Direct-initialization:
            - introduced for more efficient initialization of complex objects, but also recently fallen out of favor due to the existence of direct-list-initialization
            - also used when values are explicitly cast to another type (e.g. via static_cast).
        List-initialization (aka uniform initialization or brace initialization):
            - modern approach to initializing objects
            - the curly braces tell us we are doing an initialization, compared to other forms such as copy or direct that can be ambiguous
            - disallows narrowing conversions, such as attempting to assign an integer a floating point number
            - it also supports initializations of a list of values
        Value-initialization:
            - a special type of list-initialization that leaves the curly braces empty
            - this will set the variable to some default value, which depends on the object
            - if this value is 0, then it is known as zero-initialization
*/
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

    /// direct-list-initialization versus value-initialization
    // direct when we want to use the 0 value
    int x { 0 };    // direct-list-initialization with initial value 0
    std::cout << x; // we're using that 0 value here

    // leave empty when planning to overwrite it anyways
    int x {};      // value initialization
    std::cin >> x; // we're immediately replacing that value so an explicit 0 would be meaningless

    return 0;
}
