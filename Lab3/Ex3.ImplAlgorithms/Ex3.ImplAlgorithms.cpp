// Упражнение 3. Реализация сложных алгоритмов с помощью функций
//

#include <iostream>
#include <cmath>
#include <iomanip>

// функция реализующая алгоритм бинарного поиска для нахождения значения корня степени n 
long double firBinSearch(double a, int n)
{
    double L = 0;
    double R = a;
    while (R - L > 1e-10)
    {
        double M = (L + R) / 2;
        if (pow(M, n) < a)
        {
            L = M;
        }
        else
        {
            R = M;
        }
    }
    return R;
}

int main()
{
    setlocale(LC_ALL, "RU");

    double a;
    int n;
    
    std::cout << "Введите число a: ";
    std::cin >> a;
    std::cout << "Введите степень n: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Степень должна быть положительной!" << std::endl;
        return 1;
    }

    long double result = firBinSearch(a, n);

    std::cout << std::fixed << std::setprecision(6) << result << "\n";
    return 0;
}