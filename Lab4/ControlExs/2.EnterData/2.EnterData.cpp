// Задание 2. Реализация ввода данных

#include <iostream>
using namespace std;

// ВВод данных с проверкой корректности
// Возвращает true, если ввод успешен, false - если ввод некорректен
bool Input(int& a, int& b) {
    cout << "Введите два целых числа: ";
    cin >> a >> b;

    // если ввели не int
    if (cin.fail()) {
        return false;
    }

    return true;
}

int main() {

    setlocale(LC_ALL, "RU");

    int a, b;

    if (!Input(a, b)) {
        cerr << "error" << endl;
        return 1;
    }

    int s = a + b;
    cout << "Сумма: " << s << endl;

    return 0;
}