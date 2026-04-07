/* grade_map.h */
#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// для хранения пары имя_ученика:оценка
struct StudentGrade
{
	string name;
	char grade;
};

class GradeMap
{
private:
	vector<StudentGrade> m_map;   // вектор пар ключ:значение

public:
	// Конструтор по умолчанию
	GradeMap();
	// Перегруженный оператор индексации
	char& operator[](const string& name);
};



