/*
Do-While Loops
    Sometimes we want to include behavior as part of a loop, but want to ensure we always run it once.
    Consider the case where we want to show the user a menu and ask them to make a selection -- and if the user chooses an invalid selection, to ask them again.

    The best choice is a do-while loop, which always runs its associated block of code once before the condition is checked.
    It avoids the necessity of using a boolean flag or magic numbers entirely, but a standard while loop should be preferred if there is no compelling argument for one over the other.
*/

#include <iostream>

int main()
{
    // selection must be declared outside of the do-while-loop, so we can use it later
    int selection {};

    do
    {
        std::cout << "Please make a selection: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> selection;
    }
    while (selection < 1 || selection > 4);

    // do something with selection here
    // such as a switch statement

    std::cout << "You selected option #" << selection << '\n';

    return 0;
}