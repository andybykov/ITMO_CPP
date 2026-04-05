// Задание 2. Безопасная реализация класса Time
//

#include "time.h"
#include <iostream>

int main()
{
	try {

		Time tim1(25, 24, 3);
		tim1.print();
	}
	catch (const std::exception& e)
	{
		//обработка исключения
		std::cout << "ERROR: " << e.what() << std::endl;
	}
}
