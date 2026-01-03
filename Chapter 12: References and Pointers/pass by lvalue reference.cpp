/*
Pass by reference
    Passing by value involves making a copy of the argument for serving as a function parameter.
    This copy is later destroyed at the end of the function. Fundamental types are cheap to copy, but the same is not always true for compound data types.

    To avoid making an expensive copy of something like a class data type, we can instead pass by reference.
    This involves the parameter being declared as a (possibly const) reference type. When the function is called, each parameter becomes bound to the appropriate argument.
    The reference serves to act as an alias for the argument without any copy being made.

    An important distinction is that a value parameter is a separate object from the argument.
    This means that changes made to the reference parameter will reflect in the argument.
        In turn, pass by reference only works with arguments that are modifiable lvalues.
        This limits the usefulness of pass by reference to non-const, as it means we can not pass const variables or literals

Pass by const lvalue reference
    Making a reference parameter const allows it to bind to modifiable lvalues, non-modifiable lvalues, and rvalues.
    This guarantees the function will not modify the value being referenced, but still allows the programmer to avoid the cost of making a copy via pass by value.
    
    We would be unable to pass literals or rvalues by reference otherwise.
    However, if we pass by reference with a different type than expected, it may cause an expensive conversion of the original object.
        Take care to use the correct type when passing by reference to avoid this.
    
Other
    A function with multiple parameters can have some be pass by reference and others pass by value.

    When deciding whether to pass by value vs pass by reference:
        Fundamental types and enumerated types are cheap to copy, so they are typically passed by value.
        Class types can be expensive to copy (sometimes significantly so), so they are typically passed by const reference.

    More details:
        The following are often passed by value (because it is more efficient):
            Enumerated types (unscoped and scoped enumerations).
            Views and spans (e.g. std::string_view, std::span).
            Types that mimic references or (non-owning) pointers (e.g. iterators, std::reference_wrapper).
            Cheap-to-copy class types that have value semantics (e.g. std::pair with elements of fundamental types, std::optional, std::expected).
            
        Pass by reference should be used for the following:
            Arguments that need to be modified by the function.
            Types that aren’t copyable (such as std::ostream).
            Types where copying has ownership implications that we want to avoid (e.g. std::unique_ptr, std::shared_ptr).
            Types that have virtual functions or are likely to be inherited from (due to object slicing concerns, covered in lesson 25.9 -- Object slicing).
        When not sure, lean towards pass by const reference.
*/ 

/*
Cost of Pass-by-Value vs Pass-by-Reference
    Cost of initializing function parameter

        Pass-by-value:
            - Initialization means making a copy, in this case
            - This is generally proportional to the size of the object and additional costs, as some class types need to do some kind of setup when an object is instantiated.
        Pass-by-reference:
            - Binding a reference to an object is always quite fast -- about the same as copying a fundamental data type

    Cost of using the function parameter
        The compiler may be able to place a reference or copy into a CPU register (as opposed to RAM) for optimization

        For a value parameter, the program can easily access the value directly from the register or RAM.
        A reference parameter has an extra step to find the object being referenced in RAM, even if the reference is in a register.
        Therefore, each use of a value parameter is a single CPU register or RAM access, whereas each use of a reference parameter is a single CPU register or RAM access plus a second RAM access.

    Ease of Optimization
        The compiler can sometimes optimize code that uses pass-by-value more effectively than those using pass-by-reference.

        Due to the possibility of aliasing, where two or more pointers/references reference the same object, compilers can less freely optimize references.
        On the other hand, since the value parameter is a copy, there is no chance of aliasing occuring.

    Conclusion:
        For objects that are cheap to copy, the cost of copying is similar to the cost of binding, but accessing the objects is faster and the compiler is likely to be able to optimize better.
        For objects that are expensive to copy, the cost of the copy dominates other performance considerations.

        It is difficult to pinpoint what it means to be "cheap to copy" but a decent rule of thumb is that such an object takes up 2 or fewer words of memory, and incurs no setup costs. 
            word size can be approximated by the size of a memory address (i.e. sizeof(void *))
        It’s best to assume that most standard library classes have setup costs, unless you know otherwise that they don’t.
*/  

/*
string_view vs const std::string&
    In most cases, std::string_view is the better choice over const std::string&, as it can handle a wider range of argument types efficiently. 
    A std::string_view parameter also allows the caller to pass in a substring without having to copy that substring into its own string first.

    With a std::string_view value parameter:
        If we pass in a std::string argument, the compiler will convert the std::string to a std::string_view, which is inexpensive, so this is fine.
        If we pass in a std::string_view argument, the compiler will copy the argument into the parameter, which is inexpensive, so this is fine.
        If we pass in a C-style string or string literal, the compiler will convert these to a std::string_view, which is inexpensive, so this is fine.
        As you can see, std::string_view handles all three cases inexpensively.

    With a const std::string& reference parameter:
        If we pass in a std::string argument, the parameter will reference bind to the argument, which is inexpensive, so this is fine.
        If we pass in a std::string_view argument, the compiler will refuse to do an implicit conversion, and produce a compilation error. We can use static_cast to do an explicit conversion (to std::string), but this conversion is expensive (since std::string will make a copy of the string being viewed). Once the conversion is done, the parameter will reference bind to the result, which is inexpensive. But we’ve made an expensive copy to do the conversion, so this isn’t great.
        If we pass in a C-style string or string literal, the compiler will implicitly convert this to a std::string, which is expensive. So this isn’t great either.
        Thus, a const std::string& parameter only handles std::string arguments inexpensively.




*/

#include <iostream>
#include <string>

void printValue(std::string& y) // type changed to std::string&
{
    std::cout << y << '\n';
} // y is destroyed here

int main()
{
    std::string x { "Hello, world!" };

    printValue(x); // x is now passed by reference into reference parameter y (inexpensive). making a copy of an std::string would be far more costly.

    return 0;
}
