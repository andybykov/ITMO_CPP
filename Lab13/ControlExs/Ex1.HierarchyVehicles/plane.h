#pragma once

#include "vehicle.h"

// производный от Vehicle класс
// virtual public Vehicle - Одна копия для всех наследников
class Plane : virtual public Vehicle {
public:
    void move() const override {
        std::cout << "Plane is flying in the sky.";
    }
    std::string type() const override {
        return "Plane";
    }

    std::string getBehavior() const override {
        return "flying in the sky";
    }
};