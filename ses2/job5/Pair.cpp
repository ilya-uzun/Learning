#include "Pair.h"

// ���������� ��� ���������� 
Pair::Pair(void) {
	first = 0;
	second = 0;
}
//����������
Pair::~Pair(void) {}
//����������� � �����������
Pair::Pair(int F, int S) {
	first = F;
	second = S;
}
//����������� ����������� 
Pair::Pair(const Pair& pair) {
	first = pair.first;
	second = pair.second;
}
// ������������
int Pair::set_first(int F) {
	first = F;
	return first;
}
int Pair::set_second(int S) {
	second = S;
	return second;
}
// ���������� ���������� ������������
Pair& Pair::operator=(const Pair& pair) {
	if (&pair == this)return *this;
	first = pair.first;
	second = pair.second;
	return *this;
}

//���������� ������� ��� �����
istream& operator>>(istream& in, Pair& pair) {
	cout << "\n ������� (first) : ";
	in >> pair.first;
	cout << "\n ������� (second) : ";
	in >> pair.second;
	return in;
}
//���������� ������� ���  ������
ostream& operator <<(ostream& out, const Pair& pair) {
	out << "\n first  =" << pair.first;
	out << "\n second  =" << pair.second;
	return out;
}