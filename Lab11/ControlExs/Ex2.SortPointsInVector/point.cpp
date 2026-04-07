/* point.cpp */

#include "point.h"
#include <cmath>

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const { return x; }

double Point::getY() const { return y; }

double Point::distanceSquared() const {
    return x * x + y * y;
}

double Point::distance() const {
    return std::sqrt(distanceSquared());
}

bool Point::operator<(const Point& other) const {
    return distanceSquared() < other.distanceSquared();
}

std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}