// Упражнение 4. Использование шаблонного класса массива
//
#include <iostream>
#include "array_templ.h"

using std::cout;
using std::endl;
using std::cerr;

int main()
{
    // Массив int с суммой long
   ArrayTempl<int, long> numbers(100);
    int i;
    for (i = 0; i < 50; i++) numbers.add_value(i);
    numbers.show_array();
    cout << "Sum = " << numbers.sum() << endl;
    cout << "Average =  " << numbers.average_value() << endl;

    // Массив float с суммой float
    ArrayTempl<float, float> values(200);
    for (i = 0; i < 100; i++) values.add_value(i * 100);
    values.show_array();
    cout << "Sum = " << values.sum() << endl;
    cout << "Average = " << values.average_value() << endl;

    return 0;
}