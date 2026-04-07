// Упражнение 1. Перегрузка бинарных операций
//

#include <iostream>
#include "distance.h"

int main()
{
    Distance dist1, dist2, dist3, dist4;

    dist1.getdist();
    dist2.getdist();

    dist3 = dist1 + dist2;
    dist4 = dist1 + dist2 + dist3;

    // вывод с помощью перегруженного оператора <<
    setlocale(LC_ALL, "RU");
    std::cout << "\ndist1 = " << dist1 << std::endl;
    std::cout << "dist2 = " << dist2 << std::endl;
    std::cout << "dist3 = " << dist3 << std::endl;
    std::cout << "dist4 = " << dist4 << std::endl;

    // проверка вычитания 
    Distance dist5 = dist3 - dist1;
    std::cout << "dist5 = dist3 - dist1 = " << dist5 << std::endl;

    return 0;
}