// Задание 1. Структура Time
//

#include <iostream>

using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;

    // метод для перевода в секунды
    long long toSeconds() const {
        return hours * 3600LL + minutes * 60 + seconds;
    }

    // сложение интервалов
    Time add(const Time& other) const {
        long long totalSec = toSeconds() + other.toSeconds();
        return Time::fromSeconds(totalSec);
    }

    // вычитание интервалов
    Time subtract(const Time& other) const {
        long long diffSec = toSeconds() - other.toSeconds();
        return Time::fromSeconds(diffSec);
    }

    // статический метод для создания Time из секунд 
    
    static Time fromSeconds(long long totalSec) {

        int sign = 1;
        if (totalSec < 0) {
            sign = -1;
            totalSec = -totalSec;
        }
        int hours = totalSec / 3600;
        totalSec %= 3600;
        int minutes = totalSec / 60;
        int seconds = totalSec % 60;
        if (sign == -1) {
            hours = -hours;

        }
        return { hours, minutes, seconds };
    }
    

    // вывод времени
    void print() const {
        cout << hours << "ч " << minutes << "м " << seconds << "с";
    }
};

// функция ввода времени
Time inputTime() {
    int h, m, s;
    cout << "Введите часы: ";
    cin >> h;
    cout << "Введите минуты: ";
    cin >> m;
    cout << "Введите секунды: ";
    cin >> s;

    return { h, m, s };
}

int main() {
    setlocale(LC_ALL, "RU");

    cout << "Введите первое время: " << endl;
    Time t1 = inputTime();

    cout << "Время в секундах: " << t1.toSeconds() << endl;

    cout << "\nВведите второе время: "<< endl;
    Time t2 = inputTime();

    Time sum = t1.add(t2);
    Time diff = t1.subtract(t2);

    cout << "\nСумма интервалов: ";
    sum.print();
    cout << endl;

    cout << "Разность времени: ";
    diff.print();
    cout << endl;

    return 0;
}