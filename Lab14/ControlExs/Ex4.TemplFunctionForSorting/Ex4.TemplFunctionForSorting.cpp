// Задание 4. Шаблонная функция для сортировки (опционально)

#include <complex>
#include <concepts>
#include <iostream>
#include <vector>

// Концепт для сравнимых элементов
//Тип должен поддерживать > , < и == с результатом, конвертируемым в bool

template<typename T>
concept Sortable = requires(const T & a, const T & b) { // константые ссылки
	{ a > b } -> std::convertible_to<bool>;
	{ a < b } -> std::convertible_to<bool>;
	{ a == b } -> std::convertible_to<bool>;
};


// Концепт для контейнера
template<typename T>
concept Container = requires(const T & c) {
	// выражение должно быть валидным
	c.begin();
	c.end();
	c.size();

	// Требование вложенного типа
	typename T::value_type;
	typename T::iterator;
};

// Функция сортировки требует, чтобы контейнер был Container, а его элементы Sortable
template<typename C>
	requires Container<C>&& Sortable<typename C::value_type>

bool is_sorted(const C& container) {   // передача по константной ссылке 
	if (container.size() <= 1) return true;   // пустой или из 1 элемента всегда отсортирован

	auto iter = container.begin();  // получаем итератор

	while (iter != container.end() - 1)    // пока не дойдем до ПРЕДпоследнего
	{
		auto a = *iter;
		auto b = *(iter + 1);
		if (a > b) return false; // массив не отсортирован
		else {
			++iter; // сдвигаем указатель, перемещаемся вперед на один элемент
		}
	}
	return true;
}

int main()
{

	std::vector<int> v1{ 55, 35, 10, 1, 3, 5, 7, 98, 75 };
	std::vector<float> v2{ -1.0, 1.5, 2.1, 3.2, 4.8, 5.0, 7.1 };
	std::vector<std::string> v3{ "A", "B", "C", "D", "E" };

	std::vector<std::complex<double>> vс = {
	{1, 2},
	{3, 4},
	{5, 6},
	{7, 8},
	{9, 10}
	};


	std::cout << "Container is sorted? : " << std::boolalpha << is_sorted(v1) << std::endl;
	std::cout << "Container is sorted? : " << std::boolalpha << is_sorted(v2) << std::endl;
	std::cout << "Container is sorted? : " << std::boolalpha << is_sorted(v3) << std::endl;

	// с двумерным вектором не скомпилируется
	//std::cout << "Container is sorted? : " << std::boolalpha << is_sorted(vc) << std::endl;

}
