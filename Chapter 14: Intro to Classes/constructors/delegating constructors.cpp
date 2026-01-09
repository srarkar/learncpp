/*
Delegating Constructors
    When we have multiple functions that have common code between them, we usually make a function so that each can simply call on it rather than being repetitive.
    The same occurs with constructurs -- we often have tons of repetition between multiple constructors belonging to the same class.

    While constructors can call on other member functions, constructors should not be called directly from the body of another function.
        Doing so will either result in a compilation error, or will direct-initialize a temporary object.

    Constructors are allowed to delegate to another constructor of the same class type in a process known as constructor chaining. 
    This is done by calling on the constructor within the member initializer list.
        A constructor that delegates to another constructor is not allowed to do any member initialization itself. 
        Meaning, a constructors can delegate or initialize, but not both.
        Note that if a constructor call another, which then calls the first constructor, it will result in an infinite loop and a crash.
            This can be avoided by ensuring all constructors eventually resolve to a non-delegating constructor.


*/

#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    std::string m_name { "???" };
    int m_id { 0 };

public:
    Employee(std::string_view name)
        : Employee{ name, 0 } // delegate initialization to Employee(std::string_view, int) constructor
    {
    }

    Employee(std::string_view name, int id)
        : m_name{ name }, m_id { id } // actually initializes the members
    {
        std::cout << "Employee " << m_name << " created\n";
    }

};

int main()
{
    Employee e1{ "James" };
    Employee e2{ "Dave", 42 };
}