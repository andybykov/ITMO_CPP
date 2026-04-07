#pragma once
#include "item.h"

// Производный класс: бумажная книга
class Paperbook : public Item {
private:
	int pages;

public:
	void getdata() override {
		Item::getdata();
		cout << "Введите число страниц: ";
		cin >> pages;
	}

	void putdata() override {
		Item::putdata();
		cout << "\nСтраниц: " << pages;
	}
};
