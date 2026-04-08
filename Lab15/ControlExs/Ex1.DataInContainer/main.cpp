// Задание 1. Хранение оценок студентов в std::map

#include <iostream>
#include <map>
#include <string>

using namespace std;

// Структура для пары: имя - оценка 
struct StudentGrade {
    string name;
    char grade;
};

int main() {
    // Контейнер map: ключ = имя, значение = оценка
    map<string, char> studentGrades;

    // Добавление студентов и оценок
    studentGrades["Ivanov"] = 'B';
    studentGrades["Petrov"] = 'A';
    studentGrades["Sidorov"] = 'C';

    // Вывод всех студентов и оценок
    cout << "Student grades:\n";
    int i = 0;
    for (const auto& pair : studentGrades) {
        i++;
        cout << i << ") " << pair.first << " : " << pair.second << endl;
    }
    cout << "\tTotal students: " << i << endl;

    // Меняем оценку Сидорова
    studentGrades["Sidorov"] = 'D';

    // Повторный вывод
    i = 0;
    for (const auto& pair : studentGrades) {
        i++;
        cout << i << ") " << pair.first << " : " << pair.second << endl;
    }
    cout << "\tTotal students: " << i << endl;

    // Проверка оценки конкретного студента
    string name = "Ivanov";
    auto it = studentGrades.find(name);
    if (it != studentGrades.end())
        cout << "\nStudent grade " << name << " : " << it->second << endl;
    else
        cout << "\nStudent " << name << " not foound!\n";

    // Попытка получить оценку несуществующего студента
    name = "Vasiliev";
    it = studentGrades.find(name);
    if (it != studentGrades.end())
        cout << "Student grade " << name << " : " << it->second << endl;
    else
        cout << "\nStudent " << name << " not foound!\n";

    return 0;
}