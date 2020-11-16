#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    const int n = 101;
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


    // Добавить после элемента массива с заданным индексом элемент со значением 100.
    for (int i = 0; i < size; i++)
        // проверка чтобы первый массив е
    {
        size = size + 1; // увеличить размер на один
        int nn;// число от пользователя
        cout<< endl << "Ведите номер элемента ";
        cin >> nn;
        {
             // считаем пока не будет больше введеного числа
             for (int i = nn; i >= nn-1; i--) 
             {
                arr[i+1] = arr[i];
                arr[nn-1] = 100;
             }
             cout << endl<<"Добавляем после введенного 100 : ";

            for (int i = 0; i < size; i++) cout << arr[i] << ' ';
            break;
        }
    }     
  return 0;
}

main() {
    int a[6], i, j, n;
    for (i=0; i < 5; i++) cin >> a[i];
    
    cout << "Число: " <<endl;
    cin >> n ;
    
    cout << "Позиция: " <<endl;
    cin >> j ;
    
    for (i=4; i >= j-1; i--)
        a[i+1] = a[i];
    a[j-1] = n;

    for (i=0; i<6; i++) cout << a[i]<< " ";
      
}
