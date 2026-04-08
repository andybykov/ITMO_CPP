/* triangle_comp.cpp */

#include "triangle_comp.h"
#include <iostream>
#include <cmath>

TriangleComp::TriangleComp(double x1, double y1, double x2, double y2, double x3, double y3)
    : a(x1, y1), b(x2, y2), c(x3, y3)
{}

void TriangleComp::printSideLengths() const {
    std::cout << "Sides of triangle: "
        << b.distanceTo(c) << ", " << a.distanceTo(c) << ", " << a.distanceTo(b) << std::endl;
}

double TriangleComp::perimeter() const {

    return b.distanceTo(c) + a.distanceTo(c) + a.distanceTo(b);
}

double TriangleComp::area() const {
    double p = perimeter() / 2.0;

    return std::sqrt(p * (p - b.distanceTo(c)) * (p - a.distanceTo(c)) * (p - a.distanceTo(b)));
}