// Задание 1. Сохранение результатов в массиве

#include <ctime>
#include <iostream>

using namespace std;

int main() {
    srand(time(NULL));           // Инициализация генератора случайных чисел

    int a, b, c;                 
    int k = 0;                   // счетчик ошибок
    const int n = 6;            // количество вопросов
    int mas[n];                  // массив для хранения ответов

    for (int i = 0; i < n; ++i) {
        a = rand() % 10 + 1;     
        b = rand() % 10 + 1;     
        cout << a << " * " << b << " = ";
        cin >> c;                
        mas[i] = c;              // сохраняем ответ в массив

        if (a * b != c) {
            k++;                 
            cout << "Error! ";
            cout << a << " * " << b << " = " << a * b << endl;
        }
    }

    // Вывод всех ответов из массива
    cout << "\nAll: ";
    for (int i = 0; i < n; ++i) {
        cout << mas[i] << " ";  
    }
    cout << endl;

    cout << "Count error: " << k << endl;
    return 0;
}