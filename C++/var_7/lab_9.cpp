// #include <iostream>
// #include <vector>
// #include <string>
// #include <fstream>

// using namespace std;

// // bool pmark(const char& c)
// // {
// // 	switch (c){
// // 	case 'А': // кирилица
// // 	case 'а': // кирилица
// // 	case 'A':
// // 	case 'a': return true;
// // 	default: return false;
// // 	}
// // }

// vector<string> ReadFile(const char* filename){
	
// 	ifstream fin(filename, ios::in);
// 	if (!fin.is_open()){
// 		cout << "Не удалось открыть файл. Завершение программы...";
// 		exit(EXIT_FAILURE);
// 	}

// 	vector<string> content;
// 	string str;
// 	while (getline(fin, str))
// 		content.push_back(str);

// 	fin.close();
// 	return content;
// }
// // Запись из фала F1 в f2
// void WrideFile(const char* filename, vector<string>& content){
	
// 	ofstream fout(filename, ios::out);
// 	if (!fout.is_open()){
// 		cout << "Не удалось открыть файл. Завершение программы...";
// 		exit(EXIT_FAILURE);
// 	}

// 	for (int i = 0; i < content.size(); i++){
// 		fout << content[i];
// 	 	if (i < content.size() - 1)
// 	 		fout << '\n';
// 	 }
// 	fout.close();
// }
// // позволяет перезаписать файл только с одинаковыми символами
// vector<string> getTrueContent(const vector<string>& content){
	
// 	vector<string> trueContent;
//     string str;

// 	for (int i = 0; i < content.size(); i++){

// 		if (str[0] == 'A')
// 			trueContent.push_back(content[i]);
// 	}
// 	return trueContent;

    

//     // while(in >> str)
//     // {
//     //     if(str[0] == 'A')
//     //         out << str << std::endl;
//     // }

// 	// for (int i = 0; i < content.size(); i++){

// 	// 	if (content[i].size() < 2) continue;

// 	// 	int begin = 0;

// 	// 	int end = pmark(content[i][content[i].size() - 1])
// 	// 		? content[i].size() - 2
// 	// 		: content[i].size() - 1;

// 	// 	if (content[i][begin] + 32 == content[i][end])
// 	// 		trueContent.push_back(content[i]);
// 	// 	else if (content[i][begin] == content[i][end])
// 	// 		trueContent.push_back(content[i]);
// 	// }
// 	// return trueContent;
// }



// // подсчет символов
// void count_characters(const char* filename)
// {
// 	// Открываем файл
// 	ifstream fin(filename, ios::in);
	
// 	if (!fin.is_open())
//  	 {
// 		cout << "Не удалось открыть файл. Завершение программы...";
// 		exit(EXIT_FAILURE);
// 	 }

// 	int count = 0;
// 	cout << "Файл \"" << filename << "\" содержит:\n\n";
// 	string str;

// 	while (getline(fin, str)){
// 		cout << str << '\n'; //вывод содержания файла по строчно
// 		count += str.size();
// 	}
// 	fin.close(); // закрываем файл
// 	cout << "\nИтого " << count << " символов.\n";
// }

// int main()
// {

// 	char mainFile[15] = "F1.txt";
// 	char newFile[15] = "F2.txt";
// 	cout << "Считываем текст из файла \"" << mainFile << "\"...\n\n";
// 	vector<string> mainText = ReadFile(mainFile);
// 	count_characters(mainFile); // вывод символов
// 	cout << "\nВыбираем строки, которые начинаются и заканчиваются на одну и ту же букву...\n";
// 	vector<string> newText = getTrueContent(mainText);
// 	cout << "Помещаем их в файл \"" << newFile << "\"...\n\n";
// 	WrideFile(newFile, newText);
	
// 	count_characters(newFile);// вывод символов
	
// 	return 0;
// }



#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std; 

int main()
{
    ifstream finF1("F1.txt");
    ofstream outF2("F2.txt");
    string strF1;
     // проверка открытия файла
    if(!finF1.is_open())
    {
        cout << "Error";
        exit(EXIT_FAILURE);
    }
  
    // Переносим слова на А в файл F2
    while(finF1 >> strF1)
    {
        if(strF1[0] != 'A')  
        outF2 << strF1 << endl;
    }
    finF1.close();
    outF2.close();

    int number;
    ifstream finF2("F2.txt");
    string strF2;
    if(!finF2.is_open())
    {
        cout << "Error";
        exit(EXIT_FAILURE);
    }
    // считаем символы в первом слове F2
    
     
    while (!finF2.eof() ){
        int sum;
		cout << strF2 << '\n'; //вывод содержания файла по строчно
		sum += strF2.size();
        cout << sum << '\n'; 
	}

    finF2.close();
    
    return 0;
}

// пример подсчёта первого слова .. попробовать внести его в функцию
// void getText () {
//      std::vector<int> numbers;
//      int number;
//      std::ifstream file("file_name.txt")
//      if (!file) {
//           std::cout << "error open file file_name.txt" << std::endl;
//           return;
//      }
//      while(!file.eof()) {
//          file >> number;
//          numbers.push_back(number);
//      }
// }


    // 1)  Скопировать из файла F1 в файл F2 все строки, кроме тех, что начинаются на букву А. 
    // 2)  Подсчитать количество символов в первом слове F2.