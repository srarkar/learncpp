/*
Member Selection w/ Pointers and References
    With references, we can use the member selection operator (.) normally since the reference is meant to act as the object itself.

    With pointers, we need to de-reference the pointer first, then access its members.
    Since the de-reference would normally happen after the member selection, we have to paranthesize the de-reference.
        This is a bit ugly.
        The arrow operator (->) compacts this into a single symbol, allowing easy access to a pointer's struct members.

*/

#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

void printEmployee(const Employee& e)
{
    // Use member selection operator (.) to select member from reference to struct
    std::cout << "Id: " << e.id << '\n';
    std::cout << "Age: " << e.age << '\n';
    std::cout << "Wage: " << e.wage << '\n';
}

int main()
{
    Employee joe{ 1, 34, 65000.0 };

    ++joe.age;
    joe.wage = 68000.0;

    printEmployee(joe);

    Employee* ptr{ &joe };
    std::cout << ptr->id << '\n'; // Better: use -> to select member from pointer to object

    return 0;
}