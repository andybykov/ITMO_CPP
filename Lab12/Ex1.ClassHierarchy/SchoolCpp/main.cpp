// Упражнение 1. Создание иерархии классов
//

#include <iostream>
#include "human.h"
#include "student.h"

int main()
{
    Student stud("Pupkin", "Vasya", "Ivanovich", {1, 2, 3, 4, 5});
    std::cout << stud.get_full_name()  <<" average score = " << stud.get_average_score();
}
