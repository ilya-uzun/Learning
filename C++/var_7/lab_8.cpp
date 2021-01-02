#include<iostream>
#include <fstream>
#include <cstdio>


using namespace std;

	typedef struct {
		char name[31];
		char capital[31];
		int group; // номер группы
		float rating; // рейтинг студента rating
    }STATE; //student STUDENT

STATE createState(){
	STATE newSTATE;

	cout << "Введите название государства: ";
	cin >> newSTATE.name;
	cout << "Введите название столицы государства: ";
	cin >> newSTATE.capital;
	cout << "Введите численность населения государства: ";
	cin >> newSTATE.group;

	if (cin.fail()){
		cerr << "\n\nОшибка: введен некорректный символ. Завершениепрограммы...\n";
		exit(EXIT_FAILURE);
	}
	cout << "Введите площадь территории, занимаемой государством: ";
	cin >> newSTATE.rating;

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

//удалить из файла студентов с низким рейтингом (4.3)
void DelFileMinRating(const char* filename, const int& limit)
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
		if (tmp.rating > limit) f2.write((char*)&tmp, sizeof(tmp));
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
		cout << tmp.name << '\n' << tmp.capital << '\n' << tmp.group << '\n' << tmp.rating << "\n\n";
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

	STATE newSTATE;
	cout << "Укажите количество студенов: ";
	int n;
	cin >> n;// указали кол студентов
	cout << endl;

	const char* filename = "Countries.bin";

	for (int i = 0; i < n; i++)
  	{
		STATE tmp = createState();
		cout << "Записываем государство " << tmp.name << " в файл "<< filename << "...\n\n";
		StateFileEnd(filename, tmp);
	}

	PrintFile(filename);

	const float limit = 4.3;
	cout << "Удаляем информацию о государствах, с малым количеством населения из файла " <<filename<< "...\n\n";
	DelFileMinRating(filename, limit);
	cout << "Что осталось " <<filename<< "...\n\n";
	PrintFile(filename);// вы
	cout << "Укажите информацию о государстве, которое хотите добавить в файл.\n\n";
	newSTATE = createState();
	cout << "\nУкажите позицию, которую государство должно занять(кроме 1) : ";
	int num;
	cin >> num;
	cout << endl;
	cout << "Добавляем государство " << newSTATE.name << " в файл "<< filename << "...\n\n";
	//AddState(filename, num - 1, newSTATE);
	PrintFile(filename);

	return 0;
}
