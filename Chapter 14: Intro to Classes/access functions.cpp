/*
Access Functions
    Access functions are public member functions that provide a simple way to view or alter (get or set) the value of a private member variable.
        Getters, or accessors, return the value of a private member variable. These are usually made const.
            Since they are meant to provide read-only access to data, they should return by value or by const lvalue reference
        Setters, or mutators, set the value of a private member variable.
    The point of all this boils down to encapsulation.

    Some guidelines when writing classes:
        If your class has no invariants and requires a lot of access functions, consider using a struct (whose data members are public) and providing direct access to members instead.
        Prefer implementing behaviors or actions instead of access functions. For example, instead of a setAlive(bool) setter, implement a kill() and a revive() function.
        Only provide access functions in cases where the public would reasonably need to get or set the value of an individual member.
*/

#include <iostream>

class Date
{
private:
    int m_year { 2020 };
    int m_month { 10 };
    int m_day { 14 };

public:
    void print()
    {
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }

    int getYear() const { return m_year; }        // getter for year
    void setYear(int year) { m_year = year; }     // setter for year

    int getMonth() const  { return m_month; }     // getter for month
    void setMonth(int month) { m_month = month; } // setter for month

    int getDay() const { return m_day; }          // getter for day
    void setDay(int day) { m_day = day; }         // setter for day
};

int main()
{
    Date d{};
    d.setYear(2021);
    std::cout << "The year is: " << d.getYear() << '\n';

    return 0;
}