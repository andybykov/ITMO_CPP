// human.h
#pragma once

#include <iostream>
#include <sstream>
#include <string>

class Human {
public:
	Human(std::string last_name, std::string name, std::string second_name)
		: last_name(last_name), name(name), second_name(second_name) {
	}

	virtual ~Human() = default;   // виртуальный деструктор

	std::string get_full_name() const {
		std::ostringstream full_name;
		full_name << last_name << " " << name << " " << second_name;
		return full_name.str();
	}

	// pure virtual methodss
	virtual std::string getRole() const = 0;  // возвращает роль 
	virtual void printInfo() const = 0; // выводит информацию

private:
	std::string name;
	std::string last_name;
	std::string second_name;
};