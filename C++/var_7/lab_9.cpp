
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std; 

int main()
{
    ifstream finF1("F1.txt"); // открыть для чтения
    ofstream outF2("F2.txt"); // открыть для записи
   
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
            if(strF1[0] != 'A') // выводить строки которые не начинаются на А
            {
                outF2 << strF1 << ' ';
                    for(int i=0; i<=strF1.length(); i++) // переход на новую строку
                        {
                            if(strF1[i] == '.' )
                            outF2 << '\n';
                        }
            } 
      
    }
    finF1.close();
    outF2.close();

    ifstream finF2("F2.txt"); // открыть для чтения
    string strF2;
    if(!finF2.is_open())
    {
        cout << "Error";
        exit(EXIT_FAILURE);
    }
    // считаем символы в первом слове F2
    while (finF2){ // пока есть данные 
    	string strInput;
		finF2 >> strInput;
		cout << strInput << endl;
        cout << strInput.size() << endl; // считаем символы
        break; //
	}
    
    finF2.close();
    
    return 0;
}

    // 1)  Скопировать из файла F1 в файл F2 все строки, кроме тех, что начинаются на букву А. 
    // 2)  Подсчитать количество символов в первом слове F2.