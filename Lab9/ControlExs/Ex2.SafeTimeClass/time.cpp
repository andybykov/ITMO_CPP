//time.cpp
#include "time.h"

#include <iomanip>
#include <iostream>

// списки инициализации, нулевые значения по умолчанию
Time::Time() : _hour(0), _min(0), _sec(0) {}

// с инициализацией
Time::Time(unsigned int hour, unsigned int min, unsigned int sec) {
	if (min > 59 || sec > 59 || hour > 23) {
		throw std::invalid_argument("Incorrect time");
	}
	{
		_hour = hour;
		_min = min;
		_sec = sec;
	}
}
// вывод времени с форматированием
void Time::print() const
{
	std::cout << std::setfill('0')
		<< std::setw(2) << _hour << ":"
		<< std::setw(2) << _min << ":"
		<< std::setw(2) << _sec << std::endl;
}

// геттеры
int Time::getHours() const {
	return _hour;
}

int Time::getMinutes() const {
	return _min;
}

int Time::getSeconds() const {
	return _sec;
}

// Статический метод сложения
Time Time::addition(const Time& time1, const Time& time2)
{
	int hRes = time1.getHours() + time2.getHours();
	int mRes = time1.getMinutes() + time2.getMinutes();
	int sRes = time1.getSeconds() + time2.getSeconds();

	return Time(hRes, mRes, sRes);
}

// нормализация времени
void Time::_normalizeTime() {
	// Нормализуем секунды
	_min = _min + _sec / 60;
	_sec = _sec % 60;

	// Нормализуем минуты
	_hour = _hour + _min / 60;
	_min = _min % 60;

	// Нормализуем часы 
	_hour = _hour % 24;
}

