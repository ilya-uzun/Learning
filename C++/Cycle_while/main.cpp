#include<iostream>
#include <cmath>

using namespace std;

int main()
{
    float eps = 0.0001; // погрешнасть
    float an, sum; // текущий qn и сумма ряда
    float n; // текущий номер

    while (fabs(an)>eps)
    { //Функция fabs вычисляет абсолютное значение (модуль) и возвращает его |х|.
        n = n + 1.0;
        an = 1 / ((3*n-2)*(3*n+1));
        sum = sum + an;
    }
     cout << sum << " "; // выводим сумму
};