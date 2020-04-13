
#pragma once
#include <iostream>
using namespace std;
class Vector
{
public:
	//����������� � �����������: ��������  ������ ��� s ������� � ��������� ���������� �

	Vector(int s, int k = 0);
	//���������� ����������� 
	Vector(const Vector& a);
	//����������� � �����������
	~Vector();
	//����������
	Vector& operator=(const Vector& a);
	//�������� ������������
	int& operator[](int index);
	//�������� ������� �� �������
	Vector operator+(const int k);
	//�������� ��� ���������� ���������
	int operator()();
	// ������������� �������� �����-������
	friend ostream &operator << (ostream& out, const Vector& a);
	friend iostream &operator >> (iostream& out, const Vector& a);


	Iterator first() { return beg; } //���������� ��������� �� ������ �������
	Iterator last() { return end; } // ���������� ��. ��������� �� ���������

private:
	int size;//������ �������
	int* data;// ��������� �� ������������ ������ ������� �������

	//int size;
	//int* data;
	Iterator beg;//��������� �� ������ �������
	Iterator end;// �������� �� ������� �������� �� ���������

};

///----///----///----///----///----///----///----///----///

class Iterator
{
	friend class Vector;//��������� �����

public:
	Iterator() { emel = 0; }//����������� ��� ����������
	Iterator(const Iterator) { emel = it.elem; }//���������� �����������
	//������������� �������� ���������
	bool operator ==(const Iterator& it) { return elem == it.elem; }
	bool operator !=(const Iterator& it) { return elem != it.elem; }
	//������������� ��������  ���������
	void operator ++() { ++elem; }
	//������������� �������� ���������
	void operator --() { --elem; }
	//������������� �������� ������������
	int& operator *() const { return *elem; }



private:
	int* elem;// ��������� �� ������� ���� int


};