/*
Compound Statements
    Also known as blocks or block statements, compound statements is a group of zero or more statements treated by the compiler as a single statement.
    They are surrounded by { and } and can be used anywhere a single statement is allowed. 
    An example of a block is a function body.

    While functions cannot be nested within each other, blocks can be nested inside other blocks. Try to keep nesting level at 3 or less.
        A common use case is nested if statements.
*/

int add(int x, int y)
{ // block
    return x + y;
} // end block

int main()
{ // outer block

    // multiple statements
    int value {};

    { // inner/nested block
        add(3, 4);
    } // end inner/nested block

    return 0;

} // end outer block