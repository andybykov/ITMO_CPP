// Упражнение 2. Организация студентов с помощью мультимножества
//
#include <iostream>
#include "Group.h"
#include "Student.h"
#include "IdCard.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    // ID-карточки
    IdCard* idc1 = new IdCard(1001, "Стандарт");
    IdCard* idc2 = new IdCard(1002, "Льготная");

    // студентоы через указатели 
    Student* student01 = new Student("Иван", "Иванов", idc1);
    Student* student02 = new Student("Мария", "Петрова", idc2);
    Student* student03 = new Student("Петр", "Петров", idc2);
    Student* student04 = new Student("Семен", "Смирнов", idc1);
    Student* student05 = new Student("Саша", "Коен", idc2);
    Student* student06 = new Student("Дмитрий", "Ионов", idc1);

    // средние баллы 
    student01->set_average_score(4.5);
    student02->set_average_score(4.8);
    student03->set_average_score(3.9);
    student04->set_average_score(5.0);
    student05->set_average_score(4.2);
    student06->set_average_score(3.5);

    // группа и добавляем студентов
    Group group("14521");
    group.addStudent(student01);
    group.addStudent(student02);
    group.addStudent(student03);
    group.addStudent(student04);
    group.addStudent(student05);
    group.addStudent(student06);

    cout << "Группа: " << group.getName() << ", размер: " << group.getSize() << endl;
    cout << "Список студентов: \n"; // сортировка по имени
    group.GroupOut();

    // Поиск студента
    cout << "\nПоиск студента:\n";
    Student* found = group.findStudent("Петр", "Петров");
    if (found != nullptr)
        found->display();
    else
        cout << "Не найден\n";

    // Удаление студента
    cout << "\nУдаляем студента...\n";
    group.delStudent(student05);
    cout << "после удаления: " << group.getSize() << endl;
    group.GroupOut();

    // Освобождение памяти
    delete student01; delete student02; delete student03;
    delete student04; delete student05; delete student06;
    delete idc1; delete idc2;

    return 0;
}