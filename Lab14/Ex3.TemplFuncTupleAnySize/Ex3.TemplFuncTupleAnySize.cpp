// Упражнение 3. Использование шаблонной функции для работы с кортежем любого размера
//

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

// Рекурсивная реализация шаблонного класса TuplePrinter
template<class Tuple, std::size_t N>
struct TuplePrinter {
	// Статическая функция print, которая будет вызываться рекурсивно
	static void print(const Tuple& t)
	{
		//  напечатает все элементы от 0 до N-2
		TuplePrinter<Tuple, N - 1>::print(t);
		cout << ", " << get<N - 1>(t);
	}
};

// Базовы случай, станавливает рекурсию, когда N достигает 1 == последний элемент
template<class Tuple>
struct TuplePrinter<Tuple, 1> {
	// print для одного элемента
	static void print(const Tuple& t)
	{
		cout << get<0>(t);
	}
};

// Вариативный шаблон функции - принимает кортеж с любым количеством элементов
// Args... - может содержать разные типы
template<class... Args>
void printTuple(const tuple<Args...>& t)
{
	cout << "(";
	TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
	cout << ")" << endl;
}


int main()
{
    // векторы
    vector<string> v1{ "one", "two", "three", "four", "five", "six" };    
    vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
    vector<float> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

    // кортежи
    auto t1 = std::make_tuple(v1[0], v1[1], v3[0]);    
    auto t2 = std::make_tuple(v1[0], v1[1], v2[1], v3[0], v3[1]);

    // printTuple() для каждого кортежа
    cout << "t1: ";
    printTuple(t1);  

    cout << "t2: ";
    printTuple(t2);  

    // Кортеж из одного элемента
    auto t3 = make_tuple(42);
    cout << "t3: ";
    printTuple(t3); 

    return 0;
}
