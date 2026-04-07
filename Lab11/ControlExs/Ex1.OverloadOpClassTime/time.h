/* time.h */

#pragma once
#include <iomanip>
#include <iostream>

class Time
{
public:
    // Конструкторы
    Time();                                      
    Time(unsigned int hour, unsigned int min, unsigned int sec); // с проверкой диапазонов

    // Вывод 
    void print() const;

    // Геттеры
    unsigned int getHours()   const;
    unsigned int getMinutes() const;
    unsigned int getSeconds() const;

    // Арифметические операторы
    Time operator+(const Time& other) const;
    Time operator-(const Time& other) const;            
    Time operator+(double seconds) const;               // Time + вещественное
    friend Time operator+(double seconds, const Time& t); // вещественное + Time

    // Операторы сравнения
    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
    bool operator<(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator<=(const Time& other) const;
    bool operator>=(const Time& other) const;

private:
    unsigned int _hour, _min, _sec;
    // перевод времени в секунды
    unsigned int _toSeconds() const;        
    // создание Time из секунд (с нормализацией)
    static Time _fromSeconds(unsigned int totalSeconds); 
};