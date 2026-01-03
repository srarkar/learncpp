/*
Pointers and Const
    Attempting to point a normal pointer at a const variable would not compile, since pointers have the ability to change the values they point to.
    We can add const to the pointer declaration before the data type. This means the pointer refers to a const, not that the pointer itself cannot change.
        Pointers to const can point to non-const values, but it will still treat the value as const.
    
    Using const after the asterisk makes the pointer itself constant (i.e. a const pointer). It must be initialized upon definition, and cannot be reassigned.
    However, the value being pointed to can still be altered by de-referencing the pointer.

    Of course, this means the existence of a const pointer to const -- a pointer that cannot change, which points to a value that itself is treated as a const.
        A const pointer to a const value can not have its address changed, nor can the value it is pointing to be changed through the pointer. 
        It can only be dereferenced to get the value it is pointing at.

    
*/


int main()
{
    int v{ 5 };

    int* ptr0 { &v };             // points to an "int" but is not const itself.  We can modify the value or the address.
    const int* ptr1 { &v };       // points to a "const int" but is not const itself.  We can only modify the address.
    int* const ptr2 { &v };       // points to an "int" and is const itself.   We can only modify the value.
    const int* const ptr3 { &v }; // points to a "const int" and is const itself.  We can't modify the value nor the address.

    // if the const is on the left side of the *, the const belongs to the value
    // if the const is on the right side of the *, the const belongs to the pointer

    return 0;
}