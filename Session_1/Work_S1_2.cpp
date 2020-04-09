#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    for (int i = 0; i <= 200; i++)
    {
        sum = sum + i;
        i = i + 2;// пропускаем чётные числа
    }
    cout << sum << endl;
    return 0;
}
