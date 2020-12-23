#include <cstdio>
#include <iostream>

using namespace std;

int main()
{

	const int size = 257;
	char str[size];

	cout << " Введите слова не более 255:\n";
	fgets(str, size, stdin);

	//проверка, чтобы массив не был отрицателным
	if (size <= 0)
		{
			cerr<<"Invalid size"<< endl;
			return 1; //Завершить программу с ошибкой
		}

	cout << "\nБуквы отсортированы по возрастанию.:\n";

    // cортировка массива пузырьков
    for(int i = 0; i < size-1; i++)
    {
        for(int j=0; j < size-i-1; j++)
        {
            if(str[j]>str[j+1])
            {//меняем элементы местами
            int temp = str[j];
            str[j] = str[j+1];
            str[j+1] = temp;
            }
        }
    }
    for(int i=0; i < size; i++)
    {// выводим массива
        cout << str[i] << " ";
    }

return 0;
}
 	// Преобразовать строку так, чтобы все буквы в ней были отсортированы по возрастанию.


 

 