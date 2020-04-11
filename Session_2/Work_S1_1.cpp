#include <iostream>
#include "fraction.h"
#include	<windows.h>
using namespace std;

fraction make_fraction(int F, int S) {
	fraction t;
	t.Init();
	return t;
}

int main()
{
	SetConsoleCP(866);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(866); // для вывода


	// статическая инициализация структуры
	cout << "Cтатическая инициализация структуры :" << endl;

	fraction A;
	A.Init();
	A.Show();

	// Динамическая инициализация структуры
	cout << "Динамическая инициализация структуры." << endl;

	fraction* X = new fraction;
	X->Init();
	X->Show();

	// Инициализация статичекого массива структуры
	cout << "Инициализация статичекого массива структуры." << endl;

	fraction mas[3];
	for (int i = 0; i < 3; i++) mas[i].Init();
	for (int i = 0; i < 3; i++) mas[i].Show();


	// Инициализация динамического массива структуры
	cout << "Инициализация динамического массива структуры." << endl;
	fraction* p_mas = new fraction[3];
	for (int i = 0; i < 3; i++) p_mas[i].Init();
	for (int i = 0; i < 3; i++) p_mas[i].Show();

	// Инициализация через make_

	cout << "Инициализация через make_ " << endl;
	double y;
	int z;
	cout << "first? ";
	cin >> y;
	cout << "second? ";
	cin >> z;
	//
	fraction F = make_fraction(y, z);
	F.Show();
	delete X;
	delete p_mas;
	return 0;
}
