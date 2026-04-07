// Упражнение 1. Реализация полиморфного вызова
//
#include <windows.h>  // SetConsoleOutputCP
#include "audiobook.h"
#include "item.h"
#include "paperbook.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	SetConsoleOutputCP(1251);

	Item* pubarr[100];  // массив указателей на базовый класс
	int n = 0;
	char choice;

	do {
		cout << "\nВводить данные для книги или звукового файла (b/a)? ";
		cin >> choice;

		if (choice == 'b')
			pubarr[n] = new Paperbook;
		else
			pubarr[n] = new AudioBook;

		pubarr[n]->getdata();
		n++;

		cout << "Продолжать (y/n)? ";
		cin >> choice;
	} while (choice == 'y');

	cout << "\n\nData:\n";
	for (int j = 0; j < n; ++j) {
		pubarr[j]->putdata();
		cout << endl;
	}

	// Освобождение памяти
	for (int j = 0; j < n; ++j) {
		delete pubarr[j];
	}

	return 0;
}