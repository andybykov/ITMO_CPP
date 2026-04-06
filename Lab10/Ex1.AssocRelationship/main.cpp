// Упражнение 1. Отношение ассоциации
//

#include "IdCard.h"
#include "student.h"
#include <iostream>
#include <string>

int main()
{
	setlocale(LC_ALL, "RU");
	IdCard* idc = new IdCard (123, "Базовый");
	//IdCard idc(123, "Базовый");

	std::string name = "Василий";
	std::string last_name = "Иванов";

	Student* student02 = new Student(name, last_name, idc);
	cout << "IdCard: " << student02->getIdCard().getNumber() << endl;
	cout << "Category: " << student02->getIdCard().getCategory() << endl;

	delete idc;
}

