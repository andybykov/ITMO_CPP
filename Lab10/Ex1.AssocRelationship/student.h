/* student.h */
#pragma once /* Защита от двойного подключения заголовочного файла */

#include "IdCard.h"
#include <string>

using namespace std;



class Student
{
public:
	// Конструктор
	Student(string name, string last_name, IdCard* id);

	void setIdCard(IdCard* c);

	IdCard getIdCard();

	// Установка имени студента
	void set_name(string);

	// Получение имени студента
	string get_name();

	// Установка фамилии студента
	void set_last_name(string);

	// Получение фамилии студента
	string get_last_name();

	// Установка промежуточных оценок
	void set_scores(int[]);

	// Установка среднего балла
	void set_average_score(double);

	// Получение среднего балла
	double get_average_score();

private:

	//указатель iCard на объект типа IdCard 
	IdCard* iCard;

	// Промежуточные оценки
	int scores[5];

	// Средний балл
	double average_score;

	// Имя
	string name;

	// Фамилия
	string last_name;
};