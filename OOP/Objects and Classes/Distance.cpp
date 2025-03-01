#include <complex>
#include <iomanip>
#include <iostream>


class Point {
    int x;
    int y;

public:
    Point(const int &x, const int &y) :
        x(x), y(y) {}

    Point() :
        x(), y() {}

    int getX() const {
        return this->x;
    }

    int getY() const {
        return this->y;
    }

    friend std::istream &operator>>(std::istream &is, Point &point);
};

std::istream &operator>>(std::istream &is, Point &point) {
    return is >> point.x >> point.y;
}


double calculateDistanceBetweenTwoPoints(const Point& point1, const Point& point2) {
    return std::sqrt(
            (point1.getX() - point2.getX())*(point1.getX() - point2.getX())
            +
            (point1.getY() - point2.getY())*(point1.getY() - point2.getY())
        );
}


int main() {
    Point p1, p2;

    std::cin >> p1 >> p2;

    std::cout << std::fixed << std::setprecision(3);
    std::cout << calculateDistanceBetweenTwoPoints(p1, p2) << '\n';

    return 0;
}
