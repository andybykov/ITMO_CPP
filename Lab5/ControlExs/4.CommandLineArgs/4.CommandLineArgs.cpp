// Задание 4. Передача параметров в программу


#include <iostream>
#include <cstring> // strncmp
#include <cstdlib> // atoi

using namespace std;



int main(int argc, char* argv[]) {
    
    setlocale(LC_ALL, "RU");

    // Проверка числа параметров
    if (argc < 4) {
        cout << "Ошибка: недостаточно параметров!" << endl;
        cout << "Использование: " << argv[0] << " [-a|-m] <число1> <число2>" << endl;
        return 1;
    }

    // Проверка второго параметра
    if (strcmp(argv[1], "-a") != 0 && strcmp(argv[1], "-m") != 0) {
        cout << "Ошибка: неверный флаг!" << endl;
        cout << "Использование: " << argv[0] << " [-a|-m] <число1> <число2>" << endl;
        cout << "Допустимые флаги: -a (сумма) или -m (произведение)" << endl;
        return 1;
    }

    // Конвертация в int
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);


    // Вычисления
    if (strcmp(argv[1], "-a") == 0) {
        int sum = num1 + num2;
        cout << "Сумма: " << num1 << " + " << num2 << " = " << sum << endl;
    }
    else if (strcmp(argv[1], "-m") == 0) {
        int product = num1 * num2;
        cout << "Произведение: " << num1 << " * " << num2 << " = " << product << endl;
    }

    return 0;
}