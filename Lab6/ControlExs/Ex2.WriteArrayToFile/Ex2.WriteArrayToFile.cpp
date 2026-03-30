/*
* Задание 2. Сохранение данных в текстовый файл
* 
* В решении упражнения 2 занятия 5 создайте текстовый файл и запишите в него
* два массива: исходный и отсортированный.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>

void fillArrayRandom(int*, const int);
void sortArray(int*, const int);
void printArray(int*, const int);
void writeToFile(int*, const int, std::string, std::string);


int main()
{
	const int N = 10;
	int a[N];

	fillArrayRandom(a, N);
	std::cout << "Random array before sorting:" << std::endl;
	printArray(a, N);
	writeToFile(a, N, "arrays.txt", "Random array before sorting:");

	sortArray(a, N);
	std::cout << "Array after sorting:" << std::endl;
	printArray(a, N);
	writeToFile(a, N, "arrays.txt", "Array after sorting:");

	

    return 0;
}

void sortArray(int* array, const int N) {

	int min = 0; // для записи минимального значения
	int buf = 0; // для обмена значениями

	// selection sort
	for (int i = 0; i < N; i++)
	{
		min = i; // номер текущей ячейки, как ячейки с минимальным значением
		// в цикле найдем реальный номер ячейки с минимальным значением
		for (int j = i + 1; j < N; j++)
			min = (array[j] < array[min]) ? j : min;
		// перестановка этого элемента, поменяв его местами с текущим
		if (i != min)
		{
			buf = array[i];
			array[i] = array[min];
			array[min] = buf;
		}
	}
}

// Заполнение массива случайными значениями
void fillArrayRandom(int* arr, const int N)
{
	for (int i = 0; i < N; ++i)
		arr[i] = std::rand() % 100;
}

// Распечатка массива
void printArray(int* arr, const int N) {
	for (auto i = 0; i < N; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

//запись в файл
void writeToFile(int* arr, const int N, std::string name, std::string message) {

	//std::ofstream out;          // поток для записи
	std::ofstream out(name, std::ios::app); // открываем файл для дописывания
	if (!out.is_open()) {
		std::cerr << "Error opening file: " << name << std::endl;
		return;
	}
	if (out.is_open())
	{
		out << message << "\n";
		for (auto i = 0; i < N; i++) {
			out << arr[i] << " ";
		}
		out << "\n";
	}
	out.close();
	std::cout << "File "  << name << " has been written!\n" << std::endl;
}