#include "Rightangled.h"

// консруктор без параметров
Rightangled::Rightangled(void) :Pair() {
	hypatenuse = 0;
}
//деструктор 
Rightangled::~Rightangled(void) {}

//Конструктор с параметрами
Rightangled::Rightangled(int F, int S, int H) : Pair(F, S) {
	hypatenuse = H;
}

//Конструктор копирования 
Rightangled::Rightangled(const Rightangled& rightangled) {
	hypatenuse = rightangled.hypatenuse;
	first = rightangled.first;
	second = rightangled.second;
}
// модификаторы
void Rightangled::set_hypatenuse(int H) {
	hypatenuse = H;
}

// перегрузка операторов присваивания
Rightangled& Rightangled::operator=(const Rightangled& rightangled) {
	if (&rightangled == this)return *this;
	hypatenuse = rightangled.hypatenuse;
	first = rightangled.first;
	second = rightangled.second;

	return *this;
}

istream& operator >> (istream& in, Rightangled& rightangled) {
	//cout << "\n (b hypatenuse)  = ";
	//in >> rightangled.hypatenuse;
	cout << "\n first  = ";
	in >> rightangled.first;
	cout << "\n second  = ";
	in >> rightangled.second;
	return in;
};


//глобальная функция для  вывода
ostream& operator <<(ostream& out, const Rightangled& rightangled) {
	int hys = (pow(rightangled.first, 2) + pow(rightangled.second, 2));
	out << "\n hypatenuse  = " << hys;
	out << "\n first  = " << rightangled.first;
	out << "\n second  = " << rightangled.second;
	return out;
}
