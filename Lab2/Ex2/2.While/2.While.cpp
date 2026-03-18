/* Использование цикла с предусловием
* В этом задании вы используете цикл с предусловием для определения значения
* наибольшего общего делителя двух целых чисел по алгоритму Евклида
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	int a, b, temp; //a и b – исходные данные, temp – временная переменная для реализации алгоритма

	cout << "a = "; 
	cin >> a;
	cout << "b = ";
	cin >> b;

	while (a != b)
	{
		if (a > b)
			a -= b; // аналогично выражению a = a - b
		else
			b -= a;
	}
	cout << "НОД = " << a << endl;
	return 0;
}




