#include "List.h"
#include <iostream>

List& List::push_front(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->pNext = pFirst;
	pFirst = temp;
	return *this;
}

int& List::operator [] (int index)
{
	Node* temp = pFirst;
	for (int i = 0; i < index; i++)
		temp = temp->pNext;
	return temp->data;
}

List::Iterator& List::Iterator::operator ++ ()
{
	iter = iter->pNext;
	return *this;
}

List::Iterator List::Iterator::operator ++ (int)
{
	List::Iterator temp(iter);
	iter = iter->pNext;
	return temp;
}

int& List::Iterator::get()
{
	return iter->data;
}

bool List::Iterator::operator != (Iterator right)
{
	return bool(iter != right.iter);
}

List::Iterator List::start()
{
	return List::Iterator(pFirst);
}

List::Iterator List::end()
{
	return List::Iterator(NULL);
}