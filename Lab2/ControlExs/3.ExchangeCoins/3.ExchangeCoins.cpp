// Размен монет. Требуется выдать набор монет с наименьшим возможным количеством монет

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int sum;
    cout << "Введите сумму в рублях: ";
    cin >> sum;

    // Проверка 
    if (sum < 0) {
        cout << "Сумма не может быть отрицательной!" << endl;
        return 1;
    }

    // Количество монет каждого номинала
    int count10, count5, count2, count1;

    // Жадный алгоритм
    count10 = sum / 10;  // Количество монет 10р
    sum = sum % 10;      // Остаток после размена 

    count5 = sum / 5;    // Количество монет 5р
    sum = sum % 5;       // Остаток после размена 

    count2 = sum / 2;    // Количество монет 2р
    sum = sum % 2;       // Остаток после размена 

    count1 = sum;        // остаток добиваем по 1р


    cout << "Размен:" << endl;
    if (count10 > 0) cout << "10 руб: " << count10 << " монет" << endl;    
    if (count5 > 0) cout << "5 руб: " << count5 << " монет" << endl;
    if (count2 > 0) cout << "2 руб: " << count2 << " монет" << endl;
    if (count1 > 0) cout << "1 руб: " << count1 << " монет" << endl;

    int totalCoins = count10 + count5 + count2 + count1;
    cout << "Общее количество монет: " << totalCoins << endl;

    return 0;
}
