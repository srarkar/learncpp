/*
Pass by Address
    Along with pass by value and reference, C++ provides a third way to pass values as arguments: pass by address.
    Instead of passing an object as an argument, the caller will pass the address of the object inside a pointer.
    This pointer is copied into the function parameter, allowing the function to de-reference the pointer to access the object.

    This does not make a copy of the object, since the pointer simply references the original one.
    This also allows the function to modify the object being passed in.

    Prefer pointer-to-const function parameters over pointer-to-non-const function parameters, unless the function needs to modify the object passed in.
    Do not make function parameters const pointers unless there is some specific reason to do so.

    Prefer pass by reference to pass by address unless you have a specific reason to use pass by address.

    Pass by address can also be used for "optional" parameters. If passing in a nullptr, then that can be considered by the program as the parameter not being provided.
        It might be better to rely on function overloading instead.


    Pointers can also be passed by reference (pass by address by reference...).

    The reason 0 / NULL is not preferred over nullptr is because the literal 0 can be misinterpreted. Do we mean the integer literal or the null pointer literal?
        nullptr removes the ambiguity since it has a pointer type. Technically, its type is std::nullptr_t defined in header <cstddef>
*/

#include <iostream>
#include <string>

void printByValue(std::string val) // The function parameter is a copy of str
{
    std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const std::string& ref) // The function parameter is a reference that binds to str
{
    std::cout << ref << '\n'; // print the value via the reference
}

void printByAddress(const std::string* ptr) // The function parameter is a pointer that holds the address of str
{
    std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}

void nullify(int*& refptr) // refptr is now a reference to a pointer
{
    refptr = nullptr; // Make the function parameter a null pointer
}

int main()
{
    std::string str{ "Hello, world!" };

    printByValue(str); // pass str by value, makes a copy of str
    printByReference(str); // pass str by reference, does not make a copy of str
    printByAddress(&str); // pass str by address, does not make a copy of str

    int x{ 5 };
    int* ptr{ &x }; // ptr points to x

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    nullify(ptr);

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    return 0;
}