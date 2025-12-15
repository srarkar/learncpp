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

// When we do #include <iostream>, we copy all the contents of the iostream file here, including the forward declaration for std::cout
#include <iostream>
#include "add.h"

int main()
{
    std::cout << add(1, 2) << '\n';
    return 0;
}