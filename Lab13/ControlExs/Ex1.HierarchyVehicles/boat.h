#pragma once

#include "vehicle.h"

// производный от Vehicle класс
// virtual public Vehicle - Одна копия для всех наследников
class Boat : virtual public Vehicle {
public:
	void move() const override {
		std::cout << "Boat is sailing on water.";
	}
	std::string type() const override {
		return "Boat";
	}

	std::string getBehavior() const override {
		return "sailing on water";
	}
};