#include <iostream>
#include <ctime>

using namespace std;


void FillArrey(int* const arr, const int size)
{
    // Создаём рандомный массив с числами от 0 до 10
    srand(time(0)); //позволяет запускать программу несколько раз, иначе одинаковые значения
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10; 
    }
}

void ShowArray(int* const arr, const int size)
{

    // Выводим массив
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void del_zero(int *&arr, int &size)
{
    int *newArr_del_zero = new int[size]; // сoздаём новый массив
    
    // Присваеваем элементы к новому масству
    for (int i = 0; i < size; i++)
     {
        newArr_del_zero[i] = arr[i];
     }
    //удаление нулей из массива
    if (newArr_del_zero[size - 1] == 0)	
     {
        size--; // каждый раз при удаление уменьшаем массив
     }
            
    for (int i = size-1; i != 0; i--) // считаем  массив с конца
      {
 
        if (newArr_del_zero[i] == 0)
        {
            for (int j = i; j < size ; j++)
                newArr_del_zero[j] = newArr_del_zero[j + 1];
            size--;
             break; // выходим как только нашли ноль
        }
     }
     
    delete[] arr; // удаляем старый массив
    arr = newArr_del_zero; // изменяем адрес, так как элемен передан по ссылке, то что мы с ним сделаем повлияет а указатель arr
}

void push_back(int *&arr, int &size, int value)
{
    size++; // увеличиваем массив на единицу
    int *newArr = new int[size]; // сoздаём новый массив больший на единицу
    
     if (value > 0 && value < size)// проверка правильности ввода
    {
        // Присваеваем элементы к новому масству
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
    
        // добавляем 100 после выбраной позиции value
        for (int i = size; i >= value-1; i--)
            {
                newArr[i+1] = arr[i];
                newArr[value-1] = 100;// добовляем значени 100
            }
    }else
        {
             cout <<  "Введенно не корретное значение позиции элемента" << endl;
             cout <<  "Введите значение с 1 по последеий элемент " << endl;
        }
        
    delete[] arr; // удаляем старый массив

    arr = newArr; // изменяем адрес, так как элемен передан по ссылке, то что мы с ним сделаем повлияет а указатель arr
}

int main()
{
    const int n = 150;
    int *arr = new int[n]; // указатель под массив и выделяем под него память
    int size = 100;
    int number = 1;
    cout << "Укажите размер массива от 0 до 100 :  ";
    cin >> size;
    
    FillArrey(arr, size); // вызываем функцию для создания массива
    cout << "Первоначальный массив  : "<< endl;

    ShowArray(arr, size); // вывод на экран первый созданый массив
    cout << "Массив после удаления нулей : "<< endl;
    del_zero(arr, size); // функция удаления нулей

    ShowArray(arr, size); // вывод на экранмассив  без нулей

    cout << "Укажите номер элемента после которого нужно добавить 100  - ";
    cin >> number;
    push_back(arr, size, number); // добавляем 100 после выбраного элемента

    cout << "Массив после добавления 100 в выбранный элемент: "<< endl;
    ShowArray(arr, size); // вывод на экран новый массив с добавлением 100
    
    delete[] arr;   // отчищаем память      
   
  return 0;
}