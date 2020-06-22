#include <iostream>
#include <string>
#include "Route.h"
using namespace std;

//  Конструктор без параметров
Route::Route()
{
	start = "";
	finish = "";
	time_in_way = 0.0;
	// this указатель на класс
	cout << "Constructor without parameters for the object " << this << endl;//Конструктор без параметров для объекта
}
//  Конструктор c параметров
Route::Route(string N, string K, float S) {
	start = N;
	finish = K;
	time_in_way = S;
	cout << "Constructor with parameters for an object " << this << endl;//Конструктор c параметров для объекта 
}
//  Конструктор копирования
Route::Route(const Route&t)
{
	start = t.start;
	finish = t.finish;
	time_in_way = t.time_in_way;
	cout << "Copy constructor for an object " << this << endl;//Конструктор копирования для объекта 
}
//Деструктор
Route::~Route()
{
	cout << "Destructor for the object " << this << endl;//Деструктор для объекта 
}
//селекторы
string Route::get_start()
{
	return start;
}
string Route::get_finish()
{
	return finish;
}
float Route::get_time_in_way()
{
	return time_in_way;
}

//модификаторыs
void Route::set_start(string N)
{
	start = N;
}
void Route::set_finish(string K)
{
	finish = K;
}
void Route::set_time_in_way(float S)
{
	time_in_way = S;
}

//Метод для просмотра атрибутов
void Route::show()
{
	cout << "start : " << start << endl;
	cout << "finish : " << finish << endl;
	cout << "time_in_way : " << time_in_way << endl;
}
