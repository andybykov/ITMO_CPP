#pragma once

#include "vehicle.h"

// производный от Vehicle класс.
// virtual public Vehicle - Одна копия для всех наследников
class Car : virtual public Vehicle {
public:
    void move() const override {
        std::cout << "Car is driving on the road";
    }

    std::string type() const override {
        return "Car";
    }

    std::string getBehavior() const override {
        return "driving on the road";
    }
};