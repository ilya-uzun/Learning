#pragma once
#include <iostream>
#include "fraction.h"
using namespace std;

fraction make_fraction(int F, int S) {
	fraction t;
	t.Init();
	return t;
}

int main()
{

	// статическая инициализация структуры
	cout << "Static initialization of the structure :" << endl;

	fraction A;
	A.Init();
	A.Show();

	// Динамическая инициализация структуры
	cout << "Dynamic structure initialization." << endl;

	fraction* X = new fraction;
	X->Init();
	X->Show();

	// Инициализация статичекого массива структуры
	cout << "Initializing a static array of a structure." << endl;

	fraction mas[3];
	for (int i = 0; i < 3; i++) mas[i].Init();
	for (int i = 0; i < 3; i++) mas[i].Show();


	// Инициализация динамического массива структуры
	cout << "Initializing a dynamic array of a structure." << endl;
	fraction* p_mas = new fraction[3];
	for (int i = 0; i < 3; i++) p_mas[i].Init();
	for (int i = 0; i < 3; i++) p_mas[i].Show();

	// Инициализация через make_

	cout << "Initialization via make_ " << endl;
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
