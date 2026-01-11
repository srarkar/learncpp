/*
Class Templates w/ Member Functions
    We can combine the concepts of function templates and class templates when creating class types with member functions.

    Type template parameters defined as part of a class template parameter declaration can be used both as the type of data members and as the type of member function parameters.
    Deduction guides are not needed for CTAD to work with non-aggregate classes. A matching constructor provides the compiler with the information it needs to deduce the template parameters from the initializers.

    When we define a member function outside of the class, we need to qualify the member function name with the fully templated name of the class template.
    Within the scope of a class, the unqualified name is known as an injected class name. Within a class template, the injected class name serves as shorthand for the full templated name.
        This means it can also be used for parameters, as it is not an application of CTAD.
    
    If the template is defined outside the class, it should generally be right below it (within the same file). It should also follow the class into header files.

*/

#include <ios>       // for std::boolalpha
#include <iostream>

template <typename T>
class Pair
{
private:
    T m_first{};
    T m_second{};

public:
    // When we define a member function inside the class definition,
    // the template parameter declaration belonging to the class applies
    Pair(const T& first, const T& second)
        : m_first{ first }
        , m_second{ second }
    {
    }

    bool isEqual(const Pair<T>& pair);
};

// When we define a member function outside the class definition,
// we need to resupply a template parameter declaration
template <typename T>
bool Pair<T>::isEqual(const Pair<T>& pair)
{
    return m_first == pair.m_first && m_second == pair.m_second;
}

int main()
{
    Pair p1{ 5, 6 }; // uses CTAD to infer type Pair<int>
    std::cout << std::boolalpha << "isEqual(5, 6): " << p1.isEqual( Pair{5, 6} ) << '\n';
    std::cout << std::boolalpha << "isEqual(5, 7): " << p1.isEqual( Pair{5, 7} ) << '\n';

    return 0;
}