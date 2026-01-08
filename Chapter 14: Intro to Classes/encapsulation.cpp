/*
Data Hiding (encapsulation)
    A very important concept is the separation of interface and implementation.

    The interface of a class type defines how a user interacts with objects of that class type.
        The public members of a class form its class interface, also known as a public interface.
        It is important that this interface is well-designed and stable, as changes can break the code that uses it.
    The implementation of a class type is the code that allows the class to work as intended.
        This includes both member variables and the bodies of member functions.

    Data hiding / information hiding / data abstraction is a technique that enforces the separation between interface and implementation.
    It does so by hiding the implementation of program-defined class types from users.
        This is easily achieved with private data members accessed through public member functions.
        This forces users to manipulate objects strictly through the public interface, without accessing or needing to understand implementation details.
    
    Data hiding also makes it easier to maintain class invariants and detect and handle errors.
    It also supports changes in implementation without breaking existing code, due to the public interface being separate.

    If possible, implement functions as non-member functions, as they tend to be easier to debug and do not need heavy attention when updating a class type.
        Use a member function when you have to. C++ requires that certain kinds of functions be defined as members. This includes constructors, destructors, virtual functions, and certain operators.
        Prefer a member function when the function needs access to private (or protected) data that should not be exposed.
    
    The most commonly recommended order for class types in modern C++ is:
        Declare public members first, protected members next, and private members last. 
        This spotlights the public interface and de-emphasizes implementation details.

    Google C++ style guide on this order:
        Types and type aliases (typedef, using, enum, nested structs and classes, and friend types)
        Static constants
        Factory functions
        Constructors and assignment operators
        Destructor
        All other functions (static and non-static member functions, and friend functions)
        Data members (static and non-static)
*/

#include <iostream>
#include <string>
#include <string_view>

class Employee // members are private by default
{
    std::string m_name{};
    char m_firstInitial{};

public:
    void setName(std::string_view name)
    {
        m_name = name;
        m_firstInitial = name.front(); // use std::string::front() to get first letter of `name`
    }

    void print() const
    {
        std::cout << "Employee " << m_name << " has first initial " << m_firstInitial << '\n';
    }
};

int main()
{
    Employee e{};
    e.setName("John");
    e.print();

    e.setName("Mark");
    e.print();

    return 0;
}