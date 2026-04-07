// teacher.h
#pragma once

#include "human.h"
#include <string>

class Teacher : public Human {
public:
    Teacher(std::string last_name, std::string name, std::string second_name,
        unsigned int work_time)
        : Human(last_name, name, second_name), work_time(work_time) {
    }

    unsigned int get_work_time() const {
        return work_time;
    }

    // Переопределение виртуальных методов
    std::string getRole() const override {
        return "Преподаватель";
    }

    void printInfo() const override {
        std::cout << get_full_name() << " (" << getRole() << ")\n";
        std::cout << "Учебных часов: " << work_time << "\n";
    }

private:
    unsigned int work_time;
};