Программа:

#include<iostream>
#include <vector>
#include <string>
#include <fstream>
// #include <windows.h>

using namespace std;

vector<string> ReadFile(const char* filename){
	ifstream fin(filename, ios::in);

	if (!fin.is_open()){
		cout << "Не удалось открыть файл. Завершение программы...";
		exit(EXIT_FAILURE);
	}

	vector<string> content;
	string str;
	while (getline(fin, str))
		content.push_back(str);

	fin.close();
	return content;
}

vector<string> getTrueContent(const vector<string>& content){
	vector<string> trueContent;

	for (int i = 0; i < content.size(); i++){

		if (content[i].size() < 2) continue;

		int begin = 0;

		int end = pmark(content[i][content[i].size() - 1])
			? content[i].size() - 2
			: content[i].size() - 1;

		if (content[i][begin] + 32 == content[i][end])
			trueContent.push_back(content[i]);
		else if (content[i][begin] == content[i][end])
			trueContent.push_back(content[i]);
	}
	return trueContent;
}

void WrideFile(const char* filename,const vector<string>& content){
	ofstream fout(filename, ios::out);

	if (!fout.is_open()){
		cout << "Не удалось открыть файл. Завершение программы...";
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < content.size(); i++){
		fout << content[i];
		if (i < content.size() - 1)
			fout << '\n';
	}
	fout.close();
}

void СountСharacters(const char* filename)
{
	ifstream fin(filename, ios::in);

	if (!fin.is_open())
  {
		cout << "Не удалось открыть файл. Завершение программы...";
		exit(EXIT_FAILURE);
	}

	int count = 0;
	cout << "Файл \"" << filename << "\" содержит:\n\n";
	string str;

	while (getline(fin, str)){
		cout << str << '\n';
		count += str.size();
	}
	fin.close();
	cout << "\nИтого " << count << " символов.\n";
}

bool pmark(const char& c)
{
	switch (c){
	case ',':
	case '.':
	case '!':
	case '?':
	case ':':
	case ';': return true;
	default: return false;
	}
}

int main()
{
	// SetConsoleCP(1251);
	// SetConsoleOutputCP(1251);
	char mainFile[15] = "F1.txt";
	char newFile[15] = "F2.txt";
	cout << "Считываем текст из файла \"" << mainFile << "\"...\n\n";
	vector<string> mainText = ReadFile(mainFile);
	СountСharacters(mainFile);
	cout << "\nВыбираем строки, которые начинаются и заканчиваются на одну и ту же букву...\n";
	vector<string> newText = getTrueContent(mainText);
	cout << "Помещаем их в файл \"" << newFile << "\"...\n\n";
	WrideFile(newFile, newText);
	СountСharacters(newFile);
	
	return 0;
}
