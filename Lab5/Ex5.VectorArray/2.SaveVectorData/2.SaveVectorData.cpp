// Задание 2. Сохранение набора результатов неизвестного размера

#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    srand(time(NULL));

    int a, b, c;
    int k = 0;
    const int n = 6;            // количество вопросов
    int mas[n];                 // массив для хранения всех ответов

    vector<int> v1;             // правильные ответы
    vector<int> v2;             // неправильные ответы

    for (int i = 0; i < n; ++i) {
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        cout << a << " * " << b << " = ";
        cin >> c;
        mas[i] = c;

        if (a * b != c) {
            k++;
            v2.push_back(c);    
            cout << "Error! ";
            cout << a << " * " << b << " = " << a * b << endl;
        }
        else {
            v1.push_back(c);    
        }
    }

    // Вывод всех ответов из массива
    cout << "\nAll: ";
    for (int i = 0; i < n; ++i) {
        cout << mas[i] << " ";
    }

    // Вывод правильных ответов
    cout << "\nGood: ";
    for (size_t i = 0; i < v1.size(); ++i) {
        cout << v1[i] << " ";
    }

    // Вывод неправильных ответов
    cout << "\nBad: ";
    for (size_t i = 0; i < v2.size(); ++i) {
        cout << v2[i] << " ";
    }

    cout << endl;
    cout << "Count error: " << k << endl;
    return 0;
}