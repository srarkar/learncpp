/*
    std::string_view   
        When initializing an std::string with a literal, we must allocate memory for the std::string object, copy over the data from the initializer
        If we only printed this data, it would be inefficient to do so much work (since std::string is not a fundamental data type) compared to the result

        C++17 introduced std::string_view in the <string_view> header, which provides a read-only view of to an already existing string.
        Best practice is to use std::string_view when we need to just read/access a string without modifying it, especially for function parameters

        Note that they can be initialized with a C-style string, std::string (both of which will be implicity converted), or another std::string_view.
        On the other hand, an std::string_view is not implicitly converted to an std::string since the copy operation is expensive
            If intentional, we can convert an existing string_view to a string via static_cast, or an initializer
        
        Changing the std::string_view to another string does not modify the previous one, but simply points the object to the new string instead

        We can declare one using an "sv" suffix added to a c-style string literal. Since it is read-only, it also supports constexpr (unlike std::string).
*/

/*
    Owners and Viewers
        Owning an object comes with responsibility/expense of creating, managing, and disposing of that object.
        Viewing an object is cheap but gives no control over the object itself, and that view may be temporary.

    std::string is an owner since it creates a copy of the initializer, since we can't rely on the initializer remaining unchanged afterwards.
    On the other hand, std::string_view is a viewer. This view depends on the initializer. If the string being viewed is modified or destroyed/falls out of scope while the view is active, it can lead to unexpected behavior.
        Its best use is a type for a read-only function parameter. We can pass in a C-stlye string, std::string, or std::string_view without issue.

    Initializing an std::string_view with a literal that is an std::string causes undefined behavior, since the temporary std::string used to initialize is destroyed at the end of the expression

    However, std::string_views can be revalidated. That is, even if a modification occurs, we can reassign the string_view afterwards to prevent undefined behavior.
    While an std::string_view can be a return value for a function, if the std::string_view is viewing a local variable that is destroyed after stack teardown, further use of the view is UB.
        This is safe when returning a C-style literal, since they exist for the length of the entire program. 
        It is also safe when returning an std::string_view function parameter, so long as it is used right away if the argument is a temporary object.

    While we cannot modify the object being viewed, we can modify our view of it via remove_prefix() and remove_suffix(). Both take one parameter, the number of chars to remove.
    Since it therefore possible to only view a substring, there are times when a string_view is null-terminated, and times when it is not (unlike std::string and c-style strings, which are both always null-terminated)
*/

/*
Summary of std::string vs std::string_view usage
    Use a std::string variable when:
        You need a string that you can modify.
        You need to store user-inputted text.
        You need to store the return value of a function that returns a std::string.
    Use a std::string_view variable when:
        You need read-only access to part or all of a string that already exists elsewhere and will not be modified or destroyed before use of the std::string_view is complete.
        You need a symbolic constant for a C-style string.
        You need to continue viewing the return value of a function that returns a C-style string or a non-dangling std::string_view

    Use a std::string function parameter when:
        The function needs to modify the string passed in as an argument without affecting the caller. This is rare.
        You are using language standard C++14 or older and aren’t comfortable using references yet.
    Use a std::string_view function parameter when:
        The function needs a read-only string.
        The function needs to work with non-null-terminated strings.

    Use a const std::string& function parameter when:
        You are using language standard C++14 or older, and the function needs a read-only string to work with (as std::string_view is not available until C++17).
        You are calling other functions that require a const std::string, const std::string&, or const C-style string (as std::string_view may not be null-terminated).
    Use a std::string& function parameter when:
        You are using a std::string as an out-parameter
        You are calling other functions that require a std::string&, or non-const C-style string.
    
    Use a std::string return type when:
        The return value is a std::string local variable or function parameter.
        The return value is a function call or operator that returns a std::string by value.
    Use a std::string_view return type when:
        The function returns a C-style string literal or local std::string_view that has been initialized with a C-style string literal.
        The function returns a std::string_view parameter.

    Initializing and copying std::string is expensive, so avoid this as much as possible.
    Avoid passing std::string by value, as this makes a copy.
    If possible, avoid creating short-lived std::string objects.
    Modifying a std::string will invalidate any views to that string.
    It is okay to return a local std::string by value.
    
    std::string_view is typically used for passing string function parameters and returning string literals.
    Because C-style string literals exist for the entire program, it is always okay to set a std::string_view to a C-style string literal.
    When a string is destroyed, all views to that string are invalidated.
    Using an invalidated view (other than using assignment to revalidate the view) will cause undefined behavior.
    A std::string_view may or may not be null-terminated.
*/


#include <iostream>
#include <string>

void printString(std::string str) // str makes a copy of its initializer
{
    std::cout << str << '\n';
}

void printSV(std::string_view str) // now a std::string_view
{
    std::cout << str << '\n';
}

int main()
{
    std::string s{ "Hello, world!" }; // s makes a copy of its initializer, just to print it and be destroyed afterwards
    std::cout << s << '\n';
    printString(s); // we make two copies: one for s, and one for the parameter

    std::string_view s{ "Hello, world!" }; // now a std::string_view. we do not copy the literal, but rather have read-only access to it
    printSV(s);

    std::string name { "Alex" };
    std::string_view sv { name }; // sv is now viewing name
    std::cout << sv << '\n'; // prints Alex

    sv = "John"; // sv is now viewing "John" (does not change name)
    std::cout << sv << '\n'; // prints John

    std::cout << name << '\n'; // prints Alex

    using namespace std::string_literals;      // access the s suffix
    using namespace std::string_view_literals; // access the sv suffix

    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal
    std::cout << "moo\n"sv; // sv suffix is a std::string_view literal

    std::string_view name { "Alex"s }; // "Alex"s creates a temporary std::string
    std::cout << name << '\n'; // undefined behavior, since the temporary is destroyed at the end of the expression of the line above

    std::string s { "Hello, world!" };
    std::string_view sv { s }; // sv is now viewing s

    s = "Hello, a!";    // modifies s, which invalidates sv (s is still valid)
    std::cout << sv << '\n';   // undefined behavior

    // modifying view, not the object itself
    std::string_view str{ "Peach" };
	std::cout << str << '\n';

	// Remove 1 character from the left side of the view
	str.remove_prefix(1);
	std::cout << str << '\n';

	// Remove 2 characters from the right side of the view
	str.remove_suffix(2);
	std::cout << str << '\n';

	str = "Peach"; // reset the view
	std::cout << str << '\n';

	return 0;
}