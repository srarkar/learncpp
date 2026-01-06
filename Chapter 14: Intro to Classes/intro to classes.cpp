/*
Intro to Classes
    One of the difficulties of structs, an example of an aggregate, is the difficulty with enforcing class invariants.
    Class invariants are conditions that must be true throughout the lifetime of an object for the object to remain valid.
    If a class invariant is not met, the associated object is invalid and can cause undefined or unexpected behavior.

    For example, a simple fraction struct with numerator and denominator members cannot enforce that the denominator should not be equal to 0.
    There could also be issues if multiple fields are correlated, such as a name member and a first initial member.
        We should not have to rely on the user of an object to enforce its invariants.

    Just like structs, a class is a program-defined compound type that can have many member variables with different types.
    They are defined much like structs, replacing the struct keyword with the class keyword.
    
*/


struct Fraction
{
    int numerator { 0 };
    int denominator { 1 }; // class invariant: should never be 0. 
};

class Employee
{
    int m_id {};
    int m_age {};
    double m_wage {};
};

#include <iostream>

class Date       // we changed struct to class
{
public:          // and added this line, which is called an access specifier
    int m_day{}; // and added "m_" prefixes to each of the member names
    int m_month{};
    int m_year{};
};

void printDate(const Date& date)
{
    std::cout << date.m_day << '/' << date.m_month << '/' << date.m_year;
}

int main()
{
    Date date{ 4, 10, 21 };
    printDate(date);

    return 0;
}