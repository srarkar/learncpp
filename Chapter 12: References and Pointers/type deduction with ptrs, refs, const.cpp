/*
Type Deduction (Pointers, References, Const)

References
    By default, type deduction drops the const if the initializer is const.
    Similarly, type deduction will drop references. Naturally, it can be reapplied manually.
        For example, initializing with an std::string& will yield an std::string when using the auto type.

    A top-level const is a const qualifier that applies to itself, while a low level const is one that applies to the object being referenced or pointed to.

    If the initializer is a reference to const, the reference is dropped first (and then reapplied if applicable), and then any top-level const is dropped from the result.
        In other words, dropping a reference may change a low-level const to a top-level const: const std::string& is a low-level const, but dropping the reference yields const std::string, which is a top-level const.
    It is best to reapply the const even if it is done implicitly, for the sake of clarity.

    Constexpr is not part of an expression’s type, so it is not deduced by auto.
    
    auto& can be used for deducing references.

Pointers
    Unlike references, type deduction does not drop pointers. References are really treated as the object itself, while pointers are semantically different by acting as the location of the object.
    We can use auto* instead of auto to make it clear that the deduced type is a pointer. Note that if using auto*, the expression must evaluate to a pointer initializer.

    If you want a const pointer, pointer to const, or const pointer to const, reapply the const qualifier(s) even when it’s not strictly necessary, as it makes your intent clear and helps prevent mistakes.   
*/

#include <string>

std::string& getRef(); // some function that returns a reference

std::string* getPtr(); // some function that returns a pointer

int main()
{
    auto ref1 { getRef() };  // std::string (reference dropped)
    auto& ref2 { getRef() }; // std::string& (reference dropped, reference reapplied)

    const int x{};    // this const applies to x, so it is top-level
    int* const ptr{nullptr}; // this const applies to ptr, so it is top-level
    // references don't have a top-level const syntax, as they are implicitly top-level const

    const int& ref{}; // this const applies to the object being referenced, so it is low-level
    const int* ptr{}; // this const applies to the object being pointed to, so it is low-level

    const int* const ptr{}; // the left const is low-level, the right const is top-level

    auto ptr1{ getPtr() };  // std::string*
    auto* ptr2{ getPtr() }; // std::string*

    const auto ptr1{ getPtr() };  // std::string* const
    auto const ptr2 { getPtr() }; // std::string* const

    // A const on the left means “make the deduced pointer a pointer to const”, 
    //  whereas a const on the right means “make the deduced pointer type a const pointer”. 
    const auto* ptr3{ getPtr() }; // const std::string*
    auto* const ptr4{ getPtr() }; // std::string* const

    std::string s{};
    const std::string* const ptr { &s };

    auto ptr1{ ptr };  // const std::string*
    auto* ptr2{ ptr }; // const std::string*

    auto const ptr3{ ptr };  // const std::string* const
    const auto ptr4{ ptr };  // const std::string* const

    auto* const ptr5{ ptr }; // const std::string* const
    const auto* ptr6{ ptr }; // const std::string*

    const auto const ptr7{ ptr };  // error: const qualifer can not be applied twice
    const auto* const ptr8{ ptr }; // const std::string* const

    return 0;
}