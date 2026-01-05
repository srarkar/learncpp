/*
Scoped Enumerations
    Unscoped enums are not type safe, and can allow weird things such as comparing enumerators that belong to different enumerations but resolve to the same integer.
    The issue of easily polluting the global namespace is also a drawback to unscoped enums.

    This led to the creation of scoped enums, also known as the enum class. 
    The difference is that scoped enumerators do not resolve to integers, and enumerators are place into the scope region of the enumeration rather than sharing it with the enumeration.
        The enumeration effectively acts as a namespace for the enumerators, creating their own region of scope.
    The keyword to use is "enum class" -- the rest of the syntax remains the same.

    Generally, prefer scoped enums even though it may demand many static_casts. A way to alleviate this is to overload the + operator.

    The "using enum" statement imports all enumerators from an enum into the current scope, allowing them to be used without the class name.
        This is mainly useful if we needed to use the class name many times otherwise, such as in a switch statement.
*/






#define SUCCESS 1
#define FAILURE 0

#include <iostream>
#include <type_traits>


/// Quiz
enum class Animal {
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

std::string_view getAnimalName(Animal a) {
    switch(a) {
        case Animal::pig:
            return "pig";

        case Animal::chicken:
            return "chicken";

        case Animal::goat:
            return "goat";

        case Animal::cat:
            return "cat";

        case Animal::dog:
            return "dog";
        
        case Animal::duck:
            return "duck";
        
        default:
            return "";
    }
}

void printNumberOfLegs(Animal a) {
    std::string_view name = getAnimalName(a);

    std::cout << "A " << name << " has ";

    switch(a) {
        case Animal::pig:
        case Animal::goat:
        case Animal::cat:
        case Animal::dog:
            std::cout << 4;
            break;

        case Animal::chicken:
        case Animal::duck:
            std::cout << 2;
            break;
        
        default:
            std::cout << "???" << '\n';
            break;
    }

    std::cout << " legs." << '\n';
}
/// End of Quiz

enum class Animals
{
    chicken, // 0
    dog, // 1
    cat, // 2
    elephant, // 3
    duck, // 4
    snake, // 5

    maxAnimals,
};

// Overload the unary + operator to convert an enum to the underlying type
// adapted from https://stackoverflow.com/a/42198760, thanks to Pixelchemist for the idea
// In C++23, you can #include <utility> and return std::to_underlying(a) instead
template <typename T>
constexpr auto operator+(T a) noexcept
{
    return static_cast<std::underlying_type_t<T>>(a);
}

int main()
{
    // Quiz testing
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);
    //


    enum class Color // "enum class" defines this as a scoped enumeration rather than an unscoped enumeration
    {
        red, // red is considered part of Color's scope region
        blue,
    };

    enum class Fruit
    {
        banana, // banana is considered part of Fruit's scope region
        apple,
    };

    Color color { Color::red }; // note: red is not directly accessible, we have to use Color::red
    Fruit fruit { Fruit::banana }; // note: banana is not directly accessible, we have to use Fruit::banana

    // if (color == fruit) // compile error: the compiler doesn't know how to compare different types Color and Fruit
    //     std::cout << "color and fruit are equal\n";
    
    std::cout << +Animals::elephant << '\n'; // convert Animals::elephant to an integer using unary operator+

    return 0;
}