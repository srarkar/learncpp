/*
User-Defined Types
    User-defined types, also known as program-defined types, are types created for use in a program that aren't provided by C++.
        There can be a small caveat here, where user-defined includes standard library and implementation, while program-defined does not.
    They come in two categories:
        - Enumerated Types (unscoped and scoped)
        - Class types (classes, structs, unions)
    Program-defined types must be defined and given a name in order to be used, which is known as a type definition.
        Other compound types require neither.
    
    These types are usually defined with a capital letter and no suffix.
    A program-defined type used in only one code file should be defined in that code file as close to the first point of use as possible.
    A program-defined type used in multiple code files should be defined in a header file with the same name as the program-defined type.

    Since we have to propagate the full definition of the type, types are partially exempt from the ODR.
*/

// Define a program-defined type named Fraction so the compiler understands what a Fraction is
// (we'll explain what a struct is and how to use them later in this chapter)
// This only defines what a Fraction type looks like, it doesn't create one
struct Fraction
{
	int numerator {};
	int denominator {};
};

// Now we can make use of our Fraction type
int main()
{
	Fraction f { 3, 4 }; // this actually instantiates a Fraction object named f

	return 0;
}