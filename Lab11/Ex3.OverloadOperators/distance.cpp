/* distance.cpp */

#include "distance.h"
#include <iostream>

// конструктор по умолчанию
Distance::Distance() : feet(0), inches(0.0), MTF(3.280833F) {}

// конструктор с двумя параметрами
Distance::Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) {}

// конструктор из метров
Distance::Distance(float meters) : MTF(3.280833F)
{
	float fltfeet = MTF * meters;      // перевод метров в футы
	feet = static_cast<int>(fltfeet);  // число футов
	inches = 12.0f * (fltfeet - feet); // остаток == дюймы
}

void Distance::getdist()
{
	std::cout << "\nEnter feets: ";
	std::cin >> feet;
	std::cout << "Enter inches: ";
	std::cin >> inches;
}

void Distance::showdist()
{
	std::cout << feet << "\'-" << inches << "\"";
}

// оператор преобразования в float 
Distance::operator float() const
{
	float fracfeet = inches / 12.0f;
	fracfeet += static_cast<float>(feet);
	return fracfeet / MTF;
}

// оператор сложения
Distance Distance::operator+ (const Distance& d2) const
{
	int f = feet + d2.feet;
	float i = inches + d2.inches;
	if (i >= 12.0f)
	{
		i -= 12.0f;
		f++;
	}
	return Distance(f, i);
}

// оператор вычитания 
Distance operator- (const Distance& d1, const Distance& d2)
{
	int f = d1.feet - d2.feet;
	float i = d1.inches - d2.inches;
	if (i < 0.0f)
	{
		i += 12.0f;
		f--;
	}
	if (f < 0) f = 0;
	return Distance(f, i);
}


// операторы для смешанных типов
// Distance + float 
Distance operator+ (const Distance& d, float meters)
{
	Distance d2(meters);
	return d + d2;
}

// float + Distance
Distance operator+ (float meters, const Distance& d)
{
	Distance d1(meters);
	return d1 + d;
}

// Distance - float
Distance operator- (const Distance& d, float meters)
{
	Distance d2(meters);
	return d - d2;
}

// float - Distance 
Distance operator- (float meters, const Distance& d)
{
	Distance d1(meters);
	return d1 - d;
}

// оператор вывода
std::ostream& operator<< (std::ostream& out, const Distance& dist)
{
	out << dist.feet << "\'-" << dist.inches << "\"";
	return out;
}