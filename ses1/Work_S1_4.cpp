#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    const int n = 150;
    int arr[n];
    int size = 100;
    cout << "Укажите размер массива от 0 до 100 -    ";
    cin >> size;

    //проверка правильности ввод
    while (size > 100 || cin.fail())
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Вы ввели недопустимый символ, попробуйте снова: ";
            cin >> size;
        }
        else
        {
            cout << "Вы превысили допустимый размер, попробуйте снова: ";
            cin >> size;
        }
    }
    //генератор случайных чисел
    srand(time(0)); //позволяет запускать программу несколько раз
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10; // генерируем от 0 до 10
    }
    //выводим первый массив
    cout << endl << "Изначальный массив равен = ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";

    if (arr[size - 1] == 0)	//удаление нулей из массива
        size--;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0 && arr[i + 1] == 0)
        {
            for (int j = i; j < size - 2; j++)
                arr[j] = arr[j + 2];
            size -= 2;
        }
        else if (arr[i] == 0)
        {
            for (int j = i; j < size - 1; j++)
                arr[j] = arr[j + 1];
            size--;
        }
    }
    //выводим массив после удаления 0
    cout << endl << "Удалили все 0 из массива  = ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";

    //добавляем элемент в массив после M[i-1]+2
    for (int i = 0; i < size; i++)
        // проверка чтобы первый массив е
    {
        if (arr[0] % 2 == 0)
        {
            cout<<endl << "Первый элемент чётный, прекращаем работу ";
            break;
            return 0;
        }
        else if (arr[i] % 2 == 0)
        {
            for (int j = size; j > i; j--)
                arr[j] = arr[j - 1];
                size++;
            arr[i + 1] = (i > 0) ? (arr[i - 1] + 2) : (arr[size - 1] + 2);
            cout << endl<<"Добавляем после M[i-1]+2 = \t";
            for (int i = 0; i < size; i++) cout << arr[i] << ' ';
            break;
        }
    }     return 0;}
