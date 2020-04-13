#pragma once
#include "Pair.h"

class Rightangled :
	public Pair
{
//Rightangled() : Pair() {}; //вызываем конструктор без параметров базового класса
//Rightangled() : Pair() { int A, int B; } //конструктор с параметрами базового класса
//Rightangled(const Rightangled&); //конструктор 
	Rightangled(void); //вызываем конструктор без параметров базового класса
	Rightangled(int, int, int);//конструктор с параметрами базового класса
	Rightangled(const Rightangled&); //конструктор 
	~Rightangled(void); //деструктор 
	// селектор
	void set_hypatenuse(int);
	//модификаторы 
	int get_hypatenuse() { return hypatenuse; }
	// перегрузка опирации присваивания16+
	Rightangled& operator = (const Rightangled&);

	//глобальные  операторы функции ввода-вывода
	friend istream& operator >> (istream& in, Rightangled& rightangled);
	//int Hypatenuse(Rightangled& rightangled);
	friend ostream& operator << (ostream& out, const Rightangled& rightangled);
	//атрибуты
protected:
	int hypatenuse;
};

