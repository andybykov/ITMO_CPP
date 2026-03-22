// Задание 5. Применение рекурсии для перевода целого числа в двоичный код
// 

#include <iostream>

// функция перевода из десятичной в двоичную систему
long long decToBin(int n) {
    // Базовый случай
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Рекурсивный случай
    return decToBin(n / 2) * 10 + (n % 2);
}


int main()
{
    int n = decToBin(5);
    std::cout << n;
}
