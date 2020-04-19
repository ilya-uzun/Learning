#include "Pair.h"

// консруктор без параметров
Pair::Pair(void) {
	first = 0;
	second = 0;
}
//деструктор
Pair::~Pair(void) {}
//Конструктор с параметрами
Pair::Pair(int F, int S) {
	first = F;
	second = S;
}
//Конструктор копирования
Pair::Pair(const Pair& pair) {
	first = pair.first;
	second = pair.second;
}
// модификаторы
int Pair::set_first(int F) {
	first = F;
	return first;
}
int Pair::set_second(int S) {
	second = S;
	return second;
}
// перегрузка операторов присваивания
Pair& Pair::operator=(const Pair& pair) {
	if (&pair == this)return *this;
	first = pair.first;
	second = pair.second;
	return *this;
}

//глобальная функция для ввода
istream& operator>>(istream& in, Pair& pair) {
	cout << "\n введите (first) : ";
	in >> pair.first;
	cout << "\n введите (second) : ";
	in >> pair.second;
	return in;
}
//глобальная функция для  вывода
ostream& operator <<(ostream& out, const Pair& pair) {
	out << "\n first  =" << pair.first;
	out << "\n second  =" << pair.second;
	return out;
}
