// Задание 3. Реализация алгоритмов поиска методом транспозиции

#include <iostream>
#include <vector>

// Функция поиска элемента с методом транспозиции
// Возвращает индекс элемента если найден, иначе -1
int searchWithTransposition(std::vector<int>& arr, int key) {
    for (int i = 0; i < (int)arr.size(); ++i) {
        if (arr[i] == key) {
            if (i > 0) {
                std::swap(arr[i], arr[i - 1]);
                return i - 1;
            }
            return i;
        }
    }
    return -1;
}


int main() {

    setlocale(LC_ALL, "RU");

    // исходный вектор
    std::vector<int> data = { 3, 5, 2, 7, 4, 9, 1 };

    std::cout << "Исходный массив: ";
    // вывод иходного массива
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int key; // искомый элемент


    std::cout << "Введите элемент для поиска: ";
    std::cin >> key;


    int index = searchWithTransposition(data, key);
    // элемент найден
    if (index != -1) {

        std::cout << "Элемент найден и перемещен на позицию: " << index << std::endl;
        std::cout << "Обновленный массив: ";
        // массив после транспозиции
        for (int num : data) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    else {
        //  элемент не найден
        std::cout << "Элемент не найден" << std::endl;
    }

    return 0; 
}