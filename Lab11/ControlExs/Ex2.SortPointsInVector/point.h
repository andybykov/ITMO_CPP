/* point.h */

#pragma once
#include <iostream>

class Point {
private:
	double x, y;

	double distanceSquared() const; // квадрат расстояния до центра

public:
	Point(double x = 0, double y = 0);

	double getX() const;

	double getY() const;

	double distance() const; // расстояние до центра

	// перегрузка операторов
	bool operator<(const Point& other) const;

	friend std::ostream& operator<<(std::ostream& out, const Point& p);
};