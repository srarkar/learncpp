/*
Friend Non-member Functions
    Let's say we have some class and need complex functions to output the data of the class.
    Defining these functions as members can clutter the class, and non-members do not have access to a class type's private members.

    A friend declaration tells the compiler that some other class or function is a friend. A friend has full access to the private and protected members of another class.
    The friend keyword allows a class to selectively provide access to other classes and functions.
        Note that friendship is always granted by the class whose members will be accessed, not by the one who has the access.
    The friend declaration is not affected by access controls, so it does not matter where within the class body it is placed.

    Friend functions defined inside a class are still considered non-member functions.
    Since they are non-members, friend functions need to be passed an object since they lack an implicit object.

    A class can be friend of more than one class at the same time.
    A friend function should prefer to use the class interface over direct access whenever possible.
    If possible and reasonable, use a non-friend function as opposed to a friend one.
*/

#include <iostream>

class Accumulator
{
private:
    int m_value { 0 };

public:
    void add(int value) { m_value += value; }

    // Here is the friend declaration that makes non-member function void print(const Accumulator& accumulator) a friend of Accumulator
    friend void print(const Accumulator& accumulator);
};

class Humidity; // forward declaration of Humidity

class Temperature
{
private:
    int m_temp { 0 };
public:
    explicit Temperature(int temp) : m_temp { temp } { }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity); // forward declaration needed for this line
};

class Humidity
{
private:
    int m_humidity { 0 };
public:
    explicit Humidity(int humidity) : m_humidity { humidity } {  }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

void printWeather(const Temperature& temperature, const Humidity& humidity)
{
    std::cout << "The temperature is " << temperature.m_temp <<
       " and the humidity is " << humidity.m_humidity << '\n';
}


void print(const Accumulator& accumulator)
{
    // Because print() is a friend of Accumulator
    // it can access the private members of Accumulator
    std::cout << accumulator.m_value;
}

int main()
{
    Accumulator acc{};
    acc.add(5); // add 5 to the accumulator

    print(acc); // call the print() non-member function

    Humidity hum { 10 };
    Temperature temp { 12 };

    printWeather(temp, hum);

    return 0;
}