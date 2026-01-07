/*
Access Specifiers: Public and Private
    Each member of a class type has a property called its access specifiers, which controls who can access the member.
        The three access specifiers are public, private, and protected.
    
    Public members have no restrictions on who can access them -- anyone in scope can access a public member.
        Public members can be accessed by other members of the same class, as well as "the public"
            "The public" refers to code that exists outside the members of the class type.
            This includes non-member functions, and members of other class types.
    By default, members of a struct are public.
    In fact, we should avoid altering the access specifiers of struct members since making them private would mean they are no longer aggregates.

    Members with private access control are known as private members. They can only be accessed by members of the same class.
        Members of a class are private by default. Usually classes will have private or protected member variables, except for public member functions.
        It is a common convention to name private data members starting with an “m_” prefix
    A class with private members is no longer an aggregate, and therefore can no longer use aggregate initialization.

    This is the only technical difference between a struct and class. A struct has a default access specifier of public, and class private.
        One minor difference is that structs inherit from other class types publicly and classes inherit privately

    As a rule of thumb, use a struct when all of the following are true:
        You have a simple collection of data that doesn’t benefit from restricting access.
        Aggregate initialization is sufficient.
        You have no class invariants, setup needs, or cleanup needs.


    
*/
#include <iostream>

// struct Date
// {
//     // struct members are public by default, can be accessed by anyone
//     int year {};       // public by default
//     int month {};      // public by default
//     int day {};        // public by default

//     void print() const // public by default
//     {
//         // public members can be accessed in member functions of the class type
//         std::cout << year << '/' << month << '/' << day;
//     }
// };


class Date
{
// Any members defined here would default to private

public: // here's our public access specifier

    void print() const // public due to above public: specifier
    {
        // members can access other private members
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }

private: // here's our private access specifier

    int m_year { 2020 };  // private due to above private: specifier
    int m_month { 14 }; // private due to above private: specifier
    int m_day { 10 };   // private due to above private: specifier
};


int main() // main is part of the public
{
    //Date today { 2020, 10, 14 }; // compile error: can no longer use aggregate initialization

    // private members can not be accessed by the public
    //today.m_day = 16; // compile error: the m_day member is private
    //today.print();    // compile error: the print() member function is private

    return 0;
}