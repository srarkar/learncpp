/*
Errors
    Errors generally fall into one of two categories:
        - Syntax errors: caused by a statement that is not valid according to the grammar of C++.
            Examples: missing semicolons, unamtched braces/parenthesis
            Detected by the compiler, and generally easy to fix

            #include <iostream>
            int main( // missing closing brace
            {
                int 1x; // variable name can't start with number
                std::cout << "Hi there"; << x +++ << '\n'; // extraneous semicolon, operator+++ does not exist
                return 0 // missing semicolon at end of statement
            }

        - Semantic/logical errors: An error in meaning. 
            A statement can be syntactically valid, but either violates other rules of the language or does not do what the programmer intended
            Some kinds are caught by the compiler (undeclared variable, type mismatch...)
            Others only cause problems at runtime, such as a divide by zero
            
            It can also be actual behavior not aligning with the intended behavior, such as an add() function performing subtraction


        int add(int x, int y) // this function is supposed to perform addition
        {
            return x - y; // but it doesn't due to the wrong operator being used
        }
        int main()
        {
            int a { 10 };
            int b { 0 };
            std::cout << a << " / " << b << " = " << a / b << '\n'; // division by 0 is undefined in mathematics

            int x;
            std::cout << x; // undefined behavior from use of an uninitialized variable

            5 = y; // x not declared, cannot assign a value to 5
            
            return "hello"; // "hello" cannot be converted to an int
        }
*/

/*
Debugging
    All bugs stem from a simple premise: something that is assumed to be correct, isn't.
    A debugging process looks something like:
        - Find the cause of the problem (usually a specific line)
        - Understand why the issue is occurring
        - Determine how to fix it
        - Repair the issue
        - Retest to ensure problem is fixed
        - Retest to ensure no other problems emerged 
*/