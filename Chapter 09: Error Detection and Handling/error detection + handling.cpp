/*
    Detecting and Handling Errors
        Errors arise from incorrect assumptions about written code.
        A function being successful when it is not, parameters being the correct value when they are not, and even inputs being valid and formatted correctly when they are not.

        Rather than only testing the happy path (simple, ideal situation) for some code segment, we should check sad paths, and defensively program to account for them.

        When handling an error, there are generally 4 ways to do so:
            - Handle the error within the function itself
            - Pass the error to the caller for it to handle
            - Throw an exception
            - Halt the program

        Within handling the error within the program itself, which is usually ideal in order to contain the error, there are 2 ways to do so:
            - Retry until successful
            - Cancel the operation
        
        When passing back to the caller, we can use certain return values to indicate something went wrong.
            This can be a return value that should be impossible to return with a valid input, meaning it must have been done intentionally.
            This is known as a sentinel value.
        
        If an error is non-recoverable, or fatal, then we can either use std::exit() or return main with a nonzero status code (such as 1).

        Exceptions serve as another way to pass errors to the caller.
        
        When to print to std::cout vs std::cerr:
            For interactive programs, use std::cerr or a logfile for status and diagnostic information that may be helpful for diagnosing issues but probably isn’t interesting for normal users
            For a non-interactive program (tool or service), use std::cerr for error output only (e.g. could not open file x). This allows errors to be displayed or parsed separately from normal output.
*/      