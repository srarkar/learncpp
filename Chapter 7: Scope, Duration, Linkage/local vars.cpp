/*
Local Variables
    Local variables are those defined inside a function, include parameters.
    They have block scope, meaning they are in scope from their definition to the end of the block they were defined in.
    Local variables have automatic storage duration, which means they are created at the point of definition and destroyed at the end of the block they are defined in.

    An identifier's linkage refers to whether a declaration of the same identifier in a different scope refers to the same object or function.
    Each declaration of an identifier with no linkage refers to a unique object or function (only visible within defining scope). Local variables have no linkage.

    Limiting the scope of variables to exactly where needed is generally good, as fewer active variables means more efficient code.

    Scope vs duration vs linkage (review)
        A variable’s scope determines where the variable is accessible within the source code. Duration defines the rules that govern when a variable is created and destroyed. A variable’s lifetime is the actual time between its creation and destruction.
        Local variables have block scope, which means they can be accessed from their point of definition to the end of the block they are defined within.
        Local variables have automatic duration, which means they are created at the point of definition, and destroyed at the end of the block in which they are defined.
*/

/*
Write a program that asks the user to enter two integers, one named smaller, the other named larger.
If the user enters a smaller value for the second integer, use a block and a temporary variable to swap the smaller and larger values.
Then print the values of the smaller and larger variables. Add comments to your code indicating where each variable dies.
Note: When you print the values, smaller should hold the smaller input and larger the larger input, no matter which order they were entered in.
*/
#include <iostream>
#include <utility>

int getInt() {
    std::cout << "Enter an integer: ";
    int input {};
    std::cin >> input;
    return input;
}

void bigAndSmall() {
    int smaller {getInt()};
    int larger {getInt()};

    if (larger < smaller) {
        int temp {smaller};
        smaller = larger;
        larger = temp;
    } // temp dies

    std::cout << "Smaller input: " << smaller << '\n';
    std::cout << "Larger input: " << larger << '\n';
} // smaller and larger die

int main()
{ // outer block

    int x { 5 }; // x enters scope and is created here

    { // nested block
        int y { 7 }; // y enters scope and is created here

        // x and y are both in scope here
        std::cout << x << " + " << y << " = " << x + y << '\n';
    } // y goes out of scope and is destroyed here

    // y can not be used here because it is out of scope in this block

    return 0;
} // x goes out of scope and is destroyed here