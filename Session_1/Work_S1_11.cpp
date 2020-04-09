#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int arraySize(const int& limit)
{
	cout << "Введите размер массива, не превышающий " << limit << ":";
	int size;
	cin >> size;
	while (size > limit || cin.fail())
  {
		if (cin.fail())
    {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Вы ввели недопустимый символ, по-пробуйте снова: ";
			cin >> size;
		}
		else
    {
			cout << "Вы превысили допустимый размер, по-пробуйте снова: ";
			cin >> size;
		}
	}
	return size;
}

void arrayCopy(int* arrSet, const int* arrGet, const int& size)
{
	for (int i = 0; i < size; i++)
		*(arrSet + i) = *(arrGet + i);
}

void arrayFill(int* arr, const int& size){
	srand(time(nullptr));
	for (int i = 0; i < size; i++) *(arr + i) = std::rand() % 10;
}

void arrayPrint(const int* arr, const int& size)
{
	for (int i = 0; i < size; i++) cout << *(arr + i) << ' ';
}

int arrayMinValue(const int* arr, const int& size)
{
	int min = *arr;
	for (int i = 1; i < size; i++) if (*(arr + i) < min) min = *(arr + i);
	return min;
}

int arrayAverageValue(const int* arr, const int& size)
{
	double sum = 0;
	for (int i = 0; i < size; i++) sum += *(arr + i);
	return (int)(sum / size);
}

void arrayAddElementBegin(int* arr, int& size, const int& val)
{
	for (int i = size; i > 0; i--) *(arr + i) = *(arr + (i - 1));
	*arr = val;
	size++;
}

void arrayDeleteElement(int* arr, int& size, const int& val)
{
	if (*(arr + (size - 1)) == val)
		size--;

	for (int i = 0; i < size; i++)
		if (*(arr + i) == val && *(arr + (i + 1)) == val){
			for (int j = i; j < size - 2; j++) *(arr + j) = *(arr + (j + 2));
			size -= 2;
		}
		else if (*(arr + i) == val){
			for (int j = i; j < size - 1; j++) *(arr + j) = *(arr + (j + 1));
			size--;
		}
}

int main()
{
	setlocale(LC_ALL, "rus");

	const int n = 210;
	int* mainArray = new int[n];
	int size = arraySize(n);

	arrayFill(mainArray, size);
	std::cout << "\nИсходныймассивсодержит:\n";
	arrayPrint(mainArray, size);

	int* resultArray = new int[n];
	arrayCopy(resultArray, mainArray, size);

	int minValue = arrayMinValue(resultArray, size);
	arrayDeleteElement(resultArray, size, minValue);

	for (int i = 1; i <= 3; i++)
	{
		int avgValue = arrayAverageValue(resultArray, size);
		arrayAddElementBegin(resultArray, size, avgValue);
	}

	std::cout << "\n\nОтредактированныймассивсодержит:\n";
	arrayPrint(resultArray, size);

	delete[] mainArray;
	delete[] resultArray;

	std::cout << "\n\n";
	system("pause");
	return 0;
}
