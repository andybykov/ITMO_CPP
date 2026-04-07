/* time.cpp */

#include "time.h"
#include <cmath>
#include <stdexcept>

Time::Time() : _hour(0), _min(0), _sec(0) {}

// Конструктор с проверкой корректности 
Time::Time(unsigned int hour, unsigned int min, unsigned int sec) {
	if (min > 59 || sec > 59 || hour > 23)
		throw std::invalid_argument("Incorrect time");
	_hour = hour;
	_min = min;
	_sec = sec;
}

// вывод
void Time::print() const {
	std::cout << std::setfill('0')
		<< std::setw(2) << _hour << ":"
		<< std::setw(2) << _min << ":"
		<< std::setw(2) << _sec << std::endl;
}


unsigned int Time::getHours()   const { return _hour; }

unsigned int Time::getMinutes() const { return _min; }

unsigned int Time::getSeconds() const { return _sec; }

// время в секунды
unsigned int Time::_toSeconds() const {
	return _hour * 3600 + _min * 60 + _sec;
}

// Time из секунд
Time Time::_fromSeconds(unsigned int totalSeconds) {
	unsigned int h = (totalSeconds / 3600) % 24;
	unsigned int m = (totalSeconds % 3600) / 60;
	unsigned int s = totalSeconds % 60;
	return Time(h, m, s);
}

// Сложение Time 
Time Time::operator+(const Time& other) const {
	return _fromSeconds(_toSeconds() + other._toSeconds());
}

// Вычитание 
Time Time::operator-(const Time& other) const {
	unsigned int s1 = _toSeconds();
	unsigned int s2 = other._toSeconds();
	//if (s2 > s1) return Time(0, 0, 0);
	return _fromSeconds(s1 - s2);
}

// Сложение Time + double 
Time Time::operator+(double seconds) const {
	if (seconds < 0) seconds = 0;
	unsigned int addSec = static_cast<unsigned int>(seconds);
	return _fromSeconds(_toSeconds() + addSec);
}

// Сложение double + Time 
Time operator+(double seconds, const Time& t) {
	return t + seconds;
}

// операторы сравнения
bool Time::operator==(const Time& other) const {
	return _toSeconds() == other._toSeconds();
}

bool Time::operator!=(const Time& other) const {
	return !(*this == other);
}

bool Time::operator<(const Time& other) const {
	return _toSeconds() < other._toSeconds();
}

bool Time::operator>(const Time& other) const {
	return other < *this;
}

bool Time::operator<=(const Time& other) const {
	return !(other < *this);
}

bool Time::operator>=(const Time& other) const {
	return !(*this < other);
}