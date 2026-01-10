/*
"this" pointer
    When a member function is called, C++ uses a hidden pointer called "this" to access the implicit object. 
        The "this" pointer is a const pointer holding the address of the implicit object.

    Simply accessing the field is less verbose that doing "this->field".


    Function calls are modified when compiled to include an additional parameter for the implicit object.

    Referring to the example below:
        When we call simple.setID(2), the compiler actually calls Simple::setID(&simple, 2), and simple is passed by address to the function.
        The function has a hidden parameter named this which receives the address of simple.
        Member variables inside setID() are prefixed with this->, which points to simple. So when the compiler evaluates this->m_id, it’s actually resolving to simple.m_id.
    All non-static member functions have a this const pointer that holds the address of the implicit object.

    There are some cases where it may make sense to use it however, such as for disambiguating an argument from the implicit object's member variable.
    
    There is another idea where "this" can see usage.

Member Function Chaining
    A member function can be made to return its implicit object. This is useful for function chaining / method chainings where we call multiple functions on the same object in a single line.
    When returning, we dereference this to return the implicit object itself, which can be then passed into subsequent member functions.

    We can also create a function to return an object to its default state, often called reset().

    Funnily enough, "this" being a pointer is because it was created when C++ didn't have references. If this was redone, "this" would almost certainly be a reference instead (as it is in Java and C#).
*/

#include <iostream>

class Simple
{
private:
    int m_id{};

public:
    Simple(int id)
        : m_id{ id }
    {
    }

    int getID() const { return m_id; }
    void setID(int id) { m_id = id; }

    void print() const { std::cout << this->m_id; } // use `this` pointer to access the implicit object and operator-> to select member m_id
};

class Calc
{
private:
    int m_value{};

public:
    Calc& add(int value) { m_value += value; return *this; } // note the return
    Calc& sub(int value) { m_value -= value; return *this; }
    Calc& mult(int value) { m_value *= value; return *this; }

    void reset() { *this = {}; }

    int getValue() const { return m_value; }
};

int main()
{
    Simple simple{ 1 };
    simple.setID(2);

    simple.print();

    Calc calc{};
    calc.add(5).sub(3).mult(4); // method chaining

    std::cout << calc.getValue() << '\n';

    calc.reset();

    std::cout << calc.getValue() << '\n'; // prints 0
    return 0;
}