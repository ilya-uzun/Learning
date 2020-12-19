#include <iostream>
#include <iomanip>

#include <time.h>
using namespace std;


void FillArrey(int **matrix_1, int nR, int nC)
{
    // Создаём рандомный массив с числами от 0 до 5, что-бы чаще совпадали первые элементы 
	srand(time(0)); //позволяет запускать программу несколько раз, иначе одинаковые значения
   	for (int  i= 0; i < nR; i++)
	 {
		for (int j = 0; j < nC; j++)
		{
			matrix_1[i][j] = rand() % 5;	
		}
	 }
}

void ShowArray(int **matrix_1, int nR, int nC)
{
    // Выводим массив
	for (int  i= 0; i < nR; i++)
	 {
		for (int j = 0; j < nC; j++)
		{
			cout << matrix_1[i][j] << " ";
		}
		cout << endl;
	 }  
}
void ChangeArrey(int **matrix_1, int nR, int nC)
  {

      int  x=0, y=1, temp;
 
      
    // Выводим массив
	for (int  i= 0; i < nR; i++)
	 {
	    temp = matrix_1[i][x];
        matrix_1[i][x] = matrix_1[i][y];
        matrix_1[i][y] = temp;
		cout << endl;    
	 } 

  }


int main()
{
	const int nRow = 5;// строки
	const int nCol = 5;// столбцы
	int **matrix_1= new int* [nRow];// указатель на указатель типа int, память под массив указателей на строки массива
	int i,j;
	// Цикл для выделение памяти под каждую строку
	for (i=0; i<nRow; i++)
	  {
		matrix_1[i] = new int[nCol]; // каждому элементу указателей на сроку присваиваим адрес начала участка памяти
	  }

	FillArrey(matrix_1, nRow, nCol); // вызываем функцию для создания массива
    ShowArray(matrix_1, nRow, nCol); // вывод на экран
	ChangeArrey(matrix_1, nRow, nCol); // изменяем массив
    ShowArray(matrix_1, nRow, nCol); // вывод на экран
	delete[] matrix_1;
	return 0;
}


/* вроде рабочий код

const int n = 3;
const int m = 3;
int mass[n][m];
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        mass[i][j] = rand() % 5;
        std::cout << mass[i][j] << " ";
    }
    std::cout << std::endl;
}

for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        for (int s = i; s < n; s++)
        {
            for (int t = j + 1; t < m; t++)
                if (mass[i][j] == mass[s][t])
                {
                    std::cout << "mass[" << i << "][ " << j <<
                        "] == mass[ " << s << "][" << t << "]" << std::endl;
                }
        }
    }
*/