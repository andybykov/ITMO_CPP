// Задание 1. Реализация класса Triangle


#include <iostream>
#include "dot.h"
#include "triangle_comp.h"
#include "triangle_aggr.h"

int main()
{
    // Композиция
    std::cout << "\tExample of relationship - composition" << std::endl;

    TriangleComp triC(0, 0, 3, 0, 0, 4);

    triC.printSideLengths();          
    
    std::cout << "Perimeter: " << triC.perimeter() << std::endl;
    std::cout << "Area: " << triC.area() << std::endl;

    //Агрегация
    std::cout << "\tExample of relationship - aggregation" << std::endl;
    // Точки создаются отедельно
    Dot p1(0, 0);
    Dot p2(3, 0);
    Dot p3(0, 4);

    // передаем точки в конструктор
    TriangleAggr triA(p1, p2, p3);

    triA.printSideLengths();

    std::cout << "Perimeter: " << triA.perimeter() << std::endl;
    std::cout << "Area: " << triA.area() << std::endl;
}
