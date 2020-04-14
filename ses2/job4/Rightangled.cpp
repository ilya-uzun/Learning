#include "Rightangled.h"
#include"Pair.h"
#include <iostream>
#include <math.h>

// консруктор без параметров
Rightangled::Rightangled(void):Pair() {
	 hypatenuse = 0;
}
//деструктор
Rightangled::~Rightangled(void) {}

//Конструктор с параметрами
Rightangled::Rightangled(int F, int S, int H): Pair( F, S)
{
	hypatenuse = H;
}

//Конструктор копирования
Rightangled::Rightangled(const Rightangled& rightangled)
{
	hypatenuse = rightangled.hypatenuse;
	first = rightangled.first;
	second = rightangled.second;
}
// модификаторы
void Rightangled::set_hypatenuse(int H)
{
	hypatenuse = H;
}

// перегрузка операторов присваивания
Rightangled& Rightangled::operator=(const Rightangled& rightangled)
{
	if (&rightangled == this)return *this;
	hypatenuse = rightangled.hypatenuse;
	first = rightangled.first;
	second = rightangled.second;

	return *this;
}

std::istream& operator >> (std::istream& in,  Rightangled& rightangled)
{
	 //cout << "\n (b hypatenuse)  = ";
	 //in >> rightangled.hypatenuse;
	 std::cout << " first  = ";
	 in >> rightangled.first;
	 std::cout << " second  = ";
	 in >> rightangled.second;
	 return in;
};


//глобальная функция для  вывода
std::ostream& operator <<(std::ostream& out, const Rightangled& rightangled) {
	int hys = (pow(rightangled.first, 2) + pow(rightangled.second, 2));
	out << " hypatenuse  = " << hys;
	out << " first  = " << rightangled.first;
	out << " second  = " << rightangled.second;
	return out;
}
