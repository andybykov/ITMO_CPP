// Упражнение 5. Шаблонная функция Factorial с ограничением типов (C++20)
#include <iostream>
#include <concepts>

// Функция факториала
// доступна только для целочисленных типов  std::integral
template <std::integral T>
T Factorial(T n) {
    if (n <= 1) return 1;
    return n * Factorial(n - 1);
}

int main() {

    int x = 5;
    std::cout << "Factorial(" << x << ") = " << Factorial(x) << std::endl;

    return 0;
}