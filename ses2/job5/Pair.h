#pragma once
#include <string>
#include <iostream>
#include "Object.h"

using namespace std;
class Pair:
public Object{
	// ������������ ��� ����������
public:
	Pair(void);
public:
	//����������
	virtual ~Pair(void);
	void Show(); // ������� ��� ���������� ������ � ������� ���������
	//����������� � �����������
	Pair(int, int);
	//����������� �����������
	Pair(const Pair&);
	//���������
	int get_first() { return first; }
	int get_second() { return second; }
	//������������
	int set_first(int);
	int set_second(int);
	// ���������� �������� ������������
	Pair& operator= (const Pair&);
	//����������  ��������� ������� �����-������
	friend istream& operator >> (istream& in, Pair& pair);
	friend ostream& operator << (ostream& out, const Pair& pair);
	//��������
protected:
	int first;
	int second;
};

