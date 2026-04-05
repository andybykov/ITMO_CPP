// time.h
#pragma once
#include <iomanip>
#include <iostream>

class Time
{
public:
	// Конструкторы класса
	// списки инициализации, нулевые значения по умолчанию
	Time();

	// с инициализацией
	Time(unsigned int, unsigned int, unsigned int);


	// вывод времени с форматированием
	void print() const;
	
	// геттеры
	int getHours() const;

	int getMinutes() const;	

	int getSeconds() const;

	// статический метод сложения
	static Time addition(const Time&, const Time&);

private:
	unsigned int _hour, _min, _sec;
	// нормализация времени
	void _normalizeTime();

};

