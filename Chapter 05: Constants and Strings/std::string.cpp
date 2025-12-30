/*
std::string
    C-style strings can be dangerous and difficult to work with, giving rise to std::string and std::string_view in C++.

    std::string belongs to the <string> header. They are initialized and updated much like other objects.
    A very useful attribute of std::string is that it can easily change size (i.e. reassigning a longer or shorter string is no issue)
    This flexibility is tied to dynamic memory allocation, which also makes std::string slower.
    
    The extraction operator (used with std::cin) breaks on whitespace, which means part of the string can be left in the input buffer afterwards.
    Instead, use std::getline() for inputting text. Interestingly, it takes std::cin as a first parameter, and the string variable as the second

    Much like output manipulators (like std::setprecision()), there are also input manipulators.
    std::ws tells std::cin to ignore leading whitespace before extracting. 
        Otherwise, getline() will pull the newline char from the user pressing "enter" when inputting.
        Note that std::ws does not persist across calls, and should be used in each getline() call as part of the std::cin first param
    
    The length of a string is accessed from the <string_name>.length() member function.
        This does not include the null terminator (which is required for std::cin as of C++ 11)
        If assigning this length to an integer variable, use static_cast to avoid warnings about signed/unsigned conversions
    
    std::string is expensive, making a copy of the string used to initialize it. Don't use it to pass a parameter by value, instead use std::string_view (usually)
    However, as a rule of thumb, it is okay to return a std::string by value when the expression of the return statement resolves to any of the following:
        A local variable of type std::string.
        A std::string that has been returned by value from another function call or operator.
        A std::string temporary that is created as part of the return statement.
    
    String literals by default are C-style. Adding an 's' suffix, found in the namespace std::literals::string_literals, makes it into an std::string object
    
    constexpr std::string is not supported including and prior to C++17, and very limited in 20/23. Better to use std::string_view instead.


*/

#include <string>
#include <iostream>

// /* Practice:
//     Write a program that asks the user to enter their full name and their age. 
//     As output, tell the user the sum of their age and the number of characters in their name (use the std::string::length() member function to get the length of the string). 
//     For simplicity, count any spaces in the name as a character.
// */

// /* Sample output:
//     Enter your full name: John Doe
//     Enter your age: 32
//     Your age + length of name is: 40
// */


std::string getName() {
    std::cout << "Enter your full name: ";
    
    std::string full_name { }; 
    std::getline(std::cin >> std::ws, full_name);
    return full_name;
}

int getAge() {
    std::cout << "Enter your age: ";
    int age {};
    std::cin >> age;
    return age;
}

int sumAgeName() {
    // prompt user for full name
    std::string full_name = getName();
    
    // prompt user for age
    int age { getAge() };

    // obtain length of string (static_cast to int)
    int name_length = static_cast<int>(full_name.length());
    
    // add name length with age and print
    std::cout << "Your age + length of name is: " << name_length + age << '\n';
    
}

int main() {
    std::string name { }; // initializing an empty string
    std::string me {"Rick"}; // initializing using literal
    me = "You"; // change name

    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    std::cout << "Enter your favorite color: ";
    std::string color{};
    std::getline(std::cin >> std::ws, color); // read a full line of text into color

    std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';
    std::cout << name << " has " << name.length() << " characters\n";
    int length { static_cast<int>(name.length()) }; // avoid signed/unsigned conversion warnings via static_cast


    using namespace std::string_literals; // easy access to the s suffix

    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal


    return 0;
}