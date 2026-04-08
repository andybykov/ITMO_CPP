// Упражнение 2. Создание шаблонной функции для работы с кортежем
//

#include <iostream>
#include <string>
#include <tuple>
#include <vector>

// шаблон функции распечатки кортежа
template<class Tuple>
void printTupleOfThree(Tuple t)
{
	std::cout << "("
		<< std::get<0>(t) << ", "
		<< std::get<1>(t) << ", "
		<< std::get<2>(t) << ")" << endl;
}
int main()
{
	std::vector<std::string> v1{ "one", "two", "three", "four", "five", "six" };
	std::vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	std::vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

	// инициализиурем кортеж
	auto t0 = std::make_tuple(v1[0], v2[0], v3[0]);
	//распечатка
	printTupleOfThree(t0);

	auto t3 = std::make_tuple(v1[0], v1[1], v2[2]);
	printTupleOfThree(t3);

	return 0;
}
