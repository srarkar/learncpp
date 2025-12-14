#include <iostream>


/*
Forward Declarations
    Reordering functions can be tedious when dealing with large codebases.
    Instead, we can use forward declarations so the compiler is aware of a function, even if it is not yet defined.
    This is done using a function declaration, or function prototype. 
        Note that parameter names are not necessary to add
    Forward declarations can be useful for organization, by grouping related functions
    In rare cases, they may also be used when two functions call each other

    Declaring a function but never creating the body can create linker errors if that function is called.

    The Google C++ guide weighs the pros and cons of forward declarations.
    Pros:
        - They can save on compile-time, as #include headers require the compiler to open/unpack more files and process more input
        - They can save unnecessary recompilation. Unrelated changes in the included header file can create more recompilations
    Cons:
        - Forward declarations can hide a dependency, allowing user code to skip necessary recompilation when headers change.
        - A forward declaration as opposed to an #include statement makes it difficult for automatic tooling to discover the module defining the symbol.
        - A forward declaration may be broken by subsequent changes to the library. Forward declarations of functions and templates can prevent the header owners from making otherwise-compatible changes to their APIs, such as widening a parameter type, adding a template parameter with a default value, or migrating to a new namespace.
        - Forward declaring symbols from namespace std:: yields undefined behavior.
        - It can be difficult to determine whether a forward declaration or a full #include is needed. Replacing an #include with a forward declaration can silently change the meaning of code
        - Multiple forward declarations can be less readable than a single #include.
        - Structuring code to enable forward declarations (e.g., using pointer members instead of object members) can make the code slower and more complex
    
    The conclusion is to try to avoid forward declarations of entities defined in another project.
*/

/*
Declarations and Definitions
    Forward declarations exist for other identifiers such as variables.
    A declaration tells the compiler about the existence of an identifier and its associated type information.
        int x; // this is both a declaration and definition
        int add(int x, int y);
    A definition is a declaration that implements or instantiates the identifier.
    In C++, all definitions are declarations.
*/


// by adding this function prototype, we do not need to move the body of add() at all. 
int add(int x, int y); // function declaration includes return type, name, parameters, and semicolon.  No function body!
// int add(int, int) // this is also valid! but not necessarily best practice

// This doesn't compile! Since the call to add is before its declaration, we have an unknown add identifier due to the sequential nature of the compiler.
// int main()
// {
//     std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
//     return 0;
// }

// int add(int x, int y)
// {
//     return x + y;
// }