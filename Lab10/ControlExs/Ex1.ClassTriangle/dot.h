/* dot.h */

#pragma once
#include <cmath>

class Dot {

private:
	double x;

	double y;

public:
	Dot();

	Dot(double x, double y);

	double distanceTo(const Dot& point) const;

	double getX() const;

	double getY() const;
};