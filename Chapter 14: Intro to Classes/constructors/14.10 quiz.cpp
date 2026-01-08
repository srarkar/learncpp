/*
Write a class named Ball. 
Ball should have two private member variables, one to hold a color, and one to hold a radius. 
Also write a function to print out the color and radius of the ball.
*/
#include <iostream>
#include <string>

class Ball {
    private:
        std::string m_color { "none" };
        double m_radius { 0.0 };

    public:
        // constructor
        Ball(std::string_view color, double radius) : m_color {color}, m_radius {radius} {
        }

        // getters
        std::string_view getColor() const { return m_color; }
        double getRadius() const { return m_radius; }
};


void print(Ball b) {
    std::cout << "Ball(" << b.getColor() << ", " << b.getRadius() << ")\n";
}


int main()
{
	Ball blue { "blue", 10.0 };
	print(blue);

	Ball red { "red", 12.0 };
	print(red);

	return 0;
}