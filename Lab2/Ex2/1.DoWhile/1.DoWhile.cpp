/* Использование цикла с постусловием
* В этом задании вы используете цикл с постусловием для вывода значения функции на интервале.
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x, x1, x2, y; // x – аргумент функции, x1, x2 – границы интервала, y – выходной параметр
	cout << "x1 = "; cin >> x1;
	cout << "x2 = "; cin >> x2;
	cout << "\tx\tsin(x)\n";
	x = x1;
	do
	{
		y = sin(x);
		cout << "\t" << x << "\t" << y << endl;
		x = x + 0.01;
	} while (x <= x2);
	return 0;
}




