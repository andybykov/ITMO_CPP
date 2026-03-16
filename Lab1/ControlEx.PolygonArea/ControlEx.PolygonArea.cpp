#include <iostream>
#include <cmath>
#include <fmt/format.h>
#include <fmt/color.h>

int main() {
    const int N = 5;                    
    double x[N], y[N];      
    /*
    x[0] = 1.0; y[0] = 1.0;   
    x[1] = 5.0; y[1] = 2.0;   
    x[2] = 4.0; y[2] = 5.0;   
    x[3] = 2.0; y[3] = 6.0;   
    x[4] = 0.0; y[4] = 3.0;   
    // Площадь= 15.50
    */
    // Ввод координат вершин
    
    fmt::print(fg(fmt::color::cyan), "Введите координаты вершин пятиугольника (x y):\n");
    for (int i = 0; i < N; ++i) {
        fmt::print("Вершина {}: ", i + 1);
        std::cin >> x[i] >> y[i];        // пары координат 
    }
    
    // Расчет площади по формуле Гаусса 
    double sum = 0;
    for (int i = 0; i < N; ++i) {
        int j = (i + 1) % N;            
        sum += x[i] * y[j] - x[j] * y[i];
    }
    double area = std::fabs(sum) / 2.0;   

    // Вывод результатов в виде таблицы

    fmt::print("Площадь = {:.2f}\n", area);


    return 0;
}