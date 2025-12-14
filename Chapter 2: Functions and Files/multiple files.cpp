#include <iostream>

int add(int x, int y); // forward declaration of add() tells the compiler of its existence

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // compile error
    return 0;
}