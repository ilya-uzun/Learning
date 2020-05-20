#pragma once
#include <iostream>
#include <string>
#include "Object.h"

class  Person : public Object
{
public:
	Person(void);//конструктор без параметров
public:
	virtual ~Person(void);//деструктор
	void Show();//функция для просмотра атрибутов класса с помощью указателя
	void Input();//функция для ввода значений атрибутов
	Person(std::string, int);//конструктор с параметрами
	Person(const Person&);//конструктор копирования
	//селекторы./
	std::string Get_name(){return name;}
	int Get_age(){return age;}

	//модификаторы
	void Set_name(std::string);
	void Set_age(int);

	Person& operator=(const Person&);//перегрузка операции присваивания
	void HandleEvent(const TEvent &e); // для событий
protected:
	std::string name;
	int age;
};
