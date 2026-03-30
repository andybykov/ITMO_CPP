// Задание 2. Решение квадратного уравнения
//

#include <cmath>
#include <iostream>

using namespace std;

// Структура хранения корней 
struct QuadraticRoots {
	double root1;
	double root2;
	bool hasRoots;  // флаг наличия корней
};

// Функция решения уравнения
QuadraticRoots solveQuadratic(double a, double b, double c) {
	QuadraticRoots roots;

	double disc = b * b - 4 * a * c;
	if (disc < 0) {
		roots.hasRoots = false;
		return roots; // нет корней
	}
	else roots.hasRoots = true;

	double sqrt_disc = sqrt(disc);

	roots.root1 = (-b + sqrt_disc) / (2 * a);
	roots.root2 = (-b - sqrt_disc) / (2 * a);

	return roots;
}

int main() {
	setlocale(LC_ALL, "RU");

	double a, b, c;
	cout << "Введите коэффициенты a, b, c: ";
	cin >> a >> b >> c;

	QuadraticRoots roots = solveQuadratic(a, b, c);
	if (roots.hasRoots) {
		cout << "Корни уравнения:\n";
		cout << "x1 = " << roots.root1 << "\n";
		cout << "x2 = " << roots.root2 << "\n";

	}
	else
	{
		cout << "Нет корней\n";
	}

	return 0;
}