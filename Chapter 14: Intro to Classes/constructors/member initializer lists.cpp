/*
Constructor Member Initializer Lists
    Within a constructor, we use member initializer lists to initialize member variables.

    The member initializer list is defined after the constructor parameters.
    It begins with a colon (:), and then lists each member to initialize along with the initialization value for that variable, delimited by commas.
        Direct forms of initialization (preferably braces, or parantheses) but not copy initialization (with an =)
    
    The members in a member initializer list are always initialized in the order in which they are defined inside the class.
    Members in the member initializer list should be listed in the order in which they are defined in the class to avoid unexpected issues.

    Since the member initializer list does the initializing, constructors are often left empty. However, the body can be used for any setup tasks needed related to object creation.

    Acceptable formatting (according to C++ style guide):
        // When everything fits on one line:
        MyClass::MyClass(int var) : some_var_(var) {
        DoSomething();
        }

        // If the signature and initializer list are not all on one line,
        // you must wrap before the colon and indent 4 spaces:
        MyClass::MyClass(int var)
            : some_var_(var), some_other_var_(var + 1) {
        DoSomething();
        }

        // When the list spans multiple lines, put each member on its own line
        // and align them:
        MyClass::MyClass(int var)
            : some_var_(var),             // 4 space indent
            some_other_var_(var + 1) {  // lined up
        DoSomething();
        }

        // As with any other code block, the close curly can be on the same
        // line as the open curly, if it fits.
        MyClass::MyClass(int var)
            : some_var_(var) {}

Error Handling
    To enforce invariants, it is useful to add checks within the constructor body (since statements can go there).
    With no return value, it is difficult to pass a special value back to the user to handle the error themselves; the best thing to do is often to throw an exception if an input for a member variable is invalid.

    
*/


#include <iostream>

class Foo
{
private:
    int m_x {};    // default member initializer (will be ignored)
    int m_y { 2 }; // default member initializer (will be used)
    int m_z;      // no initializer

public:
    Foo(int x)
        : m_x { x } // member initializer list
    {
        std::cout << "Foo constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ", " << m_z << ")\n";
    }
};

int main()
{
    Foo foo { 6 };
    foo.print();

    return 0;
}