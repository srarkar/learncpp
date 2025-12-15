/*
Header Files
    Adding all the necessary forward declarations to every file quickly becomes very difficult to track and organize.
    Header files (with a .h or .hpp extension) serve to propagate related forward declarations into another code file.

    Header files are composed of:
        - A header guard 
        -  The actual contents of the header file, which are the forward declarations for all of the identifiers we want other files to be able to see
    Avoid variable or function definitions in header files, as it will encourage violations of the ODR 

    There are 4 sets of header files:
        C++ specific (new) -> <name>
        C compatibility (new) -> <cname>
        C++ specific (old) -> <name.h>
        C compatibility (old) -> <name.h>
    Best practice is using standard library headers without the .h, and user-defined headers with it

    Best practice when ordering #includes to maximize chance of compiler catching mistakes:
        - The paired header file for this code file (e.g. add.cpp should #include "add.h")
        - Other headers from the same project (e.g. #include "mymath.h")
        - 3rd party library headers (e.g. #include <boost/tuple/tuple.hpp>)
        - Standard library headers (e.g. #include <iostream>)
    The headers for each grouping should be sorted alphabetically (unless the documentation for a 3rd party library says otherwise).

    Some guidelines:
        - Always include header guards
        - Do not define variables and functions in header files (generally)
        - Give a header file the same name as the source file it’s associated with (e.g. grades.h is paired with grades.cpp).
        - Each header file should have a specific job, and be as independent as possible. For example, you might put all your declarations related to functionality A in A.h and all your declarations related to functionality B in B.h. That way if you only care about A later, you can just include A.h and not get any of the stuff related to B.
        - Be mindful of which headers you need to explicitly include for the functionality that you are using in your code files, to avoid inadvertent transitive includes.
        - A header file should #include any other headers containing functionality it needs. Such a header should compile successfully when #included into a .cpp file by itself.
        - Only #include what you need
        - Do not #include .cpp files.
        - Prefer putting documentation on what something does or how to use it in the header. It’s more likely to be seen there. Documentation describing how something works should remain in the source files.
*/

/*
Header Guards
    Avoiding violations of the ODR can be difficult when dealing with header files.
    Say we have a function defined in a1.h, and a2.h contains "#include a1.h". Lastly, let a3.h include both a1.h and a2.h.
    This will cause a compiler error, since the preprocessor will effectively paste the contents of a1.h twice, causing duplicate definitions for the the functions in a1.h
    Thus, we want some way to prevent re-defining when using header files. 

    The structure of a header guard is as follows (all header files should have one):
    #ifndef SOME_UNIQUE_NAME_HERE
    #define SOME_UNIQUE_NAME_HERE

    // your declarations (and certain types of definitions) here

    #endif

    Alternatively, simply adding #pragma once at the top of the header serves as a guard, with the compiler handling it
    There is one known case where #pragma once will typically fail.
        If a header file is copied so that it exists in multiple places on the file system, if somehow both copies of the header get included, 
            header guards will successfully de-dupe the identical headers, but #pragma once won’t (because the compiler won’t realize they are actually identical content).
    Note that #pragma once is not defined by the C++ standard, and some compilers may not implement it
    Some development houses such as Google prefer traditional headers instead due to better portability
*/

// When we do #include <iostream>, we copy all the contents of the iostream file here, including the forward declaration for std::cout
#include <iostream>
#include "add.h"

int main()
{
    std::cout << add(1, 2) << '\n';
    return 0;
}