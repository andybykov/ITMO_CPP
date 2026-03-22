// Задание 4. Рекурсивная функция суммы ряда

#include <iostream>


double sumSeries(double n) {
    if (n == 1) return 5; // базовый случай
    else return 5 * n + sumSeries(n - 1); // рекурсивыный случай
}


int main()
{
    double n = sumSeries(5);
    std::cout << n << std::endl;
}
