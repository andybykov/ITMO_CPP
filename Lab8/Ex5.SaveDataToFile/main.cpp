// Упражнение 5. Сохранение данных в файл
//
/* main.cpp */
#include <iostream>
#include <string>
#include <Windows.h>
#include "student.h"

using namespace std;

int main()
{
	string name;
	string last_name;

	SetConsoleOutputCP(CP_UTF8);   // вывод в UTF‑8
	SetConsoleCP(CP_UTF8);         // ввод в UTF‑8

	// Ввод имени с клавиатуры
	cout << "Имя: ";
	getline(cin, name);

	// Ввод фамилии
	cout << "Фамилия: ";
	getline(cin, last_name);

	// Передача параметров конструктору
	Student* student02 = new Student(name, last_name);

	// Оценки
	int scores[5];
	// Сумма всех оценок
	int sum = 0;

	// Ввод промежуточных оценок
	for (int i = 0; i < 5; ++i) {
		cout << "Балл " << i + 1 << ": ";
		cin >> scores[i];
		// суммирование
		sum += scores[i];
	}

	// Сохраняем промежуточные оценки в объект класса Student
	student02->set_scores(scores);

	// Считаем средний балл
	double average_score = sum / 5.0;

	// Сохраняем средний балл в объект класса Student
	student02->set_average_score(average_score);

	// Выводим данные по студенту
	cout << "Средний балл у студента " << student02->get_name() << " "
		<< student02->get_last_name() << " составляет: "
		<< student02->get_average_score() << endl;

	// Удаление объекта student из памяти
	delete student02;

	return 0;
}