// Задание 1. Перегрузка операторов в классе Time
//

#include "time.h"
#include <iostream>

int main() {
    // Тест конструкторов
    Time t1;
    Time t2(10, 30, 45);
    Time t3(23, 59, 59);

    std::cout << "t1: "; t1.print();
    std::cout << "t2: "; t2.print();
    std::cout << "t3: "; t3.print();


    // Time + Time
    Time t4(2, 20, 30);
    Time t5 = t2 + t4;
    std::cout << "t2 + t4: "; t5.print();

    // Time - Time
    Time t7 = t2 - t4;
    std::cout << "t2 - t4: "; t7.print();

    Time t8 = t4 - t2;  // вычитание большего из меньшего
    std::cout << "t4 - t2: "; t8.print();

    // Тест Time + double
    Time t9 = t2 + 75.5;
    t2.print();
    std::cout << "t2 + 75.5 sec: "; t9.print();

    // Тест double + Time
    Time t11 = 90.7 + t2;
    std::cout << "90.7 sec + t2: "; t11.print();

    // сравнения
    std::cout << std::boolalpha;
    std::cout << "t2 == t4: " << (t2 == t4) << std::endl;
    std::cout << "t2 != t4: " << (t2 != t4) << std::endl;
    std::cout << "t2 < t4: " << (t2 < t4) << std::endl;
    std::cout << "t2 > t4: " << (t2 > t4) << std::endl;
    std::cout << "t2 <= t4: " << (t2 <= t4) << std::endl;
    std::cout << "t2 >= t4: " << (t2 >= t4) << std::endl;

    return 0;
}