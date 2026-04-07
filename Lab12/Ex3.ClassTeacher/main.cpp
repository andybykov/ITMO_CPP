// Упражнение 3. Работа с классом teacher
//

#include <iostream>
#include "human.h"
#include "teacher.h"

int main() {
    setlocale(LC_ALL, "RU");

    unsigned int teacher_work_time = 40;

    Teacher* tch = new Teacher("Сергеев", "Дмитрий", "Сергеевич", teacher_work_time++);

    std::cout << tch->get_full_name() << std::endl;
    std::cout << "Количество часов: " << tch->get_work_time() << std::endl;

    delete tch;  // Освобождение памяти
    return 0;
}

