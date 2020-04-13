#include<iostream>
#include <fstream>
#include <cstdio>
#include <windows.h>

using namespace std;

	typedef struct {
	char name[31];
	char capital[31];
	int population;
	int square;
    }STATE;

STATE createState(){
	STATE newSTATE;

	cout << "Введите название государства: ";
	cin >> newSTATE.name;
	cout << "Введите название столицы государства: ";
	cin >> newSTATE.capital;
	cout << "Введите численность населения государства: ";
	cin >> newSTATE.population;

	if (cin.fail()){
		cerr << "\n\nОшибка: введен некорректный символ. Завершениепрограммы...\n";
		exit(EXIT_FAILURE);
	}
	cout << "Введите площадь территории, занимаемой государством: ";
	cin >> newSTATE.square;

	if (cin.fail()){
		cerr << "\n\nОшибка: введен некорректный символ. Заверешение программы...\n";
		exit(EXIT_FAILURE);
	}
	return newSTATE;
}

void StateFileEnd(const char* filename, const STATE& countryToAdd) {//добавить страну в конец файла
	ofstream fout(filename, ios::binary | ios::out | ios::app);

	if (!fout.is_open())
	{
		cerr << "Не удалось открыть файл. Завершение программы...";
		exit(EXIT_FAILURE);
	}

	fout.write((char*)&countryToAdd, sizeof(countryToAdd));
	fout.close();
}
//добавить страну в файл после элемента
void AddState(const char* filename, const int& num,const STATE& countryToAdd){

	if (num < 1) return;

	ifstream f1(filename, ios::binary | ios::in);

	if (!f1.is_open()){
		cerr << "Не удалось открыть файл. Завершение программы...";
		exit(EXIT_FAILURE);
	}

	int fileSize = 0;

	STATE tmp;
	while (f1.read((char*)&tmp, sizeof(tmp))) fileSize++;

	f1.clear();
	f1.seekg(0, ios::beg);

	if (fileSize == 0 || num >= fileSize){
		f1.close();
		StateFileEnd(filename, countryToAdd);
		cout << "Запись эелемента в файл прошла успешно.\n\n";
	}
	else{
		ofstream f2("tmp.bin", ios::binary | ios::out | ios::app);

		if (!f2.is_open()){
			cerr << "Не удалось открыть файл. Завершение программы...";
			exit(EXIT_FAILURE);
		}

		int count = 0;
		STATE tmp;

		while (count != num){
			f1.read((char*)&tmp, sizeof(tmp));
			f2.write((char*)&tmp, sizeof(tmp));
			count++;
		}

		f2.write((char*)&countryToAdd, sizeof(countryToAdd));

		while (f1.read((char*)&tmp, sizeof(tmp)))

		f2.write((char*)&tmp, sizeof(tmp));

		if (f1.eof()) cout << "Запись элелемента в файл прошла успешно.\n\n";
		else {
			cerr << "Произошел сбой при чтении файла. Завершение программы...";
			exit(EXIT_FAILURE);
		}

		f1.close();
		f2.close();

		if (rename(filename, "prev.bin")){
			cerr << "Аварийное завершение программы...";
			exit(EXIT_FAILURE);
		}
		if (rename("tmp.bin", filename)){
			cerr << "Аварийное завершение программы...";
			exit(EXIT_FAILURE);
		}
		remove("prev.bin");
	}
}

//удалить из файла в зависимости от населения
void DelFileMinPopulation(const char* filename, const int& limit)
{
	ifstream f1(filename, ios::binary | ios::in);
	ofstream f2("tmp.bin", ios::binary | ios::out);
  // Закрытие программы если не удалось открыть файл
	if (!f1.is_open() || !f2.is_open())
  {
	  cerr << "Не удалось открыть файл. Завершение программы...";
  	exit(EXIT_FAILURE);
	}

	STATE tmp;
	while (f1.read((char*)&tmp, sizeof(tmp)))
  {
		if (tmp.population > limit) f2.write((char*)&tmp, sizeof(tmp));
		else continue;
	}

	if (f1.eof()) cout << "Удаление элементов из файла прошло успешно.\n\n";
	else
  {
		cerr << "Произошел сбой при чтении файла. Завершение программы...";
		exit(EXIT_FAILURE);
	}

	f1.close();
	f2.close();

	if (rename(filename, "prev.bin"))
  {
		cerr << "Аварийное завершение программы...";
		exit(EXIT_FAILURE);
	}

	if (rename("tmp.bin", filename))
  {
		cerr << "Аварийное завершение программы...";
		exit(EXIT_FAILURE);
	}
	remove("prev.bin");
}

void PrintFile(const char* filename)
{
	ifstream fin(filename, ios::binary | ios::in);

	if (!fin.is_open()){
		cerr << "Не удалось открыть файл. Завершение программы...";
		exit(EXIT_FAILURE);
	}

	cout << "Файл " << filename << " содержит:\n\n";

	bool isEmpty = true;
	STATE tmp;
	while (fin.read((char*)&tmp, sizeof(tmp)))
  {
		isEmpty = false;
		cout << tmp.name << '\n' << tmp.capital << '\n' << tmp.population << '\n' << tmp.square << "\n\n";
	}

	if (isEmpty)
  {
		cout << "Файл пуст.\n\n";
		fin.close();
		return;
	}

	if (fin.eof()) cout << "Файл прочитан.\n\n";
	else
  {
		cerr << "Произошел сбой при чтении файла. Завершение программы...";
		fin.close();
		exit(EXIT_FAILURE);
	}
	fin.close();
}

int main()
{
  setlocale(LC_CTYPE, "Russian");
	STATE newSTATE;
	cout << "Укажите количество стран: ";
	int n;
	cin >> n;
	cout <<endl;

	const char* filename = "Countries.bin";

	for (int i = 0; i < n; i++)
  {
		STATE tmp = createState();
		cout << "Записываем государство " << tmp.name << " в файл "<< filename << "...\n\n";
		StateFileEnd(filename, tmp);
	}

	PrintFile(filename);

	const int limit = 20000000;
	cout << "Удаляем информацию о государствах, с малым количеством населения из файла " <<filename<< "...\n\n";
	DelFileMinPopulation(filename, limit);
	cout << "Укажите информацию о государстве, которое хотите добавить в файл.\n\n";
	newSTATE = createState();
	cout << "\nУкажите позицию, которую государство должно занять(кроме 1) : ";
	int num;
	cin >> num;
	cout << endl;
	cout << "Добавляем государство " << newSTATE.name << " в файл "<< filename << "...\n\n";
	AddState(filename, num - 1, newSTATE);
	PrintFile(filename);

	return 0;
}
