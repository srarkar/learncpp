/*
Testing
    Testing code is a vital portion of software development. 
    Unless some program is completely linear and only designed for one use case, any time a change is made it is important that the program's correctness is verified.
        Such changes can also lead to scope creep, where new, unplanned capabilities are added that grows the scope of the portion of code.
    
    Software testing/validation is the process of ensuring a program works as expected.
    However, even for trivial programs, there are too many combinations of inputs, conditionals, etc. It is unreasonable to test every possible combination of inputs for a given program.

    For one, the best way to test is to test in small parts, combine them, and test again. If a part is thoroughly tested, we can trust that it is not part of a problem, if one arises.
        If we do not test well enough individually, a problem can be anywhere -- we would have to diagnose every part to find a solution.
        This is known as unit testing: verifying small parts (units) of code individually
    
    While temporary tests are fine, it is better to create some dedicated functions that we can call to test our code.
    Rather than verifying results manually, asserts can be used to throw errors if there is a mismatch in expected vs actual results.
    
*/

#include <cassert> // for assert
#include <cstdlib> // for std::abort
#include <iostream>

bool isLowerVowel(char c)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

// Program will halt on any failed test case
int testVowel()
{
#ifdef NDEBUG
    // If NDEBUG is defined, asserts are compiled out.
    // Since this function requires asserts to not be compiled out, we'll terminate the program if this function is called when NDEBUG is defined.
    std::cerr << "Tests run with NDEBUG defined (asserts compiled out)";
    std::abort();
#endif

    assert(isLowerVowel('a'));
    assert(isLowerVowel('e'));
    assert(isLowerVowel('i'));
    assert(isLowerVowel('o'));
    assert(isLowerVowel('u'));
    assert(!isLowerVowel('b'));
    assert(!isLowerVowel('q'));
    assert(!isLowerVowel('y'));
    assert(!isLowerVowel('z'));

    return 0;
}

int main()
{
    testVowel();

    // If we reached here, all tests must have passed
    std::cout << "All tests succeeded\n";

    return 0;
}