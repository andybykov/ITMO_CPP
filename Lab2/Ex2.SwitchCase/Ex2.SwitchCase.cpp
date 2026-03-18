/* Использование оператора switch при реализации выбора */
#include <iostream>

int main()
{
    setlocale(LC_ALL, "RU");
    char op;
    std::cout << "Сделай свой выбор, собери авто свой мечты: ";
    std::cin >> op;

       switch (op)
    {
    case 'S':
        std::cout << "Радио играть должно\n";
        std::cout << "Колеса круглые\n";
        std::cout << "Мощный двигатель\n";
        break;
    case 'V':
        std::cout << "Кондиционер хочу\n";
        std::cout << "Радио играть должно\n";
        std::cout << "Колеса круглые\n";
        std::cout << "Мощный двигатель\n";
        break;
    default:
        std::cout << "Колеса круглые\n";
        std::cout << "Мощный двигатель\n";
    }
}
