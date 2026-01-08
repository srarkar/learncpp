/*
Default Constructors and Arguments
    A default constructor accepts no arguments.
    Prefer value initialization over default initialization for all class types, as it can be difficult to tell if it is an aggregate or non-aggregate.
    A class should not have more than one default constructor to prevent ambiguity (and therefore, compiler errors)


    If a non-aggregate class type object has no user-declared constructors, the compiler will generate a public default constructor (so that the class can be value or default initialized).
    This constructor is called an implicit default constructor/

    The implicit default constructor is equivalent to a constructor that has no parameters, no member initializer list, and no statements in the body of the constructor. 
    An explicit default constructor can be generated with "= default";
        Prefer an explicitly defaulted default constructor over a default constructor with an empty body. 
    When a class has a default constructor not provided by the user (implicit or explicit), then a created object will be zero-initialized before being default initialized.
    A class should only provide a default constructor when it makes sense for objects of a class type to be created using all default values.

    As with all functions, the rightmost parameters of constructors can have default arguments. 

    Constructors can also be overloaded, meaning we can create an object differently based on how the initial values provided.

*/

#include <iostream>

class Foo
{
public:
    Foo() // default constructor
    {
        std::cout << "Foo default constructed\n";
    }
};


class Foo2
{
private:
    int m_x { };
    int m_y { };

public:
    Foo2(int x=0, int y=0) // has default arguments
        : m_x { x }
        , m_y { y }
    {
        std::cout << "Foo2(" << m_x << ", " << m_y << ") constructed\n";
    }
};


class User
{
private:
    int m_a; // note: no default initialization value
    int m_b {};

public:
    User() {} // user-defined empty constructor

    int a() const { return m_a; }
    int b() const { return m_b; }
};

class Default
{
private:
    int m_a; // note: no default initialization value
    int m_b {};

public:
    Default() = default; // explicitly defaulted default constructor

    int a() const { return m_a; }
    int b() const { return m_b; }
};

class Implicit
{
private:
    int m_a; // note: no default initialization value
    int m_b {};

public:
    // implicit default constructor

    int a() const { return m_a; }
    int b() const { return m_b; }
};

int main()
{
    Foo foo{}; // No initialization values, calls Foo's default constructor

    Foo2 foo1{};     // calls Foo(int, int) constructor using default arguments
    Foo2 foo2{6, 7}; // calls Foo(int, int) constructor

    User user{}; // default initialized
    std::cout << user.a() << ' ' << user.b() << '\n';

    Default def{}; // zero initialized, then default initialized
    std::cout << def.a() << ' ' << def.b() << '\n';

    Implicit imp{}; // zero initialized, then default initialized
    std::cout << imp.a() << ' ' << imp.b() << '\n';

    return 0;
}