/* triangle_aggr.h */

#pragma once
#include "dot.h"

class TriangleAggr {
public:
    // принимает ссылки на Dot
    TriangleAggr(const Dot& a, const Dot& b, const Dot& c);

    void printSideLengths() const;

    double perimeter() const;

    double area() const;

private:
    // ссылки 
    const Dot& a;

    const Dot& b;

    const Dot& c;
};
