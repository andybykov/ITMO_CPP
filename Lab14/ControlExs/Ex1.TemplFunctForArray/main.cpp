// Задание 1. Шаблонная функция обработки массива
//

#include <iostream>

// Шаблон функции, возвращающей среднее арифметическое элементов массива
template <typename T>
double arrayAverage(const T* arr, int size) {
    if (size <= 0) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += static_cast<double>(arr[i]);
    }

    return sum / size;
}

int main() {
    // int
    int intArr[] = { 1, 2, 3, 4, 5 };
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    std::cout << "int array average: " << arrayAverage(intArr, intSize) << std::endl;

    // long
    long longArr[] = { 10L, 20L, 30L, 40L, 50L };
    int longSize = sizeof(longArr) / sizeof(longArr[0]);
    std::cout << "long array average: " << arrayAverage(longArr, longSize) << std::endl;

    // double
    double doubleArr[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    std::cout << "double array average: " << arrayAverage(doubleArr, doubleSize) << std::endl;

    // char 
    char charArr[] = { 'A', 'B', 'C', 'D', 'E' };
    int charSize = sizeof(charArr) / sizeof(charArr[0]);
    std::cout << "char array average: " << arrayAverage(charArr, charSize) << std::endl;

    return 0;
}