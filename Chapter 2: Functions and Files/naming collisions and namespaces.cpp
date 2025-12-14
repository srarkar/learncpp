/*
Naming
    Identifiers must be non-ambiguous. If we tried to access some identifier and found multiple with the same name, we wouldn't know which to access.
    This is known as a naming collision or naming conflict.
        If the colliding identifiers reside in the same file -> compiler error
        If the colliding identifiers reside across files in a project -> linker error
    
Scope Regions
    We can use groupings to isolate collidiing identifiers from each other.
    A scope region is an area of source code where all declared identifers are considered distinct from names declared in other scopes. 
    Two identifiers with the same name can be declared in separate scope regions without causing a naming conflict.
        However, within a given scope region, all identifiers must be unique, otherwise a naming collision will result.

Namespaces
    A namespace is a type of scope region (namespace scope) that allows names to be defined/declared inside of it for disambiguation
    For example, identical functions can be declared in separate namespaces without conflicting.
    A namespace may only contain definitions and declarations. Executable statements must be within a definition.

    Any name not defined in a class, function, or namespace is part of an implicitly-created global namespace (or global scope)
        Identifiers declared inside the global scope are in scope from the point of declaration to the end of the file.
        Although variables can be defined in the global namespace, it should be avoided
    
    When C++ was originally designed, there were issues with conflicts of identifiers in the C++ standard library, which were part of the global namespace.
    This also caused issues with code compiled under some versions not being compatible with others (forward compatibility).
    This lead to the introduction of the std namespace, which encompasses the functionalities of the standard library.

    We can tell the compiler that we are using an identifier from a namespace via the scope resolution operator (::)
    The identifier to the left of the operator is the namespace, and the identifier to the right is the symbol within it.
    If no identifier on the left is specified, it is assumed to be global.

    We can also use a using-directive to state what namespace to use when not specified. However, this can create conflicts.
    Creating an identifirr that also exists in the std namespace will cause ambiguity and compile errors
*/



// #include <iostream>
// int main() {
//     std::cout << "specifying the std namespace!" << '\n'; // std::cout is a qualified name, where std is the namespace and cout is the symbol in it
//     return 0;
// }

// alternatively...

#include <iostream>
using namespace std; // this using-directive allows us to access the std namespace without the namespace prefix
// however, this is not the right way to do it...


// int cout() // defines our own "cout" function in the global namespace
// {
//     return 5;
// }

int main() {
    cout << "using namespace std!" << '\n'; // doesn't compile!
}