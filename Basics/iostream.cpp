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
*/



int main() {
    int x{ 5 };

    // these will all print on the same line! We need to output a newline character in order to move the cursor to the next line
    std::cout << "Hello world!";
    std::cout << "Hello" << " world!"; // multiple insertion operators can concatenate multiple pieces of output

    std::cout << 4;

    std::cout << 5;

    std::cout << "Hello world!" << std::endl;

    return 0;
}