// Стрельба по мишеням

/*
Требуется разработать программу, имитирующую стрельбу по мишени.
Пользователь вводит данные о выстреле в виде пары чисел – координат x и y заранее известное количество раз
*/

#include <iostream>

// Функция расчета очков в зависимости от зоны попадания
double calculate_points(double x, double y)
{
	double totalPoints = 0.0; // очки тут

	if (y > 0.0) // Только верхняя полуплоскость
	{
		if (x * x + y * y <= 1.0) // Центральная зона (радиус 1)
		{
			totalPoints = 10.0;
		}
		else if (x * x + y * y <= 4) // Средняя зона (радиус 2)
		{
			totalPoints = 5.0;
		}
		else if (x * x + y * y <= 9) // Внешняя зона (радиус 3)
		{
			totalPoints = 1.0;
		}
		else // За пределами мишени
		{
			totalPoints = 0.0;
		}
	}
	else // Нижняя полуплоскость
	{
		totalPoints = 0.0;
	}
	return totalPoints;
}

// Функция вывода промежуточных результатов
void print_result(double points)
{
	if (points == 0.0)
	{
		std::cout << "Результат: Промах" << std::endl;
	}
	else if (points == 1.0)
	{
		std::cout << "Результат: Зона 3 (1 очко)" << std::endl;
	}
	else if (points == 5.0)
	{
		std::cout << "Результат: Зона 2 (5 очков)" << std::endl;
	}
	else if (points == 10.0)
	{
		std::cout << "Результат: Зона 1 (10 очков)" << std::endl;
	}
}

// Функция определения уровня стрелка
void print_level(double total_score, int num_shoot)
{
	if (num_shoot == 0) return; // защита от деления на ноль

	double average_score = total_score / num_shoot; // среднее количество очков за выстрел

	std::cout << "\n=== Результаты стрельбы ===" << std::endl;
	std::cout << "Всего выстрелов: " << num_shoot << std::endl;
	std::cout << "Всего очков: " << total_score << std::endl;
	std::cout << "Средний результат: " << average_score << " очков за выстрел" << std::endl;

	// Определение уровня стрелка по среднему результату
	std::cout << "Уровень стрелка: ";

	if (average_score >= 8.0)
	{
		std::cout << "СНАЙПЕР!" << std::endl;
	}
	else if (average_score >= 5.0)
	{
		std::cout << "Бывалый" << std::endl;
	}
	else if (average_score >= 3.0)
	{
		std::cout << "Любитель" << std::endl;
	}
	else if (average_score >= 1.0)
	{
		std::cout << "Новичок" << std::endl;
	}
	else
	{
		std::cout << "Нужно больше тренироваться!" << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "RU");

	// Координаты выстрелов
	double x = 0;
	double y = 0;

	double total_score = 0;    // Общий счет очков
	int num_shoot = 0;         // Текущая попытка
	//const int MAX_SHOTS = 3;  // Количество попыток
	const int STOP_SCORES = 50; // Необходимое количество очков для завершеения

	std::cout << "Стрельба по мишени. Нужно набрать " << STOP_SCORES << " очков" << std::endl;

	while (total_score <= STOP_SCORES)
	{
		//std::cout << "Попытка: " << numShoot + 1 << std::endl;
		std::cout << "Введите координаты x y: ";
		std::cin >> x >> y;


		//double temp = calculate_points(x, y); // временная переменная для хранения промежуточных результатов
		//print_result(temp);
		total_score += calculate_points(x, y);
		num_shoot++; // увеличиваем попытку
	}
	print_level(total_score, num_shoot);

	return 0;
}
