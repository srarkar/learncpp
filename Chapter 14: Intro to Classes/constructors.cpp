/*
Intro to Constructors
    A class type with private members cannot use aggregate initialization.
        This makes sense since this form of initialization is member-wise, and so using it implies knowledge of the type's implementation.
        This would also involve relying on the user to abide by class invariants.
    Instead, to initialize an object of such a class type, we use a matching constructor.

    A constructor is a special member function called automatically when a non-aggregate class type is created.
        If a matching accessible constructor is not found, the compiler will error.
        Aggregates are not allowed to have a constructor. If an aggregate has one, it is no longer an aggregate.
    
    Constructors generally perform initialization of member variables (via a member initialization list) and perform other setup such as opening files or databases.
        As such, they cannot be const. However, a constructor can be applied to a const object, since the initialization occurs before the const is applied.

    Constructors are designed to initialize an entire object at the point of instantiation. Setters are designed to assign a value to a single member of an existing object.

    As for naming conventions, constructors must have the same name as the class name (case-sensitive).
        This excludes template parameters in the case of template classes.
    They also have no return type (not even void).


*/

#include <iostream>

class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo(int x, int y) // here's our constructor function that takes two initializers
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Foo foo{ 6, 7 }; // calls Foo(int, int) constructor
    foo.print();

    return 0;
}