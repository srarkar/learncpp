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

/*
Finding the cause
    - This is often difficult, as simply inspecting the code can simply lead to making the same assumptions that caused the bug in the first place.
    
    - First, try to reproduce the problem. 
        Observing the problem occurring is key to solving it, and we can use reproduction steps to generate the issue again consistently.
    - Hi-lo approach
        The bug must lie somewhere between the start and end of the program. 
        We can start at some part of the code, and check if the error exists at runtime at that part.
        If it doesn't then the bug exists somewhere below it, and if it does then it exists above it.
*/