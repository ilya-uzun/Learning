#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	srand(time(NULL));// нужет чтобы генератор считал каждый раз по новому
	const int n = 3;
	int matrix[n][n];
	int Tmatrix[n][n];
	int i, j;
	cout << "Изначальная матрица: \n\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 9;
			cout << matrix[i][j] << "\t";
		}
		cout << "\n\n";
	}
	cout << " Транспонированная  матрица: \n\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			Tmatrix[i][j] = matrix[j][i];
			cout << Tmatrix[i][j] << "\t";
		}
		cout << "\n\n";
	}

	cout << "Сумма матриц: \n\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++) cout << matrix[i][j] + Tmatrix[i][j] << "\t";
		cout << "\n\n";
	}
	return 0;}
