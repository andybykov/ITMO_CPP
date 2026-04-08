#pragma once /* Защита от двойного подключения заголовочного файла */
#include "IdCard.h"
#include <string>

using namespace std;

class Student
{
public:
    // Конструкторы
    Student(string, string, IdCard*);
    Student();
    Student(string name, string last_name);  // Конструктор без IdCard

    // Сеттеры и геттеры
    void set_name(string);
    string get_name();
    void set_last_name(string);
    string get_last_name();
    void set_scores(int[]);
    void set_average_score(double);
    double get_average_score();
    void display() const;
    void setIdCard(IdCard* c);
    IdCard getIdCard();

    // Дружественные операторы сравнения
    friend bool operator< (const Student&, const Student&);
    friend bool operator> (const Student&, const Student&);
    friend bool operator== (const Student&, const Student&);
    friend bool operator!= (const Student&, const Student&);

private:
    int scores[5];
    double average_score;
    string name;
    string last_name;
    IdCard* iCard;
};

// Функциональный объект для сравнения указателей на Student по содержимому
class compareStudent
{
public:
    bool operator() (const Student* ptrSt1, const Student* ptrSt2) const
    {
        return *ptrSt1 < *ptrSt2;
    }
};