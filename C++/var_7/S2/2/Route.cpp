#include <iostream>
#include <string>
#include "Route.h"
using namespace std;

//  Конструктор без параметров
Route::Route()
{
	CPU = "";
	RAM = 0;
    HDD = 0;
	// this указатель на класс
	cout << "Constructor without parameters for the object " << this << endl;//Конструктор без параметров для объекта
}
//  Конструктор c параметров
Route::Route(string c, int K, int S) {
	CPU = c;
	RAM = K;
	HDD = S;
	cout << "Constructor with parameters for an object " << this << endl;//Конструктор c параметров для объекта 
}
//  Конструктор копирования
Route::Route(const Route&t)
{
	CPU = t.CPU;
	RAM = t.RAM;
	HDD = t.HDD;
	cout << "Copy constructor for an object " << this << endl;//Конструктор копирования для объекта 
}
//Деструктор
Route::~Route()
{
	cout << "Destructor for the object " << this << endl;//Деструктор для объекта 
}
//селекторы
string Route::get_CPU()
{
	return CPU;
}
int Route::get_RAM()
{
	return RAM;
}

int Route::get_HDD()
{
	return HDD;
}

//модификаторы
void Route::set_CPU(string N)
{
	CPU = N;
}

void Route::set_RAM(int K)
{
	RAM = K;
}

void Route::set_HDD(int S)
{
	HDD = S;
}

//Метод для просмотра атрибутов
void Route::show()
{
	cout << "CPU : " << CPU << endl;
	cout << "PAM : " << RAM << endl;
	cout << "HDD : " << HDD << endl;
}
