/*
Intro to Destructors
    If an object of a class uses some resource or setup and requires cleanup its use, it doesn't make sense to leave the responsibility of this to the user.
    When we know that an object needs to be performed, we can use destructors to perform it automatically after the object of a non-aggregate class type is destroyed.

    Destructors have very specific naming rules:    
        - The destructor must have the same name as the class, preceded by a tilde (~).
        - The destructor can not take arguments.
        - The destructor has no return type.
    These are usually not called explicitly since that would cause the cleanup to occur multiple times.
    Destructors may call other member functions since the object isn’t destroyed until after the destructor executes.

    The compiler will generate an implicit empty destructor that basically serves as a placeholder if the user doesn't provide one.

    Warning: when std::exit() is called, the program simply ends without destroying locals or calling destructors.
    Unhandled exceptions will also cause the program to terminate, and may not unwind the stack before doing so. If stack unwinding does not happen, destructors will not be called prior to the termination of the program.  
*/

#include <iostream>

class Simple
{
private:
    int m_id {};

public:
    Simple(int id)
        : m_id { id }
    {
        std::cout << "Constructing Simple " << m_id << '\n';
    }

    ~Simple() // here's our destructor
    {
        std::cout << "Destructing Simple " << m_id << '\n';
    }

    int getID() const { return m_id; }
};

int main()
{
    // Allocate a Simple
    Simple simple1{ 1 };
    {
        Simple simple2{ 2 };
    } // simple2 dies here

    return 0;
} // simple1 dies here