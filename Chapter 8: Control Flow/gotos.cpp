/*
Goto Statements
    Goto statements are an unconditional jump, meaning that they do not depend on some condition being true.
    They involve a statement label, which is the destination of the jump. These labels have function scope, so they are visible throughout the function (even before the point of declaration).
    They also must be associated with a statement, even if it is a null statement.

    Use of goto is shunned in C and C++ as they allow arbitary jumps around code that is difficult to follow.
    There is almost always a cleaner way to write the code than using a goto.
    One notable exception is for the purpose of exiting a nested loop but not the entire function
*/

#include <iostream>
#include <cmath> // for sqrt() function

void printCats(bool skip)
{
    if (skip)
        goto end; // jump forward; statement label 'end' is visible here due to it having function scope

    std::cout << "cats\n";
end:
    ; // statement labels must be associated with a statement
}


int main()
{
    double x{};
tryAgain: // this is a statement label
    std::cout << "Enter a non-negative number: ";
    std::cin >> x;

    if (x < 0.0)
        goto tryAgain; // this is the goto statement

    std::cout << "The square root of " << x << " is " << std::sqrt(x) << '\n';

    // one of the few cases that goto is reasonable to use
    for (int i = 1; i < 5; ++i)
    {
        for (int j = 1; j < 5; ++j)
        {
            std::cout << i << " * " << j << " is " << i*j << '\n';

            // If the product is divisible by 9, jump to the "end" label
            if (i*j % 9 == 0)
            {
                std::cout << "Found product divisible by 9.  Ending early.\n";
                goto end;
            }
        }

        std::cout << "Incrementing the first factor.\n";
    }

end:
    std::cout << "And we're done." << '\n';


    return 0;
}
