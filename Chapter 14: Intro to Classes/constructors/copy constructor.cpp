/*
The Copy Constructor
    A copy constructor is the constructor used to initialize an object using an existing object of the same type.
    The result is the newly created object being a copy of the original one that was used as an initializer.

    If not provided by the user, C++ creates an implicit copy constructor, which performs memberwise initialization.   
        This should be generally preferred over the explicit one.
    It can be made explicitly, by taking the class as a parameter. This parameter type is usually a const lvalue reference.

    The copy constructor should not be made to do anything except copy, as the compiler may optimize it out and cause any additional behavior to not run.
    If we wish to prevent an object from being copyable, we can mark the copy constructor with "= delete"

The rule of three (or five)
    The rule of three states that if a class requires a user-defined copy constructor, destructor, or copy assignment operator, then it most likely requires all 3.
        Not doing so can lead to malfunctioning code related to dynamic memory allocation.
    This was later expanded to the rule of 5 in C++11 to include the move constructor and move assignment operator. 
*/

#include <iostream>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1)
        : m_numerator{numerator}, m_denominator{denominator}
    {
    }
    

    // // Explicitly request default copy constructor
    // Fraction(const Fraction& fraction) = default;

    // Delete the copy constructor so no copies can be made
    // Fraction(const Fraction& fraction) = delete;

    // Copy constructor
    Fraction(const Fraction& fraction)
        // Initialize our members using the corresponding member of the parameter
        : m_numerator{ fraction.m_numerator }
        , m_denominator{ fraction.m_denominator }
    {
        std::cout << "Copy constructor called\n"; // just to prove it works
    }

    void print() const
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main()
{
    Fraction f { 5, 3 };  // Calls Fraction(int, int) constructor
    Fraction fCopy { f }; // Calls Fraction(const Fraction&) copy constructor

    f.print();
    fCopy.print();

    return 0;
}