#pragma once /* «ащита от двойного подключени€ заголовочного файла */
#include <string>
#include "Student.h"
#include <set>          // дл€ multiset
#include <algorithm>

using namespace std;

class Group
{
private:
    string name;
    multiset<Student*, compareStudent> masSt;            // мультимножество указателей
    multiset<Student*, compareStudent>::iterator iter;   // итератор

public:
    Group(string name);
    Group();
    int getSize();
    void setName(string newName);
    string getName();
    void addStudent(Student* newStudent);     // принимает указатель
    void delStudent(Student* oldStudent);     // удал€ет по указателю
    Student* findStudent(string, string);     // возвращает указатель
    void GroupOut();                          // вывод группы
    // метод GroupSort() не нужен Ц сортировка происходит автоматически
};