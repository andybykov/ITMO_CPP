// Упражнение 2. Реализация функции обмена значений

#include <iostream>

// прототипы
void swap(int*, int*);

void swap(int&, int&);

int main()
{
    setlocale(LC_ALL, "RU");

    int x = 5, y = 10;
    std::cout << "До обмена: " << std::endl;
    std::cout << "x = " << x << " y = " << y << std::endl;
    std::cout << "После обмена: " << std::endl;
    swap(&x, &y);   
    std::cout << "обмен по указателю: " << " x = " << x << " y = " << y << std::endl;
    swap(x, y);
    std::cout << "обмен по ссылке: " << " x = " << x << " y = " << y << std::endl;
}


void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swap(int& x, int& y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}