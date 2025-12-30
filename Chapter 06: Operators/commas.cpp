/*
Commas
    The comma operator is interesting -- it has the lowest precedence of all operators (even lower than assignment). 
    It separates a left and right operand. It evalutes the left, then the right, and only returns the result of the right operand.
    It can be dangeorus in that it leads to similar-looking code to have very different behavior. As such, it is almost exclusively used within for loops.
    
    Commas are also used as a separator, which is distinct from its use as an operator. An easy example is multiple arguments in function headers.
*/

#include <iostream>

int main()
{
    int x{ 1 };
    int y{ 2 };

    std::cout << (++x, ++y) << '\n'; // increment x and y, evaluates to the right operand
    int z{ };

    // z = (a, b); // evaluate (a, b) first to get result of b, then assign that value to variable z.               effectively z = b
    // z = a, b; // evaluates as "(z = a), b", so z gets assigned the value of a, and b is evaluated and discarded. effectively z = a

    return 0;
}