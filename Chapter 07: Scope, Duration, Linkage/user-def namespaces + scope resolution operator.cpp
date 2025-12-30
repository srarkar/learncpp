/*
User-defined Namespaces
    As a reminder, a naming collision occurs when two identical identifiers share the same scope, causing ambiguity over which is being used in an expression.
    If we had two function of the same name in two different files that belong to the same project, we would run into a linker error in attempting to compile.
    
    Instead of renaming one of the two functions, we can instead create a namespace with the namespace keyword. These are known as user-defined or program-defined namespaces.
    The syntax for it is:
        namespace NamespaceIdentifier {
        content of namespace here
        }
    Historically, namespace names have not been capitalized. 
    The Google C++ guide disallows additional identation for the contents (note how content is on the same column as namespace)

    A namespace must be defined either in the global scope, or inside another namespace.
    In the previous example, we could place each of the function in its own namespace.
    In the parent file that uses the function, it must now choose between one of the two namespaces to use, using the scope resolution operator (::) or a "using" statement.

    Scope resolution operator without a prefix (i.e. ::doSomething()) means global namespace.
    
    Forward declarations for identifiers in a namespace should also be inside the same namespace.
    Multiple namespace blocks for the same namespace will all belong to it. Also note that it is not allowed/undefined to add to the std namespace.

    Namespaces can also be nested, and can be alias'd with the assigment operator.
*/

#include <iostream>

void print() { // global namespace (default for operator::)
    std::cout << "here in global namespace";
}

namespace Foo { // define a namespace named Foo
// This doSomething() belongs to namespace Foo
int doSomething(int x, int y) {
    return x + y;
}

void print() { // this print() lives in the Foo namespace
    std::cout << "Hello";
}
}

namespace Goo { // define a namespace named Goo

// This doSomething() belongs to namespace Goo
int doSomething(int x, int y) {
    return x - y;
}
}

namespace Foo::Goo
{
    int add(int x, int y)
    {
        return x + y;
    }
}


int main() {
    std::cout << Foo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace Foo, via the scope resolution operator (::)
    ::print();

    namespace Active = Foo::Goo; // active now refers to Foo::Goo

    std::cout << Active::add(1, 2) << '\n'; // This is really Foo::Goo::add()

    return 0;   
}