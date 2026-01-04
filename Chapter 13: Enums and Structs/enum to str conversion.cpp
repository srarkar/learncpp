/*
Enumeration to String
    Typically, the way to access the name of an enumerator is by writing a function to do so. A convenient way to structure the function is using a switch statement.
    The enumerators can also be mapped to strings using an array.

    For input, we could ask for an integer from the user and then cast it to the enum. This is a bit clunky and also requires checking the integer value being in the valid enum range before casting.
    Instead, the user could input a string, and the program uses if statements and an std::optional to convert it into the appropriate enum.
*/

#include <iostream>
#include <string_view>

enum Color
{
    black,
    red,
    blue,
};

constexpr std::string_view getColorName(Color color) // this works since C-style strings exist for the program duration
{
    switch (color)
    {
    case black: return "black";
    case red:   return "red";
    case blue:  return "blue";
    default:    return "???";
    }
}

int main()
{
    constexpr Color shirt{ blue };

    std::cout << "Your shirt is " << getColorName(shirt) << '\n';

    return 0;
}