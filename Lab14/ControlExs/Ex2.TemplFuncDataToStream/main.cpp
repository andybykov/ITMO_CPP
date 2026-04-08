// Задание 2. Шаблонная функция вывода данных в поток

#include <iostream>
#include <vector>

// Шаблонная функция Print
// Параметры: контейнер (по константной ссылке), строка-разделитель
template <typename Container>
void print(const Container& container, const std::string& separator) {
    bool first = true; // флаг первого элемента
    for (const auto& elem : container) {
        if (!first) { // перед container[0] не печатаем разделитель
            std::cout << separator; // Перед элементом
        }
        first = false;
        std::cout << elem;
    }
    std::cout << '\n';
}

int main() {
    // int
    std::vector<int> data = { 1, 2, 3 };
    print(data, ", "); 

    // double
    std::vector<double> doubles = { 1.1, 2.2, 3.3 };
    print(doubles, "; ");

    return 0;
}