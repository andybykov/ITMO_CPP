// Упражнение 3. Перегрузка операций операндов различных типов
//

#include <iostream>
#include "distance.h"

int main()
{
    // Distance из метров 
    Distance dist1 = 2.35f;
    std::cout << "dist1 = " << dist1 << std::endl;

    Distance dist2(5, 8.5f);  
    std::cout << "dist2 = " << dist2 << std::endl;

    // Distance + float
    Distance sum1 = dist1 + 1.0f;   
    std::cout << "\ndist1 + 1 m = " << sum1 << std::endl;

    // float + Distance
    Distance sum2 = 2.0f + dist2;   
    std::cout << "2 m + dist2 = " << sum2 << std::endl;

    // Distance - float
    Distance diff1 = dist1 - 0.5f;  
    std::cout << "dist1 - 0.5 m = " << diff1 << std::endl;

    // float - Distance
    Distance diff2 = 3.0f - dist2; 
    std::cout << "3 m - dist2 = " << diff2 << std::endl;

    float m = static_cast<float>(sum1);
    std::cout << "\nsum1 = " << m << " meters" << std::endl;
}