// Задание 2. Алгоритм Евклида

#include <iostream>

// Рекурсивная функция НОД
int gcd(int m, int n) {
    if (n == 0) return m;           
    return gcd(n, m % n);        
}

int main() {
    setlocale(LC_ALL, "RU");
    int a, b;
    std::cout << "Введите два целых числа: ";
    std::cin >> a >> b;

    int result = gcd(a, b);

    std::cout << "НОД = " << result << std::endl;
    return 0;
}