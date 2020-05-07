#pragma once
#include <iostream>
#include "Person.h"

Person::Person(void)
{
	name = "";
	age = 0;
}
//деструктор
Person::~Person(void){}
//констрктор с параметрами
Person::Person(std::string N, int A)
{
	name = N;
	age = A;
}
//конструктор копирования
Person::Person(const Person& Person)
{
	name = Person.name;
	age = Person.age;
}
//селекторы

void Person::Set_name(std::string N)
{
	name = N;
}

void Person::Set_age(int A)
{
	age = A;
}
//оператор присваивания
Person& Person::operator=(const Person&c)
{
if(&c == this) return *this;
name = c.name;
age = c.age;
return *this;
}
//метод для просмотра атрибутов
void Person::Show()
 {
std::cout <<"\n name : " <<name;
std::cout <<"\n age : " <<age;
std::cout <<"\n";
 }
//метод для ввода значений атрибутов
void Person::Input()
{
 std::cout << "\nname:"; 
 std::cin >> name;
 std::cout << "\nPower:";
 std::cout << "\nage:";
 std::cin >> age;
}