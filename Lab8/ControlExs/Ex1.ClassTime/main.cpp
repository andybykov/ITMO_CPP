// Задание 1. Класс Time
//

#include <iomanip>
#include <iostream>
#include "time.h"

int main()
{
	const Time tim1{10, 30, 30};
	tim1.print();
	const Time tim2{0, 71, 35};
	tim2.print();

	const auto res = Time::addition(tim1, tim2);
	res.print();
}