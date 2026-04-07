// Задание 2. Полиморфизм в системе классов учебного центра
//

#include <iostream>
#include <vector>
#include <typeinfo>
#include "human.h"
#include "student.h"
#include "teacher.h"

int main() {
    setlocale(LC_ALL, "RU");

    // Вектор указателей на базовый класс Human
    std::vector<Human*> people;

    // Добавляем студентов и преподавателей
    people.push_back(new Student("Иванов", "Иван", "Иванович", { 5, 4, 5, 3, 4 }));
    people.push_back(new Student("Петрова", "Анна", "Сергеевна", { 5, 5, 5, 4 }));
    people.push_back(new Teacher("Сергеев", "Дмитрий", "Сергеевич", 40));
    people.push_back(new Teacher("Кузнецова", "Елена", "Викторовна", 36));

    // Полиморфный вызов методов printInfo() и getRole()
    for (const auto* person : people) {
        person->printInfo();     
        std::cout << "Роль: " << person->getRole() << "\n\n";
    }

    // вызов определенных методов с помощью RTTI (Run-Time Type Information)
    for (const auto* person : people) {
        //  Если это Student
        if (typeid(*person) == typeid(Student)) {
            const Student* st = static_cast<const Student*>(person); // безопасно приводим, чтобы вызвать метод из Student
            std::cout << st->get_full_name() << " == "
                << st->get_average_score() << "\n";
        }
    }

    // Освобождение памяти
    for (auto* p : people) {
        delete p;
    }

    return 0;
}