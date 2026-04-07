// Задание 1. Иерархия транспортных средств
//

#include <iostream>
#include <vector>
#include <fstream>
#include <typeinfo>
#include "car.h"
#include "boat.h"
#include "plane.h"
#include "amphibious.h"

int main() {
    // вектор указателей на Vehicle
    std::vector<Vehicle*> vehicles;

    vehicles.push_back(new Car());
    vehicles.push_back(new Boat());
    vehicles.push_back(new Plane());
    vehicles.push_back(new AmphibiousVehicle());

    // счетчик созданных объектов
    std::cout << "Number of objects: " << Vehicle::getCount() << std::endl;

    // нформация о типе и поведении каждого объекта
    for (const auto* v : vehicles) {
        std::cout << v->type() << ": ";
        v->move();
        std::cout << std::endl;       
    }

    // RTTI (typeid)
    std::cout << "\nRTTI (typeid)\n";
    for (const auto* v : vehicles) {
        std::cout << "Actual type: " << typeid(*v).name() << std::endl;
    }

    // методы из родителей
    AmphibiousVehicle av;    
    av.enterWater(); // на воде
    av.move();

    std::string behavior = av.getBehavior();    

    std::cout << "\n" << av.type() << ": " << behavior << "\n";

    av.exitWater(); // на земле
    behavior = av.getBehavior();
    av.move();


    std::cout << av.type() << ": " << behavior << "\n";
    std::cout << std::endl;

    // Сериализация в текстовый файл (<тип>;<поведение>)
    std::ofstream out("vehicles.txt");
    if (out.is_open()) {
        for (const auto* v : vehicles) {            
            out << v->type() << ";" << v->getBehavior() << "\n";
        }
        out.close();
        std::cout << "\nSaved to vehicles.txt\n";
    }
    else {
        std::cerr << "Error opening file!\n";
    }

    // Освобождение памяти
    for (auto* v : vehicles) {
        delete v;
    }

    return 0;
}