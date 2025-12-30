/*
Switch Statements
    Switch statements are the other conditional statement choice. They are often used to avoid having long chains of ifs and else-ifs when evaluating many cases.

    The idea is to evaluate an expression/condition to produce a value.
    Then, we have some case labels, and whichever match the value mean the corresponding statements will execute. 
        If none of the case labels execute, then a default case will execute, if it exists. If it doesn't exist, the switch is effectively skipped entirely.
    
    The condition of the switch must evaluate to an integral type, since they are designed to be highly optimized due to compilers often implementing them with jump tables.

    We use labels to determine which values to specify behavior for.
        A case label is followed by a constant expression, and it must match (or be convertible to) the type of the condition.
        The default label is triggered if none of the case labels are matched by the value of the condition. It is placed last.
    A break statement can be used to jump to the line after the end of the switch block.

    When to prefer to use if-else:
        Testing an expression for comparisons other than equality (e.g. x > 5)
        Testing multiple conditions (e.g. x == 5 && y == 6)
        Determining whether a value is within a range (e.g. x >= 5 && x <= 10)
        The expression has a type that switch doesn’t support (e.g. d == 4.0).
        The expression evaluates to a bool.
*/

/*
Switch Fallthroughs and Scoping
    Once a case or default is matched, it will continue executing at the start of its block until one of the following conditions is met:
        The end of the switch block is reached.
        Another control flow statement (typically a break or return) causes the switch block or function to exit.
        Something else interrupts the normal flow of the program (e.g. the OS shuts the program down, the universe implodes, etc…)

    Therefore, if a return or break is omitted, we will hit one case and execute all the cases after it until the end of the entire switch block.
    The compiler may flag this as a warning, but there may be some select cases where this fallthrough is intended behavior.

    C++17 added an attribute called [[fallthrough]] to indicate the behavior is intended and should not trigger a warning.

    If defining variables used in a case statement, do so in a block inside the case.
*/

#include <iostream>

void printDigitName(int x)
{
    switch (x) // x evaluates to 3
    {
    case 1:
        std::cout << "One";
        break;
    case 2:
        std::cout << "Two";
        break;
    case 3:
        std::cout << "Three"; // execution starts here
        break; // jump to the end of the switch block
    default:
        std::cout << "Unknown";
        break;
    }

    // execution continues here
    std::cout << " Ah-Ah-Ah!";

    switch (2)
    {
    case 1:
        std::cout << 1 << '\n';
        break;
    case 2:
        std::cout << 2 << '\n'; // Execution begins here
        [[fallthrough]]; // intentional fallthrough -- note the semicolon to indicate the null statement
    case 3:
        std::cout << 3 << '\n'; // This is also executed
        break;
    }

    // char c {'a'};

    // switch (c)
    // {
    // case 'a': // if c is 'a'
    // case 'e': // or if c is 'e'
    // case 'i': // or if c is 'i'
    // case 'o': // or if c is 'o'
    // case 'u': // or if c is 'u'
    // case 'A': // or if c is 'A'
    // case 'E': // or if c is 'E'
    // case 'I': // or if c is 'I'
    // case 'O': // or if c is 'O'
    // case 'U': // or if c is 'U'
    //     return true;
    // default:
    //     return false;
}

int main()
{
    printDigitName(3);
    std::cout << '\n';
    

    switch (2)
    {
    case 1: // Does not match
        std::cout << 1 << '\n'; // Skipped
    case 2: // Match!
        std::cout << 2 << '\n'; // Execution begins here
    case 3:
        std::cout << 3 << '\n'; // This is also executed
    case 4:
        std::cout << 4 << '\n'; // This is also executed
    default:
        std::cout << 5 << '\n'; // This is also executed
    }

    return 0;
}
