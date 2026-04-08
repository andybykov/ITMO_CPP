#include <Windows.h>
#include "Group.h"
#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

Group::Group(string name)
{
    this->name = name;
}

Group::Group()
{
    name = "Без названия";
}

void Group::setName(string newName)
{
    name = newName;
}

string Group::getName()
{
    return name;
}

int Group::getSize()
{
    return (int)masSt.size();
}

// Добавление указателя на студента
void Group::addStudent(Student* newStudent)
{
    masSt.insert(newStudent);
}

// Удаление студента по указателю
void Group::delStudent(Student* oldStudent)
{
    masSt.erase(oldStudent);
}

// Вывод всех студентов группы
void Group::GroupOut()
{
    iter = masSt.begin();
    while (iter != masSt.end())
        (*iter++)->display();
}

// Поиск студента по имени и фамилии с помощью lower_bound
Student* Group::findStudent(string searchName, string searchLastName)
{
    Student* temp = new Student(searchName, searchLastName);
    iter = masSt.lower_bound(temp);
    delete temp;
    if (iter != masSt.end())
        return *iter;
    else
        return nullptr;
}