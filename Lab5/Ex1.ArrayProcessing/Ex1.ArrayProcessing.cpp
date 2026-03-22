// Упражнение 1. Обработка данных массива

#include <iostream>

int main()
{
    setlocale(LC_ALL, "RU");

    const int N = 10;
    int mas[N];

    // заполнение
    for (int i = 0; i < N; i++)
    {
        std::cout << "mas[" << i << "]=";
        std::cin >> mas[i];
    }

    // сумма элементов
    int s = 0;

    for (int i = 0; i < N; i++)
    {
        s += mas[i];
    }
    std::cout << std::endl;
    std::cout << "Сумма всех элементов массива: " << s << std::endl;
    
    // среднее 
    double avg = static_cast<double>(s) / N;
    std::cout << "Среднее значение: " << avg << std::endl;

    // сумма отрицательных 
    int sumNegative = 0;
    for (int i = 0; i < N; i++)
    {
        if (mas[i] < 0)
            sumNegative += mas[i];
    }
    std::cout << "Сумма отрицательных: " << sumNegative << std::endl;

   // сумма положительных 
        int sumPositive = 0;
    for (int i = 0; i < N; i++)
    {
        if (mas[i] > 0)
            sumPositive += mas[i];
    }
    std::cout << "Сумма положительных: " << sumPositive << std::endl;

    // сумма с нечетными индексами 
    int sumOddIndex = 0;
    for (int i = 1; i < N; i += 2)  
    {
        sumOddIndex += mas[i];
    }
    std::cout << "Сумма элементов с нечетными индексами: " << sumOddIndex << std::endl;

    // сумма элементов с четными индексами 
    int sumEvenIndex = 0;
    for (int i = 0; i < N; i += 2)  
    {
        sumEvenIndex += mas[i];
    }
    std::cout << "Сумма элементов с четными индексами: " << sumEvenIndex << std::endl;


    // максимальный и минимальный + индексы
    int maxVal = mas[0];
    int minVal = mas[0];
    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 1; i < N; i++)
    {
        if (mas[i] > maxVal)
        {
            maxVal = mas[i];
            maxIndex = i;
        }
        if (mas[i] < minVal)
        {
            minVal = mas[i];
            minIndex = i;
        }
    }

    std::cout << "Максимум: mas[" << maxIndex << "] = " << maxVal << std::endl;
    std::cout << "Минимум: mas[" << minIndex << "] = " << minVal << std::endl;

    // произведение элементов между максимумом и минимумом
    int product = 1;
    bool found = false;

    // начало и конец диапазона
    int start = (minIndex < maxIndex) ? minIndex : maxIndex;
    int end = (minIndex < maxIndex) ? maxIndex : minIndex;

    // перемножаем элементы между ними
    for (int i = start + 1; i < end; i++)
    {
        product *= mas[i];
        found = true;
    }

    if (found)
        std::cout << "Произведение между min и max: " << product << std::endl;
    else
        std::cout << "Между min и max нет элементов" << std::endl;

}

