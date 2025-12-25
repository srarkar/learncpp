/*
    Global Constants
        It is often the case that a program relies on some symbolic constants that would be helpful to be consisten throughout the entire program.
        Prior to C++17, the methodology to set this up would be:
            - Create header file to hold such constants
            - Define a namespace in this header file
            - Add all constants to namespace (ensuring they are constexpr)
            - #include the header file wherever needed
        Since const globals have internal linkage, each translation unit where the header is included gets it own copy of the constant. 
            Changing the value would necessitate every file that uses it being recompiled, and if the constants are large/cannot be optimized away, all the copies can consume a lot of memory.
            One advantage is that it is compatible prior to C++17, and can be used in constant expressions
        
        An alternative is to make the constants into external variables, which creates a single shared variable across all files.
            - define the constants in a .cpp file 
            - put forward declarations in the header
            - extern the constexpr definitions in the .cpp file
            - the forward declarations in the header can be extern and const
        
        Outside of our constants file, the variables cannot belong to a constant expression since they are not constexpr'd in the header file.
        This may reduce the compiler's ability to optimize them out.
        This method is primarily useful if the constants need to be changed often in order to improve compile times.
*/

/*
    Global constants as Inline Variables
        Inline variables can have more than one definition so long as those definitions are identical (across translation units).
        We can use them as global constants by defining them in a header file, which avoids the downsides of duplicate variables.
            Inline variables have external linkage by default.
        
        Our header file can contain inline constexpr variables, and be included into any files where they are needed.
        Note that if the constants change, we must recompile all relevant files still. This does avoid the high memory consumption, however.
        Another disadvantage is that it is only possible with C++17 or later.
*/
