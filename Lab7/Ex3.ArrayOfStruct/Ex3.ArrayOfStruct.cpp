// Упражнение 3. Использование массива структур

#include <iostream>

using namespace std;

struct Distance
{
	int feet;
	double inches;

	void ShowDist()
	{
		cout << feet << "\'-" << inches << "\"\n";
	}
};

// сложение двух переменных типа Distance
Distance AddDist(const Distance& d1, const Distance& d2)
{
	Distance d;
	d.feet = d1.feet + d2.feet;
	d.inches = d1.inches + d2.inches;
	if (d.inches >= 12.0)
	{
		d.inches -= 12.0;
		d.feet++;
	}
	return d;
}

// ввод значений футов и дюймов
Distance InputDist()
{
	Distance d;
	cout << "\nВведите число футов: ";
	cin >> d.feet;
	cout << "Введите число дюймов: ";
	cin >> d.inches;
	return d;
}

// вывод информации о переменной структуры
void ShowDist(Distance d)
{
	cout << d.feet << "\'-" << d.inches << "\"\n";
}

int main()
{
	setlocale(LC_ALL, "RU");

	int n;
	cout << "Введите размер массива расстояний ";
	cin >> n;

	// динамичский массив типа Distacne
	Distance* masDist = new Distance[n];

	// Ввод значений для каждого элемента
	for (int i = 0; i < n; i++)
	{
		masDist[i] = InputDist();
	}

	// Вывод
	for (int i = 0; i < n; i++)
	{
		ShowDist(masDist[i]);
	}

	Distance result;
	result.feet = 0;
	result.inches = 0;

	// сложение всех элементов
	for (auto i = 0; i < n; i++) {
		result = AddDist(result, masDist[i]);
	}

	cout << "Сумма всех растояний массива:" << endl;
	result.ShowDist();

	// освобождение памяти
	delete[] masDist;
}

