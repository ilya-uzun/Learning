#include <iostream>
#include <ctime>

using namespace std;


void FillArrey(int* const arr, const int size)
{
    // Создаём рандомный массив с числами от 0 до 10
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

void push_back(int *&arr, int &size, int value)
{
    // добавлениев массив
    // value - последий элемент массива или новой значение которое будем добавлять
    // int &size - размер массива, передача по ссылке & для того, что бы вернуть новое значение переменной
    // int *&arr - даёт возможность подменить адрес, что бы он указывал на новый массив 
    
    int *newArr = new int[size+1]; // свздаём новый массив больший на единицу
    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];// в каждый новый элемент вкладываем  элементы предыдущего
    }
    newArr[size] = value; // добовление в тоследнюю ячейку
    size++; // умеличиваем размер на единицу

    delete[] arr; // удаляем старый массив

    arr = newArr; // изменяем адрес, так как элемен передан по ссылке, то что мы с ним сделаем повлияет а указатель arr
}

void pop_back(int *&arr, int &size)
{
    // удаляем элемент из  массива
    size--; // уменьшаем размер на единицу
    int *newArr = new int[size]; // свздаём новый массив больший на единицу
    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];// в каждый новый элемент вкладываем  элементы предыдущего
    }  

    delete[] arr; // удаляем старый массив

    arr = newArr; // изменяем адрес, так как элемен передан по ссылке, то что мы с ним сделаем повлияет а указатель arr
}

int main()
{
    int size = 5;
    int *arr = new int[size]; // указатель под массив и выделяем под него память
    FillArrey(arr, size); // вызываем функцию для создания массива
    ShowArray(arr, size); // вывод на экран
    push_back(arr, size, 6);
    ShowArray(arr, size); // вывод на экран новый массив
    pop_back(arr, size);
    ShowArray(arr, size); // вывод на экран новый массив
    delete[] arr;         
   
  return 0;
}
