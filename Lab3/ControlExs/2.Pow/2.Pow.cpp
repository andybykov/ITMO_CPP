// Задание 2. Применение итерации реализации функции

#include <cmath>
#include <iomanip>
#include <iostream>

// функция pow
double cubeRootPow(double a) {
	return std::pow(a, 1.0 / 3.0);
}

// итерационный метод
	// a для кого ищем кубический корень
	// x  с чего начинаем вычислять
	// n Количество итераций
double cubeRootIter(double a, double x = 1.0, int n = 10) {

	for (int i = 0; i < n; ++i) {
		// x_{n+1} = (1/3) * (a / x_n^2 + 2 * x_n)
		x = (1.0 / 3.0) * (a / (x * x) + 2.0 * x);
		//std::cout << "x: " << x << "\n";
	}

	return x;
}

int main() {
	setlocale(LC_ALL, "RU");
	std::cout << std::fixed << std::setprecision(12);

	double a;
	std::cout << "Вычисление кубического корня\n";
	std::cout << "Введите число: ";
	std::cin >> a;

	double resPow = cubeRootPow(a);
	double resIter = cubeRootIter(a);

	std::cout << "pow:   " << resPow << std::endl;
	std::cout << "итерация: " << resIter << std::endl;


	return 0;
}