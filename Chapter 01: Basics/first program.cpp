/*
    Expected Behavior:
        // 4 is the input from the user
        Enter an integer: 4 
        Double that number is: 8        
*/

#include <iostream> 

int main() {
    // declare integer variable to hold user input 
    int x{ };

    // get input from user and store into integer variable
    std::cout << "Enter an integer: ";
    std::cin >> x;

    // print double the user input
    std::cout << "Double of " << x << " is " << x * 2 << '\n';

    // bonus: do the same for triple
    std::cout << "Triple of " << x << " is " << x * 3 << '\n';


    return 0;
}