/* distance.h */

#pragma once
#include <iostream>

class Distance
{
private:
	int feet;
	float inches;
	const float MTF;   // коэффициент перевода метров в футы 

public:
	// конструктор по умолчанию
	Distance();

	// конструктор с двумя параметрами 
	Distance(int ft, float in);

	// конструктор из метров 
	Distance(float meters);

	void getdist();
	void showdist();

	// оператор преобразования 
	operator float() const;

	// перегрузка арифметических операторов
	Distance operator+ (const Distance& d2) const;
	friend Distance operator- (const Distance& d1, const Distance& d2);

	// перегрузка оператора вывода
	friend std::ostream& operator<< (std::ostream& out, const Distance& dist);
};