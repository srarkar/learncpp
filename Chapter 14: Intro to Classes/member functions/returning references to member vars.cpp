/*
Return by Reference for Data Members
    Member functions can return by reference under the same limitations as non-member functions: the object being returning must not be destroyed after the return.
    Special focus needs to given when dealing with returning data members by reference.

    Returning by value is possible but potentially expensive. 
    Member functions are also able to return by (const) lvalue reference. This is generally safe since functions are called on an object, and that implicit object has to be in scope of the caller.
    
    In general, the return type of a member function returning by reference should match the type of the data member being returned.
        This avoids unecessary conversions.
        Using auto for getters for the compiler to deduce the return type  can help avoid conversions.
    
    We need to be careful if our implicit object is an rvalue, since the object is only valid within the full expression it is created in.
    When the object is destroyed afterwards, any references to it will be left dangling.
        Therefore, a reference to a member of an rvalue object can only be safely used within the full expression where the rvalue object is created.

    Key Points:
        Prefer to use the return value of a member function that returns by reference immediately (illustrated in case 1). Since this works with both lvalue and rvalue objects, if you always do this, you will avoid trouble.
        Do not “save” a returned reference to use later (illustrated in case 2), unless you are sure the implicit object is an lvalue. If you do this with an rvalue implicit object, undefined behavior will result when you use the now-dangling reference.
        If you do need to persist a returned reference for use later and aren’t sure that the implicit object is an lvalue, using the returned reference as the initializer for a non-reference local variable, which will make a copy of the member being referenced into the local variable (illustrated in case 3).


    Do not return non-const references to private data members from a member function, as it provides direct access to that member.
    A const member function is not allowed to return a non-const reference to members, as this could lead to modification of the object.

*/

#include <iostream>
#include <string>

class Employee
{
	std::string m_name{};

public:
	void setName(std::string_view name) { m_name = name; }
	const std::string& getName() const { return m_name; } //  getter returns by const reference
};

int main()
{
	Employee joe{}; // joe exists until end of function
	joe.setName("Joe");

	std::cout << joe.getName(); // returns joe.m_name by reference

    // Case 1: okay: use returned reference to member of rvalue class object in same expression
	//std::cout << createEmployee("Frank").getName();

	// Case 2: bad: save returned reference to member of rvalue class object for use later
	// const std::string& ref { createEmployee("Garbo").getName() }; // reference becomes dangling when return value of createEmployee() is destroyed
	// std::cout << ref; // undefined behavior

	// // Case 3: okay: copy referenced value to local variable for use later
	// std::string val { createEmployee("Hans").getName() }; // makes copy of referenced member
	// std::cout << val; // okay: val is independent of referenced member

	return 0;
}