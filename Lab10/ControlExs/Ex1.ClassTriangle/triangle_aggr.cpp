/* triangle_aggr.cpp */

#include "triangle_aggr.h"
#include <iostream>
#include <cmath>

TriangleAggr::TriangleAggr(const Dot& a, const Dot& b, const Dot& c)
    : a(a), b(b), c(c)
{
}

void TriangleAggr::printSideLengths() const {
    std::cout << b.distanceTo(c) << ", " << a.distanceTo(c) << ", " << a.distanceTo(b) << std::endl;
}

double TriangleAggr::perimeter() const {

    return b.distanceTo(c) + a.distanceTo(c) + a.distanceTo(b);
}

double TriangleAggr::area() const {
    double p = perimeter() / 2.0;

    return std::sqrt(p * (p - b.distanceTo(c)) * (p - a.distanceTo(c)) * (p - a.distanceTo(b)));
}
