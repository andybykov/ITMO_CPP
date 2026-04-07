#pragma once
#include <iostream>
#include <string>

using namespace std;

// Базовый класс
class Item {
private:
    string title;
    double price;

public:
    virtual void getdata() {
        cout << "\nВведите заголовок: ";
        cin.ignore();  // очистка буфера после предыдущего ввода
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
    }

    virtual void putdata() {
        cout << "\nЗаголовок: " << title;
        cout << "\nЦена: " << price;
    }

    virtual ~Item() {}  // виртуальный деструктор для корректного удаления
};