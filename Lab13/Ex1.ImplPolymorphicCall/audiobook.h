#pragma once
#include "item.h"

// Производный класс : аудиокнига
class AudioBook : public Item {
private:
	double time;  // время звучания 

public:
	void getdata() override {
		Item::getdata();
		cout << "Введите время звучания: ";
		cin >> time;
	}

	void putdata() override {
		Item::putdata();
		cout << "\nВремя звучания: " << time << " мин";
	}
};
