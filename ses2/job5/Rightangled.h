#pragma once
#include "Pair.h"

class Rightangled :
	public Pair
{
//Rightangled() : Pair() {}; //�������� ����������� ��� ���������� �������� ������
//Rightangled() : Pair() { int A, int B; } //����������� � ����������� �������� ������
//Rightangled(const Rightangled&); //����������� 
	Rightangled(void); //�������� ����������� ��� ���������� �������� ������
	Rightangled(int, int, int);//����������� � ����������� �������� ������
	Rightangled(const Rightangled&); //����������� 
	~Rightangled(void); //���������� 
	// ��������
	void set_hypatenuse(int);
	//������������ 
	int get_hypatenuse() { return hypatenuse; }
	// ���������� �������� ������������16+
	Rightangled& operator = (const Rightangled&);

	//����������  ��������� ������� �����-������
	friend istream& operator >> (istream& in, Rightangled& rightangled);
	//int Hypatenuse(Rightangled& rightangled);
	friend ostream& operator << (ostream& out, const Rightangled& rightangled);
	//��������
protected:
	int hypatenuse;
};

