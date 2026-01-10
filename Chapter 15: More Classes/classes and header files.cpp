/*
Header Files
    While keeping member function definitions inside a class definition is reasonable for small classes, it becomes unreasonable as the class grows.
    Thus, C++ allows functions to be declared within a class definition, but be implemented/defined outside of it.
        An important detail when moving a function definition outside a class is that the definition must be prefixed by the class name and the scope resolution operator so the compiler knows that it is a member function.
        Definitions inside the class definition are inline, which avoids ODR violations.

    Since we often want to be able to use a class across multiple files, class definitions can be placed in header files and #included in any other files that need it.
        Note that this is a full definition and not a forward declaration, since the compiler needs to know how the members are declared and the size of objects of that type.
        Types are exempt from ODR, and header guards (e.g. #pragma once) prevent them from being defined multiple times in the same translation unit.
    
    Most often, classes are defined in header files of the same name as the class, and any member functions defined outside of the class are put in a .cpp file of the same name as the class.
        Trivial functions such as simple getters and empty-body constructors can be kept in the class definition.
        Put any default arguments for member functions inside the class definition.
*/

#include <iostream>

class Date
{
private:
    int m_year{};
    int m_month{};
    int m_day{};

public:
    Date(int year, int month, int day); // constructor declaration

    void print() const; // print function declaration

    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const  { return m_day; }
};

Date::Date(int year, int month, int day) // constructor definition
    : m_year{ year }
    , m_month{ month }
    , m_day{ day }
{
}

void Date::print() const // print function definition
{
    std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n";
};

int main()
{
    const Date d{ 2015, 10, 14 };
    d.print();

    return 0;
}