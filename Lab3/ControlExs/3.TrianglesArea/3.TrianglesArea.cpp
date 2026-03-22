//Задание 3. Работа с различными треугольниками

#include <cmath>
#include <iostream>


// равносторонний 
double triangleArea(double side) {
	if (side <= 0) return 1;
	return (side * side * sqrt(3.0)) / 4.0;
}

// разносторонний
double triangleArea(double a, double b, double c) {
	// Проверка существования треугольника
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a + b <= c || a + c <= b || b + c <= a) return 1;

	double p = (a + b + c) / 2.0;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {

	setlocale(LC_ALL, "RU");

	int choice;

	std::cout << "Расчет площади треугольника\n";
	std::cout << "\tВыберите тип:\n";

	std::cout << ("1 - Равносторонний треугольник\n");
	std::cout << ("2 - Разносторонний треугольник\n");

	while (1)
	{
		std::cout << ("Выберите тип: ");
		std::cin >> choice;

		// равносторонний
		if (choice == 1) {
			double side;
			std::cout << ("\nВведите сторону: ");
			std::cin >> side;

			double area = triangleArea(side);

			if (area < 0) {
				std::cout << "Ошибка: сторона должна быть > 0\n";
				return 1;
			}

			std::cout << "\tПлощадь: " << area << std::endl;
			break;
		}

		// разносторонний
		if (choice == 2) {
			double a, b, c;
			std::cout << ("Введите стороны: ");
			std::cin >> a >> b >> c;

			double area = triangleArea(a, b, c);

			if (area < 0) {
				std::cout << "Ошибка: треугольник с такими сторонами не существует!\n";
				return 1;
			}


			std::cout << "\tПлощадь: " << area << std::endl;;
			break;
		}
	}

	return 0;
}