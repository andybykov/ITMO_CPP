/* Рассет площади равностороннего треугольника, периметр которого известен*/
#include <iostream>
#include <cmath>
#include <fmt/format.h>
#include <fmt/color.h>


int main() {

    double perimeter;

    fmt::print(fg(fmt::color::white_smoke),"Введите периметр равностороннего треугольника: ");
    std::cin >> perimeter;

    if (perimeter <= 0) {
        fmt::print(fg(fmt::color::red), "Периметр должен быть положительным числом!");
        return 1;
    }

    double side = perimeter / 3.0;
    double semiperimeter = perimeter / 2.0;

    double area = sqrt(semiperimeter * pow((semiperimeter - side), 3));



    fmt::print("\n------------------------\n");
    fmt::print("  {:^8} | {:^8}\n", "Сторона", "Площадь"); // выравнивание по центру
    fmt::print("------------------------\n");
    fmt::print("  {:^8.2f} | {:^8.2f}\n", side, area); // выравнивание по центру, два знака после запятой
    fmt::print("------------------------\n");

    return 0;
}