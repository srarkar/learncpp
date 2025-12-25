/*
    Static Local Variables
        Static has many different meanings for different contexts. Here we will discuss how it applies when used for a local variable.
        
        By default, local variables have automatic duration, meaning they are created at the point of definition, and destroyed at the end of their block.
        Applying the static keyword to a local variable gives it static duration, meaning it is created at the start of the program, and is destroyed when the program ends, much like a global.

        Thus, even though the local variable is still only accessible within its function, its value will persist between function calls.
        It is common to use an "s_" prefix to such variables. A common usage case would be ID generation (see below).
        They can also be useful if a program only needs to use a value that doesn't change, and the cost of initializing is expensive.

        Non-const static local variables should generally be avoided. 
        If you do use them, ensure the variable never needs to be reset, and isn’t used to alter program flow.
*/

#include <iostream>

void incrementAndPrint()
{
    static int s_value{ 1 }; // static duration via static keyword.  This initializer is only executed once.
    ++s_value;
    std::cout << s_value << '\n';
} // s_value is not destroyed here, but becomes inaccessible because it goes out of scope

/*
The first time this function is called, it returns 0.
The second time, it returns 1.
Each time it is called, it returns a number one higher than the previous time it was called.
You can assign these numbers as unique IDs for your objects. Because s_itemID is a local variable, it can not be “tampered with” by other functions.
*/
int generateID()
{
    static int s_itemID{ 0 };
    return s_itemID++; // makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
}

int main()
{
    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();

    return 0;
}