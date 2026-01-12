/*
Static Member Variables
    We can apply the static keyword to member variables. Doing so makes the variable shared among all objects of the class type.
    Since these variables are created at the start of the program, static member variables exist even if there are no instances of the class type.
        That is, these variables are not associated with class objects, as they are global variables that live in the scope of the class.
        This also means these variables can be accessed directly using the class name and the scope resolution operator.
    
    Since static member variables are essentially global variables, they must be explicitly defined (and optionally initialized) outside the class.
    For non-template classes, if the class is defined in a header file, the static member definition is usually placed in the associated .cpp code file for the class.
    For template classes, the (templated) static member definition is typically placed directly underneath the template class definition in the header file.

    If the static member is a constant integral type or a const enum, it can be initialized inside the class definition.
        This shortcut is allowed because these specific const types are compile-time constants.
        The same applies for inline (constant or not) and constexpr variables.
    Static variables can be useful if the entire class shares some information (such as a lookup table). This reduces redundancy and the amount of memory used.
    
    Only static members may use type deduction (auto and CTAD).
        Using these with non-static members is not allowed since there are specific cases where it would cause ambiguity / non-intuitive results.
*/


#include <iostream>

class Something
{
private:
    static inline int s_idGenerator { 1 };
    int m_id {};

public:
    // grab the next value from the id generator
    Something() : m_id { s_idGenerator++ }
    {
    }

    int getID() const { return m_id; }
};

int main()
{
    Something first{};
    Something second{};
    Something third{};

    std::cout << first.getID() << '\n';
    std::cout << second.getID() << '\n';
    std::cout << third.getID() << '\n';
    return 0;
}