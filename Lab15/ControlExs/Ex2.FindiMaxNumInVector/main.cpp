// Задание 2. Поиск максимального чётного числа в векторе
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

// возвращает наибольшее четное число в векторе
int FindMaxEven(const std::vector<int>& vec) {
    // первый четный элемент
    auto it = std::find_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    if (it == vec.end()) {
        throw std::runtime_error("No even numbers in vector");
    }

    // максимум среди четных
    auto max_it = std::max_element(it, vec.end(),
        [](int a, int b) {            
            return a < b;
        }
    );
    return *max_it;
}

int main() {
    try {
        std::vector<int> v1 = { 1, 3, 5, 7, 8, 10, 4, 2 };
        std::cout << "Max even in v1: " << FindMaxEven(v1) << std::endl; 

        std::vector<int> v2 = { 1, 3, 5, 7 };
        std::cout << "Max even in v2: " << FindMaxEven(v2) << std::endl; // нет четных, исключение
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}