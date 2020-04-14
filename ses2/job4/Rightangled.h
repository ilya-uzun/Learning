#pragma once
#include"Pair.h"

class Rightangled : public Pair
{
public:

	Rightangled(void); //вызываем конструктор без параметров базового класса
	Rightangled(int, int, int);//конструктор с параметрами базового класса
	Rightangled(const Rightangled&); //конструктор
	~Rightangled(void); //деструктор
	// селектор
	void set_hypatenuse(int);
	//модификаторы
	int get_hypatenuse() { return hypatenuse; }
	// перегрузка опирации присваивания
	Rightangled& operator = (const Rightangled&);

	//глобальные  операторы функции ввода-вывода
	friend std::istream& operator >> (std::istream& in,  Rightangled& rightangled);
	//int Hypatenuse(Rightangled& rightangled);
	friend std::ostream& operator << (std::ostream& out, const Rightangled& rightangled);

//атрибуты
protected:
	int hypatenuse;

};
