/*
Inline functions and variables
    When writing some code, it can either be added to some existing function (i.e. inline) or added to a small new function.
    While having short, specialized functions is generally good practice, every function call adds additional overhead to a program.

    A compiler optimization called inline expansion involves taking a function call and replacing it with the code from the function itself, replacing the arguments with the parameters (values)
    This is useful because it removes the overhead of calling the function (call stack buildup/teardown) and can also create constant expressions
    
    It is important to note that even if a function can be expanded, the compiler decides whether each function call actually should be expanded or not.
        It is not always better to do so since replacing the function call with the function body can lead to a higher instruction count, and therefore a larger executable.
        Inline expansion is best suited to simple, short functions (e.g. no more than a few statements), especially cases where a single function call can be executed more than once (e.g. function calls inside a loop).
    
    Some functions cannot be expanded. One example is those whose definition is found in a different translation unit.

    Originally, the inline keyword was intended for hinting the compiler towards a function that could be expanded.
        Modern compilers do this themselves, however.
        In addition, programmers may use inline in a way that does not lead to better performance (premature optimization)
        Since inline is added to the function header, it is not specific to each function call as it should be
        The compiler can also just ignore the inline, since it is non-binding

    In modern C++, the inline term has evolved to denote that multiple definitions are allowed.
    An inline function is one that is allowed to be defined in multiple translation units without violating the ODR.
    Requirements:   
        - The compiler must be able to see each full definition for the inline function in each translation unit (NOT just a forward declaration).
        There can only be one such definition per translation unit (to abide by ODR). While the definition can be placed after the point of use, along with a forward declaration, the compiler will likely not be able to optimize until after the full definition.
        - Every definition for an inline function (with external linkage, which is default for functions) must be identical
    The linker will consolidate all the definitions into a single one.

    Inline functions are typically defined in header files, where they can be #included into the top of any code file that needs to see the full definition of the identifier. 
        This ensures that all inline definitions for an identifier are identical.

*/