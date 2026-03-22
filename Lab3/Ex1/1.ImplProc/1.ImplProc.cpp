// Задание 1. Реализация процедуры

#include <iostream>
#include <string>

using namespace std;

// Прототип функции
void privet(string);


int main()
{
	string name;
	cout << "What is your name?" << endl;
	cin >> name;
	privet(name);

	return 0;
}

// Реализация функции
void privet(string name)
{
	cout << name << ", " << "hello!" << endl;
}