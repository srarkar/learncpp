/*
User-defined Conversions
    Type conversion between fundamental types can be handled implicitly by the compiler. However, it does not know how to do the same when program-defined types are involved.
    When such a type conversion is needed, the compiler will look for a function it can use to do so, which is known as a user-defined conversion

    A constructor that can be used to perform an implicit conversion is called a converting constructor. By default, all constructors are converting constructors.
    When an implicit conversion is applied, only one user-defined conversion can be used.
        To help reduce the number of implicit conversions, it is useful to know that an implicit conversion can be trivially converted into an explicit definition by using direct or direct list initialization.

Explicit
    However, this can sometimes backfire. We may want to prevent implicit conversions by the compiler in order to only allow certain objects to be passed into a functon.
    The explicit keyword tells the compiler that a constructor should not be used as a converting constructor.

    The consequences of applying it are:    
        An explicit constructor cannot be used to do copy initialization or copy list initialization.
        An explicit constructor cannot be used to do implicit conversions (since this uses copy initialization or copy list initialization).
    An explicit constructor can still be used for direct and direct list initialization

    When we return a value from a function, if that value does not match the return type of the function, an implicit conversion will occur. Just like with pass by value, such conversions cannot use explicit constructors.
    Copy and move constructors should not be made explicit since they do not perform conversions.
    Default constructors without parameters and constructors that only take multiple parameters are usually not make explicit.
    Constructors that take a single argument, on the other hand, should be made explicit.

    If an implicit conversion between types is both semantically equivalent and performant, you can consider making the constructor non-explicit.
*/

#include <iostream>

class Dollars
{
private:
    int m_dollars{};

public:
    explicit Dollars(int d) // now explicit
        : m_dollars{ d }
    {
    }

    int getDollars() const { return m_dollars; }
};

void print(Dollars d)
{
    std::cout << "$" << d.getDollars();
}

int main()
{
    //print(5); // compilation error because Dollars(int) is explicit

    return 0;
}