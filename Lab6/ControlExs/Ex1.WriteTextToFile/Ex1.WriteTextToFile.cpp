// Задание 1. Запись текста в файл
/*
* Требуется написать программу для записи небольшого стихотворения с
* клавиатуры в текстовый файл
*/

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "Enter the verses line by line\n";
    std::cout << "If you are finished, enter: /e\n";

    std::string line, message;
    while (std::getline(std::cin, line)) { //читаем всю строку
        if (line == "/e") break;
        message.append(line).push_back('\n');
    }

    std::cout << "\nYour verse:\n" << message;

    std::ofstream out;          // поток для записи
    out.open("my-verse.txt", std::ios::out);   // открываем файл для записи
    if (out.is_open())
    {
        out << message;
    }
    out.close();
    std::cout << "File has been written" << std::endl;
    return 0;
}