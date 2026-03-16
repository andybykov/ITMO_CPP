/*
* В этом упражнении вы изучите особенности ввода числовых данных с
* клавиатуры и вывод их на экран, а также преобразование типов данных
*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;


int main()
{
	
	system("chcp 1251"); // не выводимм


	string name;
	cout << "Enter your name\n";
	double a, b;
	cout << "Enter a and b:\n";
	cin >> a;
	cin >> name;
	cin >> b;

	double x = a / b;
	cout << "sizeof(a / b) = " << sizeof(a / b) << std::ends << "\tsizeof(x)(double) = " << sizeof(x) << std::ends << "\tsizeof(x)(int) = " << sizeof(int(x)) << endl;

	cout.precision(3); // формат вывода результата
	cout << "\nx = " << x << endl; //вывод результата на экран
	cout << "Hello, " << name << "!\n";

	return 0;
}