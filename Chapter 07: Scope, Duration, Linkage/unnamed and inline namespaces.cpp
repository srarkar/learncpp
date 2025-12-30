/*
Unnamed Namespaces
    Namespaces can be declared without a name. All identifiers inside this namespace have internal linkage.
    For functions inside the namespace, it is very similar to them being static, so that some group of identifiers stays local to a single translation unit.
    Avoid using them in header files, due to ODR violating and unexpected behavior.

Inline Namespaces
    Say we have an existing function that we want to alter without breaking prior programs that rely on the old one.
    Creating a new function each time is fine, but can become tedious. An inline namespace is primarily used for this kind of "versioning".
    We can create multiple namespaces, and whichever one is inline is the default/preferred choice for a function call.
    Those who want to use a different version can use the scope resolution operator to specify.

A namespace can be both inline and unnamed. However, in such cases, it’s probably better to nest an anonymous namespace inside an inline namespace. 
This has the same effect (all functions inside the anonymous namespace have internal linkage by default) but still gives you an explicit namespace name you can use.
*/

// #include <iostream>

// namespace // unnamed namespace
// {
//     void doSomething() // can only be accessed in this file
//     {
//         std::cout << "v1\n";
//     }
// }

// int main()
// {
//     doSomething(); // we can call doSomething() without a namespace prefix

//     return 0;
// }

#include <iostream>

inline namespace V1 // declare an inline namespace named V1
{
    void doSomething()
    {
        std::cout << "V1\n";
    }
}

namespace V2 // declare a normal namespace named V2
{
    void doSomething()
    {
        std::cout << "V2\n";
    }
}

int main()
{
    V1::doSomething(); // calls the V1 version of doSomething()
    V2::doSomething(); // calls the V2 version of doSomething()

    doSomething(); // calls the inline version of doSomething() (which is V1)

    return 0;
}