#include <iostream>
#include <string>

class Ball {

    private:
        std::string m_color { "black" };
        double m_radius { 10.0 };

    public:

        Ball(double radius) : Ball {"black", radius} {} // delegate to other constructor

        Ball(std::string_view color = "black", double radius = 10.0) : m_color {color}, m_radius {radius} {}

        // getters
        // std::string_view getColor() const { return m_color; }
        // double getRadius() const { return m_radius; }
};

int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}