/*
Type conversion
    We have the ability to convert values of one fundamental data type to another fundamental type in a process known as type conversion.
    When the compiler does it automatically without the programmer explicitly asking, it is implicit type conversion. 

    However, it can cause warnings/errors, especially if there is a loss of information. 

    Note that type conversion produces a new value / temporary object, rather than modifying the existing value or object being supplied. Rather, it takes the original value's data as input.
        A few advanced type conversions (const_cast and reinterpret_cast) involve re-interpreting the existing value rather than creating a temporary object.

    Explicit type conversion allows the programmer to explicity tell the compiler to convert a value from one type to another, without generating warnings (even with a loss of information).
    In most cases, this involves the usage of the static_cast operator. Its syntax is: static_cast<new_type>(expression).
        The argument being evaluated as an expression means that if we pass in a variable, its value is what is converted to the new type.

    Converting an unsigned integral value to a signed integral value will result in implementation-defined behavior prior to C++20 if the value being converted can not be represented in the signed type.
*/

#include <iostream>

void print(double x) // print takes a double parameter
{
	std::cout << x << '\n'; // prints 5, since the .0 is excluded by std::cout
}

void print2(int x) // int param
{
    std::cout << x << '\n';
}

int main()
{
	print(5); // what happens when we pass an int value? Implicit type conversion to a double (5.0)

    //print2(5.5); // passing in a double. may cause compiler warnings, since there is a loss of data 

    print2(static_cast<int>(5.5)); // explicit cast to an int -> print 5

    

	return 0;
}