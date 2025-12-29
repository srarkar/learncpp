/*
Arithmetic Conversions
    One or more of an operator's operands may have their type converted in order for the operation to be successful.
    This is done under a set of rules called the usual arithmetic conversions, and the matching type they produce is called the common type of the operands.

    The following operators require their operands to be of the same type:
        The binary arithmetic operators: +, -, *, /, %
        The binary relational operators: <, >, <=, >=, ==, !=
        The binary bitwise arithmetic operators: &, ^, |
        The conditional operator ?: (excluding the condition, which is expected to be of type bool)
    
    The compiler "ranks" types in order to determine the common type.
    The ranking is as follows:
        long double (highest rank)
        double
        float
        long long
        long
        int (lowest rank)
    
    The rules are applied as such:
        Step 1:
            If one operand is an integral type and the other a floating point type, the integral operand is converted to the type of the floating point operand (no integral promotion takes place).
            Otherwise, any integral operands are numerically promoted (see 10.2 -- Floating-point and integral promotion).
        Step 2:
            After promotion, if one operand is signed and the other unsigned, special rules apply
                If the rank of the unsigned operand is greater than or equal to the rank of the signed operand, the signed operand is converted to the type of the unsigned operand.
                If the type of the signed operand can represent all the values of the type of the unsigned operand, the type of the unsigned operand is converted to the type of the signed operand.
                Otherwise both operands are converted to the corresponding unsigned type of the signed operand.
            Otherwise, the operand with lower rank is converted to the type of the operand with higher rank.
    
    The typeid() function can be used to determine the type of an expression.
    Also, std::common_type(type1, type2) will return the common type between the provided types.
        
    
*/

#include <iostream>
#include <typeinfo> // for typeid()

int main()
{
    int i{ 2 };
    std::cout << typeid(i).name() << '\n'; // show us the name of the type for i

    double d{ 3.5 };
    std::cout << typeid(d).name() << '\n'; // show us the name of the type for d

    std::cout << typeid(i + d).name() << ' ' << i + d << '\n'; // show us the type of i + d

    return 0;
}