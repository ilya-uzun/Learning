#pragma once
#include <string>
#include <iostream>
//using namespace std;

class Pair {
	// ������������ ��� ����������
public:
	Pair(void);
	//����������
	virtual ~Pair(void);
	//����������� � �����������
	Pair(int, int);
	//����������� �����������
	Pair(const Pair&);
	//���������
	int get_first(){ return first; }
	int get_second() { return second; }
	//������������
	int set_first(int);
	int set_second(int);
	// ���������� �������� ������������
	Pair& operator= (const Pair&);
	//����������  ��������� ������� �����-������
	friend std::istream& operator >> (std::istream &in, Pair& pair);
	friend std::ostream& operator << (std::ostream &out, const Pair& pair);
//��������
protected:
	int first;
	int second;
};