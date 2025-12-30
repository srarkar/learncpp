/*
Optimization
    Optimization is the process of modifying software to make it work more efficiently (run fast, use fewer resource, etc.).

    A profiler is a program that checks how long various parts of a program take to run, and how they impact overall performance.
    Optimizing by hand is slow, and so it makes sense to focus on changes that have the largest impact
        - more perforamnt algorithms
        - parallelization
        - data storage and access methods
    
    Some optimizations can be done automatically by a program called an optimizer. 
    They usually work at a low-level by removing, rewriting or rearranging code to let it run faster on a particular system -- something that a programmer might not be able to make the best decision for
    Note that source code is not modified (much like the preprocessor), but rather is applied transparently so that no changes in output occur.
*/

/*
The As-if Rule
    A compiler can modify behavior however it wishes, so long as those modifications do not affect observable behavior. 
        The only notable exception is for unnecessary calls to a copy or move constructor, even if those constructors have observable behavior

Compile-Time Optimization
    One method of optimizing is partially or fully evaluating an expression at compile time. In doing so, the actual executable is smaller/faster, at the cost of a slightly slower compilation process.
    One of the forms of compile-time optimization is constant folding, where expressions with literal operands are replaced by the result/value of the expression. 
    Similarly, constant propagation replaces variables with known values at compile-time with their actual values, saving on retrieving the variable's value from memory at runtime.

    Dead code elimination removes code that is never reached, or does not contribute to the output of the program.
    That is, if a code has zero impact on observable behavior, it is safe to remove it entirely (in other words, optimize it out)
*/

/*
Constants and Builds
    Constant values are easier for the compiler to optimize since it encourages the use of constant propagation and the variable being optimized out entirely.
    A compile-time constant is a constant whose value is known at compile-time. Examples include:
        - Literals.
        - Constant objects whose initializers are compile-time constants.
    A runtime constant is a constant whose value is determined in a runtime context. Examples include:
        - Constant function parameters.
        - Constant objects whose initializers are non-constants or runtime constants.
    Note that some runtime constants (and even non-constants) can be evaluated at compile-time for optimization purposes (under the as-if rule).
    Also, some compile-time constants (e.g. const double d { 1.2 };) cannot be used in compile-time features, as defined by the language standard.

    While optimization improves code performance, it can also worsen readability.
    Hence, there are usually options for a debug build and release build.
        The debug build will minimize / turn off optimization so that source code matches the compiled code closely, meaning that it is easier to find and fix issues.
        A release build will include optimizations since the optimizations are relevant for the compiled code in this case
    After all, there is often little visibiity on what the compiler actually does with the original code. 
*/

#include <iostream>

// strictly for the sake of compiling
int five() {
    return 0;
}

int pass(int x) {
    return x;
}
//

int main()
{
	int x { 3 + 4 }; // can be optimized to int x {7} (constant folding)
	std::cout << x << '\n'; // better yet, remove the line above this and change to std::cout << 7 << '\n'; (constant propagation)

    // The following are non-constants:
    [[maybe_unused]] int a { 5 };

    // The following are compile-time constants:
    [[maybe_unused]] const int b { 5 };
    [[maybe_unused]] const double c { 1.2 };
    [[maybe_unused]] const int d { b };       // b is a compile-time constant

    // The following are runtime constants:
    [[maybe_unused]] const int e { a };       // a is non-const
    [[maybe_unused]] const int f { e };       // e is a runtime constant
    [[maybe_unused]] const int g { five() };  // return value isn't known until runtime
    [[maybe_unused]] const int h { pass(5) }; // return value isn't known until runtime
	return 0;
}