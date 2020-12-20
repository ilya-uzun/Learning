#include <iostream>
#include <iomanip>
#include <time.h>// генератор случайных чисел
using namespace std;

void FillArrey(int **matrix, int nR, int nC)
{
    // Создаём рандомный массив с числами от 0 до 5, что-бы чаще совпадали первые элементы 
	srand(time(0)); //позволяет запускать программу несколько раз, иначе одинаковые значения
   	for (int  i= 0; i < nR; ++i)
	 {
		for (int j = 0; j < nC; ++j)
		{
			matrix[i][j] = rand() % 5;	
		}
	 }
}

void ShowArray(int **matrix, int nR, int nC)
{
    // Выводим массив
	for (int  i= 0; i < nR; ++i)
	 {
		for (int j = 0; j < nC; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	 } 
}
void ChangeArrey(int **matrix, int nR, int nC)
  {

      int  x=0, y=1, temp;
 
 
     // Выводим массив
	for (int  i= 0; i < nR; ++i)
	 {
		for (int j = 0; j < nC; ++j)
		{
			if (matrix[0][0]==matrix[0][1]) {x=0; y=1;}
			else if (matrix[0][0]==matrix[0][2]) {x=0; y=2;}
			else if (matrix[0][0]==matrix[0][3]) {x=0; y=3;}
			else if (matrix[0][0]==matrix[0][4]) {x=0; y=4;}
			else if (matrix[0][1]==matrix[0][2]) {x=1; y=2;}
			else if (matrix[0][1]==matrix[0][3]) {x=1; y=3;}
			else if (matrix[0][1]==matrix[0][4]) {x=1; y=4;}
			else if (matrix[0][2]==matrix[0][3]) {x=2; y=3;}
			else if (matrix[0][3]==matrix[0][4]) {x=3; y=4;}			
		}
	 } 
      
    // Выводим массив
	for (int  i= 0; i < nR; ++i)
	 {
	    temp = matrix[i][x];
        matrix[i][x] = matrix[i][y];
        matrix[i][y] = temp;
		cout << endl;    
	 } 
  }

int main()
{
	const int nRow = 5;// строки
	const int nCol = 5;// столбцы
	int **matrix= new int* [nRow];// указатель на указатель типа int, память под массив указателей на строки массива

	// Цикл для выделение памяти под каждую строку
	for (int i=0; i < nRow; ++i)
	  {
		matrix[i] = new int[nCol]; // каждому элементу указателей на сроку присваиваим адрес начала участка памяти
	  }

	FillArrey(matrix, nRow, nCol); // вызываем функцию для создания массива
    ShowArray(matrix, nRow, nCol); // вывод на экран
	ChangeArrey(matrix, nRow, nCol); // изменяем массив
    ShowArray(matrix, nRow, nCol); // вывод на экран
	delete[] matrix;
	return 0;
}


