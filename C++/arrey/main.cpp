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

void push_back(int *&arr, int &size, int value)
{
    size++;
    int *newArr = new int[size+1]; // сoздаём новый массив больший на единицу
    
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

void pop_back(int *&arr, int &size)
{
    // удаляем элемент из  массива
    size--; // уменьшаем размер на единицу
    int *newArr = new int[size]; // создаём новый массив больший на единицу
    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];// в каждый новый элемент вкладываем  элементы предыдущего
    }  

    delete[] arr; // удаляем старый массив

    arr = newArr; // изменяем адрес, так как элемен передан по ссылке, то что мы с ним сделаем повлияет а указатель arr
}

int main()
{
    int size = 100;
    int *arr = new int[size]; // указатель под массив и выделяем под него память
    FillArrey(arr, size); // вызываем функцию для создания массива
    ShowArray(arr, size); // вывод на экран
    push_back(arr, size, 6);
    ShowArray(arr, size); // вывод на экран новый массив
    //pop_back(arr, size);
    //ShowArray(arr, size); // вывод на экран новый массив
    delete[] arr;         
   
  return 0;
}