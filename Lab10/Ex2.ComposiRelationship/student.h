/* student.h */
#pragma once

#include "IdCard.h"
#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	// новый конструктор
	Student(string name, string last_name, int id, string cat);

	void setIdCard(int id, string c);

	int getIdCard(); //  номер карты

	void display(); // вывод всей информации


	void set_name(string);

	string get_name();

	void set_last_name(string);

	string get_last_name();

	void set_scores(int[]);

	void set_average_score(double);

	double get_average_score();

private:
	int scores[5];

	double average_score;

	string name;

	string last_name;

	IdCard iCard;
};