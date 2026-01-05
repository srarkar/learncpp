/*
Passing Structs
    If we need to pass a struct's members to a function, we can conveniently pass the struct itself.
    They are generally passed by (const) reference to avoid making a copy of the struct.

    Temporary structs can also be passed in. The type specifier is not necessary, but recommended for clarity.
    Evaluation of a temporary object is an rvalue expression, meaning when a temporary object is used as a function argument, it will only bind to parameters that accept rvalues.

Returning Structs
    Structs defined inside functions are usually returned by value, so as not to return a dangling reference.

*/

#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

void printEmployee(const Employee& employee) // note pass by reference here
{
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

struct Point3d
{
    double x { 0.0 };
    double y { 0.0 };
    double z { 0.0 };
};


Point3d getZeroPoint()
{
    return Point3d { 0.0, 0.0, 0.0 }; // return an unnamed Point3d in a single line. the "Point3d" in the return statement can be omitted since the return type is specified.
}


int main()
{
    Employee joe { 14, 32, 24.15 };
    Employee frank { 15, 28, 18.27 };

    // Print Joe's information
    printEmployee(joe);

    std::cout << '\n';

    // Print Frank's information
    printEmployee(frank);

    
    printEmployee(Employee { 14, 32, 24.15 }); // construct a temporary Employee to pass to function (type explicitly specified) (preferred)

    std::cout << '\n';

    // Print Frank's information
    printEmployee({ 15, 28, 18.27 }); // construct a temporary Employee to pass to function (type deduced from parameter)

    return 0;
}