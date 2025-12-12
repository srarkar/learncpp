#include <iostream>

/*
    The input/output (io) library is part of the C++ std library, and is used to get input from the keyboard and output data to a console.
        std::cout -> cout = character output. sends data to the console to be printed as text
                     uses the insertion operator (<<) to send

                    std::cout is buffered, meaning that output sent to console is stored in some region of memory (buffer) before it is
                     "flushed" to console. Flushes can occur in multiple scenarios, the main ones of which are: 
                        - When the buffer is full
                        - When a program terminates: All standard streams are generally flushed upon normal program termination.
                        - When std::cin is used: any input operation on std::cin first flushes std::cout.
                        - When std::cerr is used: The standard error stream std::cerr is always flushed after each output operation, and operations on it can also indirectly affect std::cout.
                        - When std::endl is used: The std::endl manipulator explicitly writes a newline character and then calls flush(). 

        std::endl -> moves the cursor to the start of next line. This also flushes the output buffer 

        When to use std::endl vs newline character (\n) ?
            - Since std::endl implicitly calls flush after the newline character, it can be inefficient, since it could force multiple flushes that are not needed
            - Best to use if we want to see the output immediately rather than waiting for the next natural flush
            - Otherwise, simply append a newline character ('\n') to move the cursor to the next line without force-flushing

        std::cin -> cin = character input. reads input from the keyboard
                    uses the extraction operator (>>) to place input data into a variable
                        - skips leading whitespace
                        - if the input buffer is now empty, >> will wait for the user to enter more data.
                        - >> then extracts as many consecutive characters as it can, until it encounters either a newline character 
                            or a invalid character for the variable being extracted to (such as a space char when loading into an integer)
                            If this step is completed, extraction is a success. if this step is reached but no chars extracted, then 
                            the object being extracted to is copy-assigned the value 0, and any future extractions will immediately fail until std::cin is cleared
                    Much like std::cout, std::cin is buffered
                    The extraction operator removes from the front of the input buffer and stores it into a variable via copy-assignment

                    cin being buffered allows us to take a single input (ex: "4 5") and extract multiple times from it (x = 4, y = 5)
*/



int main() {
    int a{ 5 };

    // these will all print on the same line! We need to output a newline character in order to move the cursor to the next line
    std::cout << "Hello world!";
    std::cout << "Hello" << " world!"; // multiple insertion operators can concatenate multiple pieces of output

    std::cout << 4;

    std::cout << a;

    std::cout << "Hello world!" << std::endl; // fine, but forces a std::flush
    
    // both of these are conventional!
    std::cout << "Hello world!" << '\n'; // double-quotes for the \n is legal syntax, but unconventional 
    std::cout << "Hello world!\n"; 

    /* Author note about using double quotes for character in outputs:
        - It’s simpler to double-quote all outputted text rather than having to determine what should be single-quoted and double-quoted.
        - More importantly, it helps avoid inadvertent multicharacter literals (see Datatypes)
    */

    int x{};

    std::cout << "Enter a number: "; // newline or endl is not needed, since user pressing "enter" will move to new line

    std::cin >> x;

    std::cout << "You entered: " << x << '\n';


    int y{};
    int z{};
    std::cout << "Now enter two numbers: ";
    std::cin >> y >> z; // get two numbers and store in variable x and y respectively

    std::cout << "You entered " << y << " and " << z << '\n';

    return 0;
}