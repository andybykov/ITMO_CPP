/* dot.cpp */

#include "dot.h"

Dot::Dot() : x(0), y(0) {}

Dot::Dot(double x, double y) : x(x), y(y) {}

double Dot::distanceTo(const Dot& point) const {
    double dx = point.x - x;

    double dy = point.y - y;

    return std::sqrt(dx * dx + dy * dy);
}

double Dot::getX() const { return x; }

double Dot::getY() const { return y; }
