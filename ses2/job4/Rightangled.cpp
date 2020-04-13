#include "Rightangled.h"
#include"Pair.h"
#include <iostream>
#include <math.h>

// ���������� ��� ���������� 
Rightangled::Rightangled(void):Pair() {
	 hypatenuse = 0;
}
//����������
Rightangled::~Rightangled(void) {}

//����������� � �����������
Rightangled::Rightangled(int F, int S, int H): Pair( F, S) 
{
	hypatenuse = H;
}

//����������� ����������� 
Rightangled::Rightangled(const Rightangled& rightangled) 
{
	hypatenuse = rightangled.hypatenuse;
	first = rightangled.first;
	second = rightangled.second;
}
// ������������
void Rightangled::set_hypatenuse(int H) 
{
	hypatenuse = H;
}

// ���������� ���������� ������������
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
	 std::cout << "\n first  = ";
	 in >> rightangled.first;
	 std::cout << "\n second  = ";
	 in >> rightangled.second;
	 return in;
};


//���������� ������� ���  ������
std::ostream& operator <<(std::ostream& out, const Rightangled& rightangled) {
	int hys = (pow(rightangled.first, 2) + pow(rightangled.second, 2));
	out << "\n hypatenuse  = " << hys;
	out << "\n first  = " << rightangled.first;
	out << "\n second  = " << rightangled.second;
	return out;
}


	