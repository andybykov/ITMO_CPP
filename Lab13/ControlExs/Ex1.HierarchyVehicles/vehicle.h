/* vehicle.h */
#pragma once

#include <iostream>
#include <string>

// Абстрактный класс - содержат или наследуют, без переопределения, хотя бы одну чистую виртуальную функцию
class Vehicle {
public:		
    // Конструктор
    Vehicle() { ++count; }

    // Виртуальный деструктор
    virtual ~Vehicle() { --count; }

    // Статический метод 
    static int getCount() { return count; }

	// pure virtual functions
	virtual void move() const = 0;         

	virtual std::string type() const = 0;  

    virtual std::string getBehavior() const = 0;
	
private:
	static int count; // счетчик
};


