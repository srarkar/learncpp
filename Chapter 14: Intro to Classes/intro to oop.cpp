/*
Intro to Object-Oriented Programming
    Procedural programming is the process of writing functions that implement program logic.
    The functions are separate entities from the data they operate on, and the programmer controls how they are combined to produce desired results.
        This separation of properties and behaviors means procedural programming poorly represents reality.
        
    Object-oriented programming involves creating program-defined types that contain properties and a set of defined behaviors.
    We clearly define how objects interact with the programmer and other objects.

    OOP also uses concepts that encourage code to build on itself modularily, and with minimal redundancy.
*/

#include <iostream>
#include <string_view>

struct Cat
{
    std::string_view name{ "cat" };
    int numLegs{ 4 };
};

struct Dog
{
    std::string_view name{ "dog" };
    int numLegs{ 4 };
};

struct Chicken
{
    std::string_view name{ "chicken" };
    int numLegs{ 2 };
};

int main()
{
    constexpr Cat animal;
    std::cout << "a " << animal.name << " has " << animal.numLegs << " legs\n";

    return 0;
}