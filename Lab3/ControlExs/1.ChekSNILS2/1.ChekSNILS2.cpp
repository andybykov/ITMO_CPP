//Задание 1. Проверка номера СНИЛС

#include <iostream>
#include <string>
#include <cctype>

bool validateSnils(const std::string& input) {
    std::string clean;  // только цифры

    // Очистка и проверка допустимых символов
    for (size_t i = 0; i < input.length(); ++i) {
        char ch = input[i];
        if (ch == ' ' || ch == '-') {
            continue;                 
        }
        if (std::isdigit(ch)) {      
            clean.push_back(ch);
        }
        else {                      
            return false;
        }
    }

    // 11 цифр
    if (clean.length() != 11) {
        return false;
    }

    // Контрольные цифры 
    int control = (clean[9] - '0') * 10 + (clean[10] - '0');

    // Вычисление контрольной суммы
    long long sum = 0;
    for (int i = 0; i < 9; ++i) {
        int digit = clean[i] - '0';
        sum += digit * (9 - i);       
    }

    // Провкрка суммы 
    if (sum == 100 || sum == 101) {
        sum = 0;
    }
    else if (sum > 101) {
        sum %= 101;
        if (sum == 100 || sum == 101) {
            sum = 0;
        }
    }

    return sum == control;
}

int main() {
    setlocale(LC_ALL, "RU");

    std::string snils;
    std::cout << "Введите СНИЛС: ";
    std::getline(std::cin, snils);

    bool result = validateSnils(snils);
    std::cout << std::boolalpha << result << std::endl;

    return 0;
}