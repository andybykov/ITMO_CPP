// Проверка номера СНИЛС
	/*

	1. Каждая цифра СНИЛС умножается на номер своей позиции (позиция отсчитывается с конца), полученные произведения суммируются.
	2. Если сумма меньше 100, то контрольное число равно самой сумме.
	3. Если сумма равна 100 или 101, то контрольное число равно 00.
	4. Если сумма больше 101, то вычисляется остаток от деления суммы на 101.
	5. Если остаток меньше 100, то контрольное число равно остаток.
	6. Если остаток равен 100, то контрольное число равно 00.

	*/

#include <iostream>

int main()
{
	uint64_t snils = 0;
	std::cout << "Enter SNILS: ";
	std::cin >> snils;

	// проверка длины снилс
	auto tmp_snils = snils;

	for (int i = 0; i < 11; i++) {
		if (tmp_snils > 0) {
			tmp_snils /= 10;
		}
		else
		{
			std::cout << "SINLS length is incorrect!" << std::endl;
			return 1;
		}
	}
	uint64_t snils_cut = snils / 100; // обрезаем контрольную сумму
	uint64_t tmp_summ = 0; // хранение рассчета контрольной суммы
	uint64_t control_summ = snils % 100; // получаем контрольную сумму

	bool isvalid = false; // переменная вадидности снилс

	for (auto i = 1; i <= 9; i++) {
		auto last_number = snils_cut % 10; // получаем последнюю цифру
		snils_cut /= 10; //убираем последнюю цифру
		tmp_summ += last_number * i;
	}


	if (tmp_summ == 100 || tmp_summ == 101) {
		tmp_summ = 0;
	}
	else if (tmp_summ > 101) {
		tmp_summ %= 101;
	}

	isvalid = tmp_summ == control_summ; // сравниваем полученный рассчет с переданной суммой

	std::cout << std::boolalpha << isvalid << std::endl;

	return 0;
}

