// Упражнение 4. Реализация динамического массива

#include <iostream>

using namespace std;

void show_array(const int*, const int);

bool from_min(const int, const int);

bool from_max(const int, const int);

void bubble_sort(int*, const int, bool (*)(int, int));


int main()
{
	setlocale(LC_ALL, "RU");

	int N = 0;  // размер массива 

	cout << "Введите размер массива: ";
	cin >> N;

	if (N <= 0) {
		cout << "Ошибка: размер должен быть положительным!\n";
		return 1;
	}

	// создаем динамичский массив
	int* A = new int[N];  

	// заполнение массива
	cout << "Введите " << N << " элементов массива:\n";
	for (int i = 0; i < N; i++) {
		cout << "A[" << i << "] = ";
		cin >> A[i];      
	}

	// Массив указателей на функции сравнения
	bool (*from_f[2])(int, int) = { from_min, from_max };

	int my_choose = 0;
	cout << "\n1. Сортировать по возрастанию\n";
	cout << "2. Сортировать по убыванию\n";
	cout << "Ваш выбор: ";
	cin >> my_choose;

	if (my_choose < 1 || my_choose > 2) {
		cout << "Неизвестная операция\n";
		delete[] A; // освобождение памяти
		return 1;
	}

	cout << "\nИсходные данные:\n";
	show_array(A, N);

	// сортировка
	bubble_sort(A, N, from_f[my_choose - 1]);

	cout << "После сортировки:\n";
	show_array(A, N);

	// освобождение памяти
	delete[] A;        
	A = nullptr;        

	return 0;
}

void show_array(const int* Arr, const int N)
{
	cout << "Array[] = { ";
	for (int i = 0; i < N; i++) {
		cout << Arr[i];
		if (i != N - 1) cout << ", ";
	}
	cout << " }\n";
}

bool from_min(const int a, const int b)
{
	return a > b;
}

bool from_max(const int a, const int b)
{
	return a < b;
}

void bubble_sort(int* Arr, const int N, bool (*compare)(int, int))
{
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if ((*compare)(Arr[j], Arr[j + 1]))
				swap(Arr[j], Arr[j + 1]);
		}
	}
}
