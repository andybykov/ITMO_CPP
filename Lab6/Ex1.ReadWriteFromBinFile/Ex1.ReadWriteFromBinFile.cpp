// Упражнение 1. Запись и чтение данных из бинарного файла

#include <cstdlib>
#include <fstream>   // std::ofstream / std::ifstream
#include <iostream>

int main()
{
	double sum = 0;
	int const N = 100;
	double nums[N];

	for (int i = 0; i < N; i++)
	{
		nums[i] = (rand() % 100);
		std::cout << nums[i] << std::endl;
	}
	// поток для записи
	std::ofstream out("test", std::ios::out | std::ios::binary);
	if (!out) {
		std::cout << "Файл открыть невозможно\n";
		return 1;
	}

	out.write((char*)nums, sizeof(nums)); // пишем бинарные данные

	out.close();

	// открытие файла
	std::ifstream in("test", std::ios::in | std::ios::binary);
	if (!in) {
		std::cout << "Файл открыть невозможно";
		return 1;
	}

	in.read((char*)&nums, sizeof(nums)); // читаем в nums 

	int k = sizeof(nums) / sizeof(double);

	// подстчет суммы
	for (int i = 0; i < k; i++)
	{
		sum = sum + nums[i];
		std::cout << nums[i] << ' ';
	}
	std::cout << "\nsum = " << sum << std::endl;

	in.close();
}
