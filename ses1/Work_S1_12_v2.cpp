#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdarg>
#include <windows.h>

//Вариант 7

using namespace std;

struct l_list
{
	const char* data;
	l_list* prev;
	l_list* next;
};

void listAddEnd(l_list*& begin, const char* str)
{
	if (begin == nullptr)
  {
		begin = new l_list;
		begin->data = str;
		begin->prev = nullptr;
		begin->next = nullptr;
		return;
	}
	else
  {
		l_list* pbegin = begin;
		while (pbegin->next != nullptr)
			pbegin = pbegin->next;

		l_list* p = new l_list;
		p->data = str;
		pbegin->next = p;
		p->prev = pbegin;
		p->next = nullptr;
	}
}

l_list* listCreate(){
	l_list* begin = new l_list;
	begin = nullptr;
	return begin;
}

l_list* listCreate(int num, ...)
{

  l_list* begin = new l_list;
	begin = nullptr;

	va_list args;
	va_start(args, num);

	while (num > 0)
  {
		listAddEnd(begin, va_arg(args, const char*));
		num--;
	}
	va_end(args);
	return begin;
}

void listPrint(l_list* begin)
{
	if (begin == nullptr) {
		std::cout << "Список пуст.\n ";
		return;
	}
	cout << "  Конец списка" << endl;
	while (begin->next != nullptr)
  {
		cout << begin->data << "    ";
		begin = begin->next;
	}
	cout << begin->data << "  Конец списка " <<endl;
}

void listAddBegin(l_list*& begin, const char* str)
{
	if (begin == nullptr)
  {
		begin = new l_list;
		begin->data = str;
		begin->prev = nullptr;
		begin->next = nullptr;
		return;
	}
	else
  {
		l_list* p = new l_list;
		p->data = str;
		p->prev = nullptr;
		p->next = begin;
		begin->prev = p;
		begin = p;
	}
}
// добавить после элемента
void AddElement(l_list* begin, const char* key, const char* str)
{
	if (begin == nullptr)
		return;

	bool found = false;
	while (begin != nullptr){
		if (strcmp(begin->data, key) == 0)
    {
			found = true;
			break;
		}
		begin = begin->next;
	}

	if (found)
  {
		l_list* p = new l_list;
		p->data = str;
		p->next = begin->next;
		p->prev = begin;
		begin->next->prev = p;
		begin->next = p;
	}
	else
		cout << "Элемент не найден"<<endl;
}
//Удалить список
void Removelist(l_list*& begin, const char* str)
{
	if (begin == nullptr)
		return;

	l_list* pbegin = begin;
	bool found = false;

	while (pbegin != nullptr)
  {
		if (strcmp(pbegin->data, str) == 0)
    {
			found = true;
			break;
		}
		pbegin = pbegin->next;
	}

	if (found)
		if (pbegin->prev == nullptr)
    {
			l_list* p = begin;
			begin = begin->next;
			begin->prev = nullptr;
			delete p;
		}
		else if (pbegin->next == nullptr)
    {
			l_list* p = pbegin;
			pbegin = pbegin->prev;
			pbegin->next = nullptr;
			delete p;
		}
		else
    {
			pbegin->prev->next = pbegin->next;
			pbegin->next->prev = pbegin->prev;
			delete pbegin;
		}
	else
		cout << "Элемент не найден." << endl;
}
//удалить одинаковые элементы
void RemoveElements(l_list*& begin)
{
	if (begin == nullptr) return;

	l_list* p, * pbegin;
	pbegin = begin;

	while (pbegin->next != nullptr)
  {
		p = pbegin;
		int equal = 0;
		char elem[50];
		strcpy_s(elem, pbegin->data);

		while (p != nullptr)
    {
			if (strcmp(p->data, elem) == 0)
				equal++;
			p = p->next;
		}
		bool changedBegin = false;
		if (equal > 1)
			for (int i = 0; i < equal; i++)
				if (strcmp(begin->data, elem) == 0)
        {
					pbegin = begin->next;
					Removelist(begin, elem);
					begin = pbegin;
					changedBegin = true;
				}
				else
        {
					if (strcmp(pbegin->data, elem) == 0)
						if (pbegin->next != nullptr)
            {
							pbegin = pbegin->next;
							changedBegin = true;
						}
						else
            {
							Removelist(begin, elem);
							return;
						}
					Removelist(begin, elem);
				}
		if (!changedBegin) pbegin = pbegin->next;
	}
}

void WriteFile(l_list* begin, const char* filename)
{
	if (begin == nullptr) return;

	ofstream fout(filename, ios::out);

	if (!fout.is_open()){
	cout << "Не удалось открыть файл." << endl;
		return;
	}

	while (begin->next != nullptr)
  {
		fout << begin->data  << endl;
		begin = begin->next;
	}
	fout << begin->data;

	fout.close();
}

void listRead(l_list*& begin, const char* filename)
{
	ifstream fin(filename, ios::in);

	if (!fin.is_open()){
		cout << "Не удалось открыть файл."<< endl;
		return;
	}

	const int size = 50;
	char* str = new char[size];

	while (fin.getline(str, size))
  {
		listAddEnd(begin, str);
		str = new char[size];
	}
	delete[] str;
	fin.close();
}

void listDelete(l_list*& begin)
{
	if (begin == nullptr)return;

	while (begin != nullptr)
  {
		l_list* p = begin;
		begin = begin->next;
		delete p;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Создаем список..." << endl;
	l_list* List = listCreate(13, "Руслан", "Тимур", "Стас", "Алексей",
		"Матвей", "Илья", "Андрей", "  \nНиколай", "Станислав", "Фёдор", "Егор", "Стас", "Анатолий");
	cout << "Содержание:" << endl;
	listPrint(List);
	cout << "Удаляем элементы с одинаковыми ключевыми полями ..." << endl;
	RemoveElements(List);
	const char* elemToAdd = "Алексей";
	cout << "Добавляем элемент " << elemToAdd << " в список..." << endl;
	AddElement(List, "Леонид", elemToAdd);
	cout << "Списоксодержит:\n";
	listPrint(List);
	const char filename[15] = "myList.txt";
	cout << "Записываем  в файл..." << endl;
	WriteFile(List, filename);
	cout << "Удаляем список..." << endl;
	listDelete(List);
	listPrint(List);
	l_list* restoredList = listCreate();
	cout << "Восстанавливаем из файла..." << endl;
	listRead(restoredList, filename);
	cout << "Список содержит:" << endl;
	listPrint(restoredList);
	cout << "Удаляем ..." << endl;
	listDelete(restoredList);
	listPrint(List);

	system("pause");
	return 0;}
