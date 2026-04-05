// Задание 1. Безопасная реализация класса Triangle
//

/*
* Реализовать генерацию исключительной ситуации при попытке задать стороны
недопустимой длины – если хотя бы одна из сторон имеет длину большую, чем
сумма двух других сторон
*/

#include <cmath>
#include <iostream>
#include <stdexcept>


// Класс треугольника
class Triangle {
public:
	// конструктор
	Triangle(double a, double b, double c) : _a(a), _b(b), _c(c) {
		if (!_chekSides()) {
			throw std::invalid_argument("Invalid side length!");
		}
	}

	//  вычисляет площадь треугольника по трем сторонам
	double calculateArea() const {
		double perimeter = _a + _b + _c; // рассчитываем периметир
		double p = perimeter / 2; // рассчитываем полупериметр 

		return sqrt(p * ((p - _a) * (p - _b) * (p - _c)));
	}

private:
	// стороны
	double _a, _b, _c;

	// проверка если хотя бы одна из сторон имеет длину большую, чем сумма двух других 
	bool _chekSides() const {

		return ((_a + _b >= _c) && (_b + _c >= _a) && (_a + _c >= _b));
	}

};

int main()
{
	try {
		Triangle tri(3, 4, 50);
		auto area = tri.calculateArea();
		std::cout << "Triangle area = " << area << "\n";
	}
	catch (const std::exception& e)
	{
		//обработка исключения
		std::cout << e.what() << std::endl;
	}
}
