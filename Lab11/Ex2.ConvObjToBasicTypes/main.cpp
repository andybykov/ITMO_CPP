// Упражнение 2. Преобразования объектов в основные типы и наоборот
//

#include <iostream>
#include "distance.h"

int main()
{

    // преобразование float -> Distance с помощью конструктора
    Distance dist1 = 2.35F;   
    std::cout << "dist1 = " << dist1 << std::endl;
    float mtrs;

    // Явное преобразование Distance -> float
    mtrs = static_cast<float>(dist1);
    std::cout << "Converting Distance to meters: " << mtrs << " meters" << std::endl;

    // Неявное преобразование
    Distance dist2 = 5.0F;     // объект из метров
    mtrs = dist2;              // неявное преобразование 
    std::cout << "dist2 = " << dist2 << " == " << mtrs << " meters" << std::endl;

    // арифметические операции 
    Distance dist3 = dist1 + dist2;
    std::cout << "dist1 + dist2 = " << dist3 << " ";

    float sumMeters = static_cast<float>(dist3);
    std::cout << "== " << sumMeters << " meters" << std::endl;

    return 0;
}