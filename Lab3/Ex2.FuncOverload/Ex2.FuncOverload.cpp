// Упражнение 2. Перегрузка функций
//

// Задание 2. Реализация возвращения значения функции
//
#include <iostream>
#include <string>

using namespace std;


string privet(string name)
{
	string str = name + ", " + "hello!\n";
	return str;
}

void privet(string name, int k)
{
	cout << name << ", " << "hello! " << "you input " << k << endl;
}

int main()
{
	string name;
	cout << "What is your name?" << endl;
	cin >> name;
	int k;
	cout << "Input number:" << endl;
	cin >> k;
	string nameOut = privet(name);
	cout << nameOut << endl;
	privet(name, k);

	return 0;
}
