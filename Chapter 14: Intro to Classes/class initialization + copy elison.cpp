/*
Class Initialization
    All 6 forms of initialization are valid for class type objects.
    For all types of initialization:
        When initializing a class type, the set of constructors for that class are examined, and overload resolution is used to determine the best matching constructor. This may involve implicit conversion of arguments.
        When initializing a non-class type, the implicit conversion rules are used to determine whether an implicit conversion exists.
    
    There are 3 key differences between the initialization forms:
        - List initialization disallows narrowing conversions
        - List initialization prioritizes matching list constructors over other matching constructors
        - Copy initialization only considers non-explicit constructors/conversion function
    Also, in some circumstances, certain forms of initialization are disallowed (e.g. in a constructor member initializer list, we can only use direct forms of initialization, not copy initialization).
*/

/*
Copy Elison
    Copy elison is a compiler optimization where unecessary object copies are removed.
    That is, calls to a copy constructor can be replaced entirely to improve performance.
        When the compiler optimizes away a call to the copy constructor, we say the constructor has been elided.
    This is an exception to the as-if rule, as the compiler can remove calls to the copy constructor even if it does more than just making a copy.
        Meaning, the compiler's optimizations can alter observable behavior, which is why copy constructors should not perform additional tasks outside of copying.
    
    After C++17, copy elison became a situationally mandatory optimization, even if the programmer tells the compiler not to do it.
*/

#include <iostream>

class Foo
{
public:

    // Default constructor
    Foo()
    {
        std::cout << "Foo()\n";
    }

    // Normal constructor
    Foo(int x)
    {
        std::cout << "Foo(int) " << x << '\n';
    }

    // Copy constructor
    Foo(const Foo&)
    {
        std::cout << "Foo(const Foo&)\n";
    }
};

class Something
{
public:
	Something() = default;
	Something(const Something&)
	{
		std::cout << "Copy constructor called\n";
	}
};

Something rvo()
{
	return Something{}; // calls Something() and copy constructor
}

Something nrvo()
{
	Something s{}; // calls Something()
	return s;      // calls copy constructor
}

int main()
{
    // Calls Foo() default constructor
    Foo f1;           // default initialization
    Foo f2{};         // value initialization (preferred)

    // Calls foo(int) normal constructor
    Foo f3 = 3;       // copy initialization (non-explicit constructors only)
    Foo f4(4);        // direct initialization
    Foo f5{ 5 };      // direct list initialization (preferred)
    Foo f6 = { 6 };   // copy list initialization (non-explicit constructors only)

    // Calls foo(const Foo&) copy constructor
    Foo f7 = f3;      // copy initialization
    Foo f8(f3);       // direct initialization
    Foo f9{ f3 };     // direct list initialization (preferred)
    Foo f10 = { f3 }; // copy list initialization

    std::cout << "Initializing s1\n";
	Something s1 { rvo() }; // calls copy constructor

	std::cout << "Initializing s2\n";
	Something s2 { nrvo() }; // calls copy constructor

    return 0;
}