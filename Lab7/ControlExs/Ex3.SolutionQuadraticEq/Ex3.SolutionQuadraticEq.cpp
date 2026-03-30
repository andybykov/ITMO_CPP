// Задание 3. Решение квадратного уравнения
//

#include <iostream>
#include <tuple>
#include <cmath>

using namespace std;

//  возвращает кортеж: корень1, корень2, флаг наличия корней
tuple<double, double, bool> solveQuadratic(double a, double b, double c) {
    double disc = b * b - 4 * a * c;
    if (disc < 0) {

        return make_tuple(0.0, 0.0, false);
    }
    double sqrt_disc = sqrt(disc);
    double x1 = (-b + sqrt_disc) / (2 * a);
    double x2 = (-b - sqrt_disc) / (2 * a);

    return make_tuple(x1, x2, true);
}

int main() {
    setlocale(LC_ALL, "RU");

    double a, b, c;
    cout << "Введите коэффициенты a, b, c: ";
    cin >> a >> b >> c;

    auto result = solveQuadratic(a, b, c);

    double x1 = get<0>(result);
    double x2 = get<1>(result);
    bool hasRoots = get<2>(result);

    if (hasRoots) {
        cout << "Корни уравнения:\n";
        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2 << "\n";
    }
    else {
        cout << "Нет корней\n";
    }

    return 0;
}