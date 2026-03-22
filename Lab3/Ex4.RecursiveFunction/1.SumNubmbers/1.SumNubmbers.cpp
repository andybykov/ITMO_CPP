// Применение рекурсивной функции. Задание 1. Сумма чисел
//
#include <iostream>

// Сумма от 1 до n 
int addNumders(int n)
{
    if (n == 1) return 1; // выход из рекурсии
    else return (n + addNumders(n - 1));
}

// Сумма от m до n 
int addNumbers(int m, int n) {
    if (m == n) return m;            // базовый случай
    return n + addNumbers(m, n - 1); // прибавляем последнее число и идем вниз
}

int main() {
    setlocale(LC_ALL, "RU");

    int n;
    std::cout << "Введите n: ";
    std::cin >> n;
    std::cout << "Сумма от 1 до " << n << " = " << addNumbers(n) << std::endl;


    int m, n2;
    std::cout << "Введите m и n (m <= n): ";
    std::cin >> m >> n2;
    if (m > n2) {
        std::cout << "Ошибка: m должно быть <= n\n";
        return 1;
    }
    std::cout << "Сумма от " << m << " до " << n2 << " = " << addNumbers(m, n2) << std::endl;

    return 0;
}