// Задание 1. Вычисление корней квадратного уравнения

#include <iostream>
#include <cmath>

int Myroot(double a, double b, double c, double& x1, double& x2) {
    if (a == 0) {
        if (b == 0) return -1;
        x1 = -c / b;
        x2 = x1;
        return 0;
    }

    double d = b * b - 4 * a * c;

    if (d < 0) return -1;

    if (d == 0) {
        x1 = -b / (2 * a);
        x2 = x1;
        return 0;
    }

    double sd = sqrt(d);
    x1 = (-b + sd) / (2 * a);
    x2 = (-b - sd) / (2 * a);
    return 1;
}

int main() {
    
    setlocale(LC_ALL, "RU");

    std::cout << "Введите коэффициенты квадратного уравнения (a, b, c): " << std::endl;

    double a, b, c, x1, x2;

    std::cin >> a >> b >> c;

    int res = Myroot(a, b, c, x1, x2);

    if (res == 1)
        std::cout << "Корни уравнения x1 = " << x1 << ", x2 = " << x2 << std::endl;
    else if (res == 0)
        std::cout << "Корень уравнения один x1 = x2 = " << x1 << std::endl;
    else
        std::cout << "Корней уравнения нет" << std::endl;

    return 0;
}