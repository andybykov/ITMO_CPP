// Упражнение 2. Создание объекта класса student
//

#include <iostream>
#include <vector>
#include "student.h"
#include "human.h"


int main()
{
	// Оценкистудента
	std::vector<int> scores;
	// Добавление оценок студента в вектор
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(4);
	scores.push_back(4);
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);

	Student* stud = new Student("Petrov", "Ivan", "Alexeevich", scores);

	std::cout << (*stud).get_full_name() << std::endl;
	std::cout << "Average score:" << (*stud).get_average_score() << std::endl;
	
	delete stud; // освобождение памяти
}