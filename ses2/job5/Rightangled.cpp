#include "Rightangled.h"
#include <iostream>
#include <math.h>

// консруктор без параметров
Rightangled::Rightangled(void):Pair() {
	 hypatenuse = 0;
}
//деструктор
Rightangled::~Rightangled(void) {}

void Rightangled::Show()
{
	std::cout<<"\n first"<<first;
	std::cout<<"\n second"<<second;
	std::cout<<"\n hypatenuse"<<hypatenuse;
	std::cout<<"\n";
}

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

int Rightangled::Hypatenuse()
{
	return (hypatenuse = (pow(first, 2) + pow(second, 2)));
}

//перегрузка операторов присваивания
Rightangled& Rightangled::operator=(const Rightangled& rightangled)
{
	if (&rightangled == this)return *this;
	hypatenuse = rightangled.hypatenuse;
	first = rightangled.first;
	second = rightangled.second;
	return *this;
};

std::istream& operator >> (std::istream& in,  Rightangled& rightangled)
{
	 std::cout << " Input (first) class Rightangled = ";// ввод first
	 in >> rightangled.first;
	 std::cout << " Input (second) class Rightangled = "; // ввод second
	 in >> rightangled.second;
	 return in;
}

//глобальная функция для  вывода
std::ostream& operator <<(std::ostream& out, const Rightangled& rightangled) {
	out << " \n Hypatenuse  = " << rightangled.hypatenuse;
	out << " \n First  = " << rightangled.first ;
	out << " \n Second  = " << rightangled.second ;
	return out;
}
