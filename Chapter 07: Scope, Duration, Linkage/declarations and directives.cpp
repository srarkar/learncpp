/*
    Declarations and Directives
        Before namespace support, all the names in the std namespace belonged to the global namespace, causing collisions between program identifiers and standard library identifiers.
            Programs would work on some C++ versions and not others.
        When namespaces became standardized in 1995, it broke code that did not use the std:: prefix when accessing the names that now belonged to the std namespace.

        A qualified name is one that includes an associated scope. Usually, names are qualified via the scope resolution operator (::). A name can also be qualified through a class name or object.
            Naturally, an unqualified name does not include a scoping qualifier.

        To reduce the repetition of using std:: in every standard library usage is through a using-declaration statement, which allows the usage of an unqualified name as an alias for a qualified one.

        A using-directive, however, allows all identifiers in a specified namespace to be referenced without qualification.
            This can lead to naming collisions since there is no concept of priority of the namespace, and many names are included that will likely not be used.
            When the compiler encounters a function call, it has to determine what function definition it should match the function call with.
            In selecting a function from a set of potentially matching functions, it will prefer a function that requires no argument conversions over a function that requires argument conversions.
            This means that if we have two functions of the same name, the compiler may prefer one that the programmer does not expect it to, causing unintended behavior.

        The using keyword is also used to define type aliases, which are unrelated to using-statements.
*/

#include <iostream>

int main()
{
   using std::cout; // this using declaration tells the compiler that cout should resolve to std::cout
   cout << "Hello world!\n"; // so no std:: prefix is needed here!

   return 0;
} // the using declaration expires at the end of the current scope

/*
#include <iostream>

int main()
{
   using namespace std; // all names from std namespace now accessible without qualification
   cout << "Hello world!\n"; // so no std:: prefix is needed here

   return 0;
} // the using-directive ends at the end of the current scope
 */