/*
* В этом упражнении применяется библиотека fmt (также известна как {fmt}),
* современная, быстрая и удобная альтернатива стандартному printf и std::cout.
*/

#include <chrono>
#include <fmt/chrono.h>
#include <fmt/color.h>
#include <fmt/core.h>
#include <iostream>
#include <string>

// перечисление типов сообщений
enum Level { INFO, WARNING, ERROR };

// Функция для форматирования строки сообщения
//Формат записи: [YYYY-MM-DD HH:MM:SS] [LEVEL] message
std::string log_msg(Level level, std::string message) {
	std::string result;
	auto now = std::chrono::system_clock::now();

	switch (level) {
	case INFO:
		result = fmt::format(fmt::emphasis::bold | fg(fmt::color::green), "[{:%Y-%m-%d %H:%M:%S}] ", now) +
			fmt::format(fmt::emphasis::bold | fg(fmt::color::green), "[{}] ", "INFO") +
			fmt::format(fmt::emphasis::bold | fg(fmt::color::green), "[{}]\n", message);
		break;
	case WARNING:
		result = fmt::format(fmt::emphasis::bold | fg(fmt::color::yellow), "[{:%Y-%m-%d %H:%M:%S}] ", now) +
			fmt::format(fmt::emphasis::bold | fg(fmt::color::yellow), "[{}] ", "WARNING") +
			fmt::format(fmt::emphasis::bold | fg(fmt::color::yellow), "[{}]\n", message);
		break;

	case ERROR:
		result = fmt::format(fmt::emphasis::bold | fg(fmt::color::red), "[{:%Y-%m-%d %H:%M:%S}] ", now) +
			fmt::format(fmt::emphasis::bold | fg(fmt::color::red), "[{}] ", "ERROR") +
			fmt::format(fmt::emphasis::bold | fg(fmt::color::red), "[{}]\n", message);
		break;

	}

	return result;
}



int main() {
	int x = 42;
	std::string name = "Alice";

	//fmt::print("Date and time: {}\n", now);
	//fmt::print("Time: {:%H:%M:%S}\n", now);
	// Возвратите строку с числом в разных форматах: десятичном, шестнадцатеричном и двоичном формате
	//"Dec: 42, Hex: 0x2a, Bin: 0b101010
	// Строку с числом в трёх форматах:	▪ по умолчанию,	▪ с 2 знаками после запятой,▪ в экспоненциальной форме Default: 3.14159 | Fixed: 3.14 | Sci: 3.142e+00
	double value = 0;
	std::string mes1 = ("INFO", "Application started");
	fmt::print("Enter value: ");
	std::cin >> value;
	std::string res = fmt::format(fmt::emphasis::bold | fg(fmt::color::blue_violet), "DEC: {0:} ", int(value)) +
		fmt::format(fmt::emphasis::bold | fg(fmt::color::green_yellow), "Hex: {0:#x} ", int(value)) +
		fmt::format(fmt::emphasis::bold | fg(fmt::color::orange_red), "Bin: {0:#b}", int(value)) +
		fmt::format("\n") +
		fmt::format(fmt::emphasis::bold | fg(fmt::color::white_smoke), "Default: {0:} | ", value) +
		fmt::format(fmt::emphasis::bold | fg(fmt::color::white_smoke), "Fiexed: {0:.2f} | ", value) +
		fmt::format(fmt::emphasis::bold | fg(fmt::color::white_smoke), "Sci: {0:.3e} ", value) +
		fmt::format("\n");

	fmt::print("{}\n", res);


	// Массив сообщений
	std::string messages[] = {
	log_msg(Level::INFO, "Application start"),
	log_msg(Level::WARNING, "Application some warning"),
	log_msg(Level::ERROR, "Application error")
	};
	// перебираем
	for (std::string mes : messages) {

		fmt::print("{}", mes);
	}

	return 0;
}



