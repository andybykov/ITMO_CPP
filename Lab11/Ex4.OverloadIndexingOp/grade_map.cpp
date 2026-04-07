/* grade_map.cpp */

#include "grade_map.h"

// конструктор по умолчанию 
GradeMap::GradeMap() {}

// перегрузка оператора []
char& GradeMap::operator[](const string& name)
{
	// Найдём ли мы имя ученика в векторе
	for (auto& ref : m_map)
	{
		// Если нашли, то возвращаем ссылку на его оценку
		if (ref.name == name)
			return ref.grade;
	}
	// Не нашли - создаём новый StudentGrade для нового ученика
	StudentGrade temp{ name, ' ' };
	// Помещаем его в конец вектора
	m_map.push_back(temp);

	// И возвращаем ссылку на его оценку
	return m_map.back().grade;
}
