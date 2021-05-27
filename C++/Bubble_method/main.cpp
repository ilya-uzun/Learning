#include<iostream>
using namespace std;

int main()
{
    int *arr;
    int size;

    cout<<"n = ";
    cin >> size;

    if (size <= 0)
    {//проверка, чтобы массив небыл отрицательным
        cerr<<"Invalid size"<< endl;
        return 1; //Завершить програссу с ошибкой
    }
    arr = new int[size];

    for(int i=0; i < size; i++)
    {// вводим массив
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    // cортировка массива пузырьком
    for(int i = 0; i < size-1; i++)
    {
        for(int j=0; j < size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {//меняем элементы местами
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            }

        }
    }
    for(int i=0; i < size; i++)
    {// выводим массива
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}


