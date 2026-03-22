// Упражнение 3. Использование указателя на функцию

#include <iostream>

using namespace std;

void show_array(const int[], const int);

bool from_min(const int, const int);

bool from_max(const int, const int);

void bubble_sort(int[], const int, bool (*)(int, int));

int main()
{
	setlocale(LC_ALL, "RU");

	const int N = 10;
	int my_choose = 0;
	int A[N] = { 9,8,7,6,1,2,3,5,4,9 };

	// массив указателей на функции
	bool (*from_f[2])(int, int) = { from_min, from_max };

	cout << "1. Сортировать по возрастанию\n";
	cout << "2. Сортировать по убыванию\n";
	cin >> my_choose;

	if (my_choose < 1 || my_choose > 2) {
		cout << "Неизвестная операция\n";
		return 1;
	}

	cout << "Исходные данные:\n";
	show_array(A, N);

	//вызов через массив указателей
	bubble_sort(A, N, (*from_f[my_choose - 1]));

	cout << "После сортировки:\n";
	show_array(A, N);

	return 0;
}


// отображение массива
void show_array(const int Arr[], const int N)
{
	cout << "Array[] = { ";
	for (int i = 0; i < N; i++)
		if (i != N - 1) {
			cout << Arr[i] << ", ";
		}
		else
		{
			cout << Arr[i] << " ";
		}
	cout << "}\n";
}

// направление сравнения
bool from_min(const int a, const int b)
{
	return a > b;
}

bool from_max(const int a, const int b)
{
	return a < b;
}

// пузырьковая сортировка
void bubble_sort(int Arr[], const int N, bool (*compare)(int a, int b))
{
	for (int i = 1;i < N;i++)
	{
		for (int j = 0;j < N - 1;j++)
		{
			// вызов функции по адресу
			if ((*compare)(Arr[j], Arr[j + 1])) {
				swap(Arr[j], Arr[j + 1]);

			}
		}
	}
}