/* В этом задании должна быть проверка лежит ли точка внутри заштрихованной области, или она
* находится вне заштрихованной области или на ее границе
*/
#include <iostream>

int main()
{
	int x{ 0 };
	int y{ 0 };

	std::cout << "Enter coordinats: x y" << std::endl;

	std::cin >> x >> y;
	
		if (x * x + y * y < 9 && y > 0) {
			// "внутри"
			std::cout << "Inside area" << std::endl;
		}

		else if (x * x + y * y > 9 || y < 0) {
			// "снаружи"
			std::cout << "Outside area" << std::endl;
		}

		else {
			// "на границе"
			std::cout << "On border of area" << std::endl;
		}

}
