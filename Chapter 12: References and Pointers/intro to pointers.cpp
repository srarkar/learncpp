/*
& and *
    When a variable is defined, some piece of memory is assigned to the object. 
    Since we can just use the identifier of the variable to access it, the programmer doesn't need to know where exactly the variable is stored in memory.
        The same applies for references.
    
    Even though the memory addresses are not exposed by default, they are accessible using the "address-of" operator &.
        This operator returns a pointer to to the operand, not a literal value. This pointer contains the address of the operand.
        When following a type name, & denotes an lvalue reference: int& ref.
        When used in a unary context in an expression, & is the address-of operator: std::cout << &x.
        When used in a binary context in an expression, & is the Bitwise AND operator: std::cout << x & y.
    For objects that take up more than one byte of memory, the & will provide the location of the first byte they occupy.

    From an address, we can access the value that is stored at that address by de-referencing it (*). This is also called the indirection operator.

Pointers
    A pointer is an object that holds a memory address as its value, and a type that specifies a pointer is called a pointer type (such as int *).
        Typically, pointers will hold an address of another variable / object in order to access its value.

    Pointers are not initialized by default. An uninitialized pointer is known as a wild pointer, and contain a garbage address.
        Pointers also are not allowed to be initialized with a literal value, with one exception (string literal, and possibly null pointers (0))
    
    Pointers behave much like lvalue references. Some differences:
        References must be initialized, pointers are not required to be initialized (but should be).
        References are not objects, pointers are.
        References can not be reseated (changed to reference something else), pointers can change what they are pointing at.
        References must always be bound to an object, pointers can point to nothing (we’ll see an example of this in the next lesson).
        References are “safe” (outside of dangling references), pointers are inherently dangerous (we’ll also discuss this in the next lesson).

    The size of a pointer is dependent upon the architecture the executable is compiled for -- a 32-bit executable uses 32-bit memory addresses -- consequently, a pointer on a 32-bit machine is 32 bits (4 bytes). 
        With a 64-bit executable, a pointer would be 64 bits (8 bytes). 
        Note that this is true regardless of the size of the object being pointed to.
    
    Much like a dangling reference, a dangling pointer is a pointer that is holding the address of an object that is no longer valid. It is undefined behavior to de-reference a dangling pointer.
    One can assign an invalid pointer a new value, such as nullptr (because this doesn’t use the invalid pointer’s value). 
        However, any other operations that use the invalid pointer’s value (such as copying or incrementing an invalid pointer) will yield implementation-defined behavior.
*/

#include <iostream>

int main()
{
    int x{ 5 };
    int& ref { x }; // a reference to an integer (bound to x)
    int* ptr { &x };       // a pointer to an integer

    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (5)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (5)

    ref = 6; // use the reference to change the value of x
    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (6)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (6)

    *ptr = 7; // use the pointer to change the value of x
    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (7)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (7)

    int i{ 5 };
    double d{ 7.0 };

    int* iPtr{ &i };     // ok: a pointer to an int can point to an int object
    //int* iPtr2 { &d };   // not okay: a pointer to an int can't point to a double object
    double* dPtr{ &d };  // ok: a pointer to a double can point to a double object
    //double* dPtr2{ &i }; // not okay: a pointer to a double can't point to an int object

    return 0;
}