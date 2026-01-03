/*
In and Out Parameters
    Parameters only used for receiving input from the caller (meaning, most of them) are known as in parameters.

    Parameters used only to return information back to the caller are called out parameters.
        They are useful if the return value is not sufficient information.
    Their usage is a bit unnatural since the variable has to be initialized in the caller, passed to the callee, and only used once the function returns.
    It is also not always obvious that an out parameter is intended to be modified by the function call.
        As such, prefer pass by reference for non-optional out-parameters.

    A parameter whose value is both used by the function and overwritten by it to give information to the caller is called an in-out parameter.xx
    
    If you’re going to pass by reference in order to avoid making a copy of the argument, you should almost always pass by const reference.
    Two cases where pass non-const reference may make more sense:
        - Use pass by non-const reference when a parameter is an in-out-parameter. Since we’re already passing in the object we need back out, it’s often more straightforward and performant to just modify that object.
        - Use pass by non-const reference when a function would otherwise return an object by value to the caller, but making a copy of that object is extremely expensive.- 
*/
#include <cmath>
#include <iostream>

void print(int x) // x is an in parameter
{
    std::cout << x << '\n';
}

void print(const std::string& s) // s is an in parameter
{
    std::cout << s << '\n';
}


// sinOut and cosOut are out parameters
void getSinCos(double degrees, double& sinOut, double& cosOut)
{
    // sin() and cos() take radians, not degrees, so we need to convert
    constexpr double pi { 3.14159265358979323846 }; // the value of pi
    double radians = degrees * pi / 180.0;
    sinOut = std::sin(radians);
    cosOut = std::cos(radians);
}

int main()
{
    print(5);
    std::string s { "Hello, world!" };
    print(s);

    double sin { 0.0 };
    double cos { 0.0 };

    double degrees{};
    std::cout << "Enter the number of degrees: ";
    std::cin >> degrees;

    // getSinCos will return the sin and cos in variables sin and cos
    getSinCos(degrees, sin, cos);

    std::cout << "The sin is " << sin << '\n';
    std::cout << "The cos is " << cos << '\n';


    return 0;
}