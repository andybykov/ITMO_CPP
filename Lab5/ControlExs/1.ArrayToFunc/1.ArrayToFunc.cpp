// Задание 1. Передача массива в функцию

#include <iostream>
using namespace std;

// Функция обработки массива
void processArray(int size, int arr[]) {
    // Сумма элементов
    int s = 0;
    for (int i = 0; i < size; i++) {
        s += arr[i];
    }
    cout << "Сумма всех элементов массива: " << s << endl;

    // Среднее значение
    double avg = static_cast<double>(s) / size;
    cout << "Среднее значение: " << avg << endl;

    // Сумма отрицательных элементов
    int sumNegative = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0)
            sumNegative += arr[i];
    }
    cout << "Сумма отрицательных: " << sumNegative << endl;

    // Сумма положительных элементов
    int sumPositive = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0)
            sumPositive += arr[i];
    }
    cout << "Сумма положительных: " << sumPositive << endl;

    // Сумма элементов с нечетными индексами
    int sumOddIndex = 0;
    for (int i = 1; i < size; i += 2) {
        sumOddIndex += arr[i];
    }
    cout << "Сумма элементов с нечетными индексами: " << sumOddIndex << endl;

    // Сумма элементов с четными индексами
    int sumEvenIndex = 0;
    for (int i = 0; i < size; i += 2) {
        sumEvenIndex += arr[i];
    }
    cout << "Сумма элементов с четными индексами: " << sumEvenIndex << endl;

    // Максимальный и минимальный элементы + индексы
    int maxVal = arr[0];
    int minVal = arr[0];
    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
    }

    cout << "Максимум: arr[" << maxIndex << "] = " << maxVal << endl;
    cout << "Минимум: arr[" << minIndex << "] = " << minVal << endl;

    // Произведение элементов между максимумом и минимумом
    int product = 1;
    bool found = false;

    // Начало и конец диапазона
    int start = (minIndex < maxIndex) ? minIndex : maxIndex;
    int end = (minIndex < maxIndex) ? maxIndex : minIndex;


    for (int i = start + 1; i < end; i++) {
        product *= arr[i];
        found = true;
    }

    if (found)
        cout << "Произведение между min и max: " << product << endl;
    else
        cout << "Между min и max нет элементов" << endl;
}

// сортировка массива 
void sortArray(int size, int arr[]) {
    int min = 0; 
    int buf = 0; 

    // selection sort
    for (int i = 0; i < size; i++) {
        min = i; 
        
        for (int j = i + 1; j < size; j++)
            min = (arr[j] < arr[min]) ? j : min;
       
        if (i != min) {
            buf = arr[i];
            arr[i] = arr[min];
            arr[min] = buf;
        }
    }
}

//  вывода массива
void printArray(int size, int arr[]) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    setlocale(LC_ALL, "RU");

    const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };

    cout << "Исходный массив: ";
    printArray(N, a);

    cout << "\nОбработка массива:" << endl;
    processArray(N, a);

    cout << "\nСортировка массива:" << endl;
    sortArray(N, a);

    cout << "Отсортированный массив: ";
    printArray(N, a);

    return 0;
}
