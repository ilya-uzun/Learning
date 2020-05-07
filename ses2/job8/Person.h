#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class  Person : public Object

{
	int min, sec;
public:
	Person(void);//конструктор без параметров
public:
	virtual ~Person(void);//деструктор
	void Show();//функция для просмотра атрибутов класса с помощью указателя
	void Input();//функция для ввода значений атрибутов
	Person(string,int,int);//конструктор с параметрами
	Person(const Person&);//конструктор копирования
	//селекторы
	string Get_mark(){return mark;}
	int Get_cyl(){return cyl;}
	int Get_power(){return power;}
	//модификаторы
	void Set_mark(string);
	void Set_cyl(int);
	void Set_power(int);
	Person& operator=(const Person&);//перегрузка операции присваивания
	protected:
	string mark;
	int cyl;
	int power;
};
