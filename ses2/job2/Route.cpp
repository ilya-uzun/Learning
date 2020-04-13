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
	cout << "Конструктор без параметров для объекта " << this << endl;
}
//  Конструктор c параметров
Route::Route(string N, string K, float S) {
	start = N;
	finish = K;
	time_in_way = S;
	cout << "Конструктор c параметров для объекта " << this << endl;
}
//  Конструктор копирования
Route::Route(const Route&t)
{
	start = t.start;
	finish = t.finish;
	time_in_way = t.time_in_way;
	cout << "Конструктор копирования для объекта " << this << endl;
}
//Деструктор
Route::~Route()
{
	cout << "Деструктор для объекта " << this << endl;
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
