/*
Loops
    A while statement is the simplest of the three loop types C++ provides.
    It consists of a condition, and a statement or block. When the condition evaluates to true, the block is executed, and then it loops back to the condition again until it is false.

    If the condition always evaluates to true, we end up in an infinite loop. 
        This can be done intentionally, where the only way to break out is through a return, break, goto, exception, or the program being killed.
    
    A loop variable is a variable used to control how many times a loop runs. Integral loop variables should be signed to prevent strange behavior.
*/

#include <iostream>

// Write a program that prints out the letters a through z along with their ASCII codes. 
// Use a loop variable of type char.

void printAlphabet() {
    char currentChar {'a'};
    while (currentChar <= 'z') {
        std::cout << "Current char: " << currentChar << '\n';
        std::cout << "ASCII value: " << static_cast<int>(currentChar) << "\n\n";
        ++currentChar;
    }
}

int main()
{
    printAlphabet();
    return 0;
    int count{ 1 };
    while (count <= 10)
    {
        std::cout << count << ' ';
        ++count;
    }

    std::cout << "done!\n";

    while(true) {
        ;
    }

    // outer loops between 1 and 5
    int outer{ 1 };
    while (outer <= 5)
    {
        // For each iteration of the outer loop, the code in the body of the loop executes once

        // inner loops between 1 and outer
        // note: inner will be created and destroyed at the end of the block
        int inner{ 1 };
        while (inner <= outer)
        {
            std::cout << inner << ' ';
            ++inner;
        }

        // print a newline at the end of each row
        std::cout << '\n';
        ++outer;
    } // inner destroyed here

    return 0;
}