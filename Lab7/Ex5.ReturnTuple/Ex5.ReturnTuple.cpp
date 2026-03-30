// Упражнение 5. Возвращение кортежа из функции
//

#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <windows.h>

using namespace std;

// создаем псевдоним
//typedef tuple<string, int, double> Tuple;
using Tuple = tuple<string, int, double>;

// распечатка кортежа
void printTupleOfThree(Tuple t)
{
	cout << "("
		<< std::get<0>(t) << ", "
		<< std::get<1>(t) << ", "
		<< std::get<2>(t) << ")" << endl;
}

Tuple funtup(string s, int a, double d)
{
	s.append("!");
	return make_tuple(s, a, d * 10);
}

// Функция, которая принимает кортеж, изменяет его содержимое 
// и возвращает новый кортеж того же типа
Tuple modifyTuple(const Tuple& t)
{
	string s = get<0>(t);
	int a = get<1>(t);
	double d = get<2>(t);

	// изменяем содержимое
	s = "Modified: " + s;
	a = a * 2;
	d = d + 2.5;

	return funtup(s, a, d);
}

// Функция, которая принимает кортеж, изменяет его содержимое,
// формирует две переменные и возвращает новый кортеж другого типа
tuple<string, double> transformTuple(const Tuple& t)
{
	string s = get<0>(t);
	int a = get<1>(t);
	double d = get<2>(t);

	// изменяем содержимое
	s = s + "!!!";
	double result1 = a * 10.5;      // преобразуем в double
	double result2 = d * 2.0;       // умножаем дюймы

	// возвращаем кортеж string, double
	return make_tuple(s, result1 + result2);
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };


	// инициализиурем кортеж
	auto t0 = make_tuple(v1[0], v2[0], v3[0]);
	auto t1 = funtup(v1[1], v2[1], v3[1]);

	// вывод
	printTupleOfThree(t0);
	printTupleOfThree(t1);

	Tuple modified = modifyTuple(t0);
	printTupleOfThree(modified);

	auto transformed = transformTuple(t1);
	cout << "(" << get<0>(transformed) << ", " << get<1>(transformed) << ")" << endl;

	return 0;
}

