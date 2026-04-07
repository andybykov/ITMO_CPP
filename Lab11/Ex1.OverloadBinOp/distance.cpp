/* distance.cpp */

#include "distance.h"
#include <iostream>

// конструктор по умолчанию
Distance::Distance() : feet(0), inches(0.0) {}

// конструктор с двумя параметрами
Distance::Distance(int ft, float in) : feet(ft), inches(in) {}

void Distance::getdist()
{
    std::cout << "\nEnter feets: ";
    std::cin >> feet;
    std::cout << "\nEnter inches: ";
    std::cin >> inches;
}

void Distance::showdist()
{
    std::cout << feet << "-" << inches << "\n";
}

Distance Distance::operator+ (const Distance& d2) const
{
    int f = feet + d2.feet;
    float i = inches + d2.inches;
    if (i >= 12.0)
    {
        i -= 12.0;
        f++;
    }
    return Distance(f, i);
}

// дружественная функция
Distance operator- (const Distance& d1, const Distance& d2)
{
    int f = d1.feet - d2.feet;
    float i = d1.inches - d2.inches;
    if (i < 0.0)
    {
        i += 12.0;
        f--;
    }
    // защита от отрицательных расстояний 
    if (f < 0) f = 0;
    return Distance(f, i);
}

// Перегрузка оператора вывода
std::ostream& operator<< (std::ostream& out, const Distance& dist)
{
    out << dist.feet << "\'-" << dist.inches << "\"";
    return out;
}