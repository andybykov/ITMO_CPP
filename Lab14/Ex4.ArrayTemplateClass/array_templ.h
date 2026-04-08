#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

// Шаблонный класс ArrayTempl: T - тип элементов, T1 - тип для суммы
template<class T, class T1>
class ArrayTempl
{
public:
    ArrayTempl(int size);
    ~ArrayTempl() { delete[] data; cout << "des" << endl; };
    T1 sum();
    T average_value();
    void show_array();
    int add_value(T);

private:
    T* data;
    int size;
    int index;
};

// Реализации методов шаблонного класса 
// в файле .h
template<class T, class T1>
ArrayTempl<T, T1>::ArrayTempl(int size)
{
    data = new T[size];
    if (data == NULL)
    {
        cerr << "Error memory ---- exit program" << endl;
        exit(1);
    }
    ArrayTempl::size = size;
    ArrayTempl::index = 0;
}

template<class T, class T1>
T1 ArrayTempl<T, T1>::sum()
{
    T1 sum = 0;
    for (int i = 0; i < index; i++) sum += data[i];
    return(sum);
}

template<class T, class T1>
T ArrayTempl<T, T1>::average_value()
{
    T1 sum = 0;
    for (int i = 0; i < index; i++) sum += data[i];
    return (sum / index);
}

template<class T, class T1>
void ArrayTempl<T, T1>::show_array()
{
    for (int i = 0; i < index; i++) cout << data[i] << ' ';
    cout << endl;
}

template<class T, class T1>
int ArrayTempl<T, T1>::add_value(T value)
{
    if (index == size) return(-1);
    else
    {
        data[index] = value;
        index++;
        return(0);
    }
}