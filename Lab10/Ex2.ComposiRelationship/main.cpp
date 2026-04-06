// Упражнение 2. Отношение композиции
//

#include "student.h"
#include <iostream>
#include <string>

int main()
{
    setlocale(LC_ALL, "RU");

    string name = "Василий";
    string last_name = "Иванов";

  
    Student* student02 = new Student(name, last_name, 101, "base");


    student02->display();

    delete student02;
}
