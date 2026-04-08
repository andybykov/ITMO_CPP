// Задание 3. Шаблонная функция maxOfTwo с ограничением
//

#include <iostream>
#include <concepts>

// Концепт требующий наличие оператора < 
/*
* тип должен поддерживать < с результатом, конвертируемым в bool
*/
template <typename T>
concept Comparable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
};

// Шаблонная функция maxOfTwo 
// ограничением по типу
template <Comparable T>
T maxOfTwo(const T& a, const T& b) {
    return (a < b) ? b : a;
}

// Класс Meters 
class Meters {
    double value;
public:
    Meters(double v) : value(v) {}  

    bool operator<(const Meters& other) const {
        return value < other.value;
    }

    friend std::ostream& operator<<(std::ostream& os, const Meters& m) {
        os << m.value << " m";
        return os;
    }
};

// Класс Seconds
class Seconds {
    double value;
public:
    Seconds(double v) : value(v) {}

    bool operator<(const Seconds& other) const {
        return value < other.value;
    }

    friend std::ostream& operator<<(std::ostream& os, const Seconds& s) {
        os << s.value << " s";
        return os;
    }
};

int main() {
    // int
    std::cout  << maxOfTwo(5, 3) << std::endl;
    std::cout  << maxOfTwo(2, 7) << std::endl;

    // double
    std::cout << maxOfTwo(3.14, 2.71) << std::endl;
    std::cout << maxOfTwo(1.5, 1.5) << std::endl;

    // пользовательские классы
    Meters m1(10.5), m2(5.2);
    std::cout << maxOfTwo(m1, m2) << std::endl;

    Seconds s1(30.0), s2(45.5);
    std::cout << maxOfTwo(s1, s2) << std::endl;

    return 0;
}