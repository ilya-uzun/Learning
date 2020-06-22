#pragma once
#include "List.h"
#include <iostream>
using namespace std;
int main()
{
 List list;
	list.push_front(13).push_front(29).push_front(16);

	for (List::Iterator iter = list.start(); iter != list.end(); iter++)
		cout << iter.get() << " ";

	cout << endl;

	return 0;
}

