/* triangle_comp.h */

#pragma once
#include "dot.h"

class TriangleComp {
public:
	// принимает координаты точек
	TriangleComp(double x1, double y1, double x2, double y2, double x3, double y3);

	void printSideLengths() const;

	double perimeter() const;

	double area() const;

private:
	Dot a, b, c;  // точки поля класса 
};