/*
Null Pointers
    If a pointer holds a null value, it indicates that it is currently pointing to nothing.
    They are easily initialized with value initialization. The nullptr keyword represents a null pointer literal.
    Note that de-referencing a null pointer can cause unexpected behavior, including a crash.

    For historical reasons, null pointers can also be created by initializing a pointer with a literal 0. The same is true for the preprocessor macro NULL.
        Prefer using nullptr instead of these 2.
    Due to how easily things can go wrong when using pointers, prefer using references unless needing some capability only a pointer could provide.
*/

#include <iostream>

int main()
{
    int* ptr4 {}; // ptr is now a null pointer, and is not holding an address

    int* ptr2 { nullptr }; // can use nullptr to initialize a pointer to be a null pointer

    int value { 5 };
    int* ptr3 { &value }; // ptr2 is a valid pointer
    ptr3 = nullptr; // Can assign nullptr to make the pointer a null pointer

    //someFunction(nullptr); // we can also pass nullptr to a function that has a pointer parameter

    int x { 5 };
    int* ptr { &x };

    // pointers convert to Boolean false if they are null, and Boolean true if they are non-null
    if (ptr) // implicit conversion to Boolean
        std::cout << "ptr is non-null\n";
    else
        std::cout << "ptr is null\n";

    int* nullPtr {};
    std::cout << "nullPtr is " << (nullPtr ? "non-null\n" : "null\n"); // implicit conversion to Boolean

    return 0;
}