/*
* В этом упражнении изучаются особенности ввода текстовых данных с клавиатуры и вывод их на экран
*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;


int main()
{
	string name;
	cout << "What is your name?\n";
	// cin >> name;
	getline(cin, name);
	cout << "Hello, " << name << "!" << endl;

	return 0;
}