/* distance.h */

#pragma once
#include <iostream>

class Distance
{
private:
    int feet;
    float inches;

public:
    // конструктор по умолчанию
    Distance();

    // конструктор с двумя параметрами
    Distance(int ft, float in);

    void getdist();

    void showdist();  

    Distance operator+ (const Distance& d2) const;

    friend Distance operator- (const Distance& d1, const Distance& d2);
 
    friend std::ostream& operator<< (std::ostream& out, const Distance& dist);
};