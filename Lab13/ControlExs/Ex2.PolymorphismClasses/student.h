// student.h
#pragma once

#include "human.h"
#include <vector>
#include <string>

class Student : public Human {
public:
    Student(std::string last_name, std::string name, std::string second_name,
        std::vector<int> scores)
        : Human(last_name, name, second_name), scores(scores) {
    }

    float get_average_score() const {
        if (scores.empty()) return 0.0f;
        unsigned int sum = 0;
        for (int s : scores) sum += s;
        return static_cast<float>(sum) / scores.size();
    }

    // Переопределение виртуальных методов
    std::string getRole() const override {
        return "Студент";
    }

    void printInfo() const override {
        std::cout << get_full_name() << " (" << getRole() << ")\n";
        std::cout << "Средний балл: " << get_average_score() << "\n";
    }

private:
    std::vector<int> scores;
};