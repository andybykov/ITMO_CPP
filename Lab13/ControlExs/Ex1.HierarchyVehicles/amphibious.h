#pragma once

#include "boat.h"
#include "car.h"

class AmphibiousVehicle : public Car, public Boat {
private:
	bool _onWater = false;  // состояние: на воде или не на воде

public:
	void move() const override {
		if (_onWater)
			Boat::move();   // метод лодки
		else
			Car::move();    // метод машины
	}

	std::string type() const override {
		return "Amphibious";
	}

	std::string getBehavior() const override {
		if (_onWater) {
			return "sailing on water";
		}
		else {
			return "driving on the road";
		}
	}

	void enterWater() { _onWater = true; }
	void exitWater() { _onWater = false; }
};
