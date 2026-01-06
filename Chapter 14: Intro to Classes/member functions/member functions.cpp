/*
Member Functions
    Functions that belong to a class type are known as member functions, as opposed to non-member or free functions.
    Member functions must be declared inside the class type definition, but can be defined inside or out.
        They are implicitly inline, which avoids ODR violations.
    
    We access them much like accessing other members: the member selection operator (.).
    The object that the member function is called on is implicitly passed to this function.
        This object can be known as an implicit object.
    
    When a member function accesses another member of the class, it does so without any prefix or member selection operator if it is using the implicit object.
    If we passed in another object, we could access its fields using operator. as if it were a non-member function.

    Member variables and functions can be declared in any order.
    Structs are allowed to have member functions, but should avoid constructors as that would render them as non-aggregate.
    
    If your class type has no data members, prefer using a namespace.   
*/


#include <iostream>
#include <string>

struct Date
{
    int year {};
    int month {};
    int day {};

    void print() // defines a member function named print
    {
        std::cout << year << '/' << month << '/' << day; // year, month, and day belong to the implicit object, and do not need a member selection operator.
    }
};

struct Person
{
    std::string name{};
    int age{};

    void kisses(const Person& person)
    {
        std::cout << name << " kisses " << person.name << '\n';
    }
};

int main()
{
    Date today { 2020, 10, 14 }; // aggregate initialize our struct

    today.day = 16; // member variables accessed using member selection operator (.)
    today.print();  // member functions also accessed using member selection operator (.)

    Person joe{ "Joe", 29 };
    Person kate{ "Kate", 27 };

    joe.kisses(kate);

    return 0;
}