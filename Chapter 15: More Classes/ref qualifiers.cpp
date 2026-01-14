/*
Ref Qualifiers
    When an access function that returns a reference to a data member is called when the implicit object is an value, it can lead to undefined behavior since the reference is left dangling afterwards.
    This is annoying because:
        - returning by value is safe if the implicit object is an rvalue
        - but we create an unecessary and potentially expensive copy when the implicit object is an lvalue, which is more common.
    Conventionally, this is dealt with by simply returning by const reference and avoiding cases where the implicit object is an rvalue. This feels far from ideal.

    What we really want is a way to separate the logic of our function based on the identity of the implicit object (lvalue or rvalue).
    A ref-qualifier allows us to overload a member function based on if it is being called on an lvalue or rvalue implicit object.
    This allows the creation of two versions that cater to each of these possibilities.

    Ref-qualifiying a function is done by adding an & qualifier to match lvalue implicit objects and && to match rvalue implicit objects.
    This allows us to do the performant thing when our implicit object is an lvalue, and the safe thing when our implicit object is an rvalue.

    For a given function, non-ref-qualified overloads and ref-qualified overloads cannot coexist.
    Similar to how a const lvalue reference can bind to an rvalue, if only a const lvalue-qualified function exists, it will accept either lvalue or rvalue implicit objects.

    Some downsides of ref qualifiers:
        - Most C++ developers are not aware of this feature (which can lead to errors or inefficiencies in use).
            - In a similar vein, the standard library typically does not make use of this feature.
        - Adding rvalue overloads to every getters adds clutter
        - Ref qualifiers deal with an edge case that isn't common and should be avoided anyways with good practice.
        - Having an rvalue overload return by value means we have to pay for the cost of a copy (or move) even in cases where we could have used a reference safely
*/
#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
	std::string m_name{};

public:
	Employee(std::string_view name): m_name { name } {}

	const std::string& getName() const &  { return m_name; } //  & qualifier overloads function to match only lvalue implicit objects
	std::string        getName() const && { return m_name; } // && qualifier overloads function to match only rvalue implicit objects. this line can be replaced with "return std::move(m_name);" to be more performant when the implicit object is a non-const temporary.

};

// createEmployee() returns an Employee by value (which means the returned value is an rvalue)
Employee createEmployee(std::string_view name)
{
	Employee e { name };
	return e;
}

int main()
{
	Employee joe { "Joe" };
	std::cout << joe.getName() << '\n'; // Joe is an lvalue, so this calls std::string& getName() & (returns a reference)

	std::cout << createEmployee("Frank").getName() << '\n'; // Frank is an rvalue, so this calls std::string getName() && (makes a copy)

	return 0;
}
