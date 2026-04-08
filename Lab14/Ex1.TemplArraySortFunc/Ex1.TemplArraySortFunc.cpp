// Упражнение 1. Создание шаблонной функции сортировки массива
//

#include <iostream>

// функция сортировки
void sorting(int arr[], int size) {
	int j = 0;
	for (int i = 0; i < size; i++) {
		int x = arr[i];
		for (j = i - 1; j >= 0 && x < arr[j]; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = x;
	}
}

// шаблон функции сортировки
template<class T>
void sorting(T arr[], int size) {
	int j = 0;
	for (int i = 0; i < size; i++) {
		T x = arr[i];
		for (j = i - 1; j >= 0 && x < arr[j]; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = x;
	}
}

// шаблон функции вывода массива
template <typename T, std::size_t N> // N известен из контекста
void printArray(const T(&array)[N])   
{
	for (const auto& elem : array) {
		std::cout << elem << "; ";
	}		
	std::cout << '\n';
}
int main()
{
	int arr[] = { 9,3,17,6,5,4,31,2,12,35 };
	double arrd[] = { 2.1, 2.3,1.7,6.6,5.3,2.44,3.1,2.4,1.2 };
	char arrc[] = "Hello, word!";

	int k1 = sizeof(arr) / sizeof(arr[0]);
	int k2 = sizeof(arrd) / sizeof(arrd[0]);
	int k3 = sizeof(arrc) / sizeof(arrc[0]) - '\0';


	sorting(arr, k1);
	printArray(arr);

	sorting(arrd, k2);
	printArray(arrd);

	sorting(arrc, k3);
	printArray(arrc);

}
