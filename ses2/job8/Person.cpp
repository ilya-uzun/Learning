#pragma once
#include <iostream>
#include "Person.h"

Person::Person(void)
{
	mark="";
	cyl=0;
	power=0;
}
//деструктор
Person::~Person(void){}
//констрктор с параметрами
Person::Person(string M,int C,int P)
{
	mark=M;
	cyl=C;
	power=P;
}
//конструктор копирования
Person::Person(const Person& Person)
{
	mark=Person.mark;
	cyl=Person.cyl;
	power=Person.power;
}
//селекторы
void Person::Set_cyl(int C)
{
	cyl = C;
}
void Person::Set_mark(string M)
{
	mark = M;
}
void Person::Set_power(int P)
{
	power=P;
}
//оператор присваивания
Person& Person::operator=(const Person&c)
{
if(&c==this)return *this;
mark=c.mark;
power=c.power;
cyl=c.cyl;
return *this;
}
//метод для просмотра атрибутов
void Person::Show()
 {
cout<<"\nMARK : "<<mark;
cout<<"\nCYL : "<<cyl;
cout<<"\nPOWER : "<<power;
cout<<"\n";
 }
//метод для ввода значений атрибутов
void Person::Input()
{
 cout<<"\nMark:"; cin>>mark;
cout<<"\nPower:";cin>>power;
cout<<"\nCyl:";cin>>cyl;
}