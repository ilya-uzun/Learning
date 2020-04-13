#pragma once
#include"Pair.h"

class Rightangled : public Pair 
{
public:

	Rightangled(void); //�������� ����������� ��� ���������� �������� ������ 
	Rightangled(int, int, int);//����������� � ����������� �������� ������
	Rightangled(const Rightangled&); //����������� 
	~Rightangled(void); //����������
	// ��������
	void set_hypatenuse(int);
	//������������ 
	int get_hypatenuse() { return hypatenuse; }
	// ���������� �������� ������������
	Rightangled& operator = (const Rightangled&);

	//����������  ��������� ������� �����-������
	friend std::istream& operator >> (std::istream& in,  Rightangled& rightangled);
	//int Hypatenuse(Rightangled& rightangled);
	friend std::ostream& operator << (std::ostream& out, const Rightangled& rightangled);

//��������
protected:
	int hypatenuse; 

};