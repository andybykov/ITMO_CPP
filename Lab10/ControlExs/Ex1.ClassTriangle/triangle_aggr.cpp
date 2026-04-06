/* triangle_aggr.cpp */

#include "triangle_aggr.h"
#include <iostream>
#include <cmath>

TriangleAggr::TriangleAggr(const Dot& a, const Dot& b, const Dot& c)
    : a(a), b(b), c(c)
{
    calculateSides();
}

void TriangleAggr::calculateSides() {
    sideA = b.distanceTo(c);
    sideB = a.distanceTo(c);
    sideC = a.distanceTo(b);
}

void TriangleAggr::printSideLengths() const {
    std::cout << "Sides of triangle: " << sideA << ", " << sideB << ", " << sideC << std::endl;
}

double TriangleAggr::perimeter() const {

    return sideA + sideB + sideC;
}

double TriangleAggr::area() const {
    double p = perimeter() / 2.0;

    return std::sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}
