#include <iostream>

class Point2d {
    private:
        double m_x {0.0};
        double m_y {0.0};
    public:
        Point2d() = default;
        Point2d(double x, double y):  m_x {x}, m_y {y} {}

        void print() {
            std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
        }

        double distanceTo(Point2d p2) {
            double x1 = m_x;
            double y1 = m_y;
            
            double x2 = p2.m_x;
            double y2 = p2.m_y;

            return std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
        }
};

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    // Point2d third{ 4.0 }; // should error if uncommented

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}