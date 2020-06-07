#include "Person.h"
#include "File_work.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{ 
  Person p, p1, p2;
  int k, c;
  char file_name[100];
  do
  { //Меню
      cout <<"\n1. Make file";// создать файл
      cout <<"\n2. Print file";// печать файла
      cout <<"\n3. Delete record from file";// Удалить запись из файла
      cout <<"\n4. Add record to file";// Добавить запись в файл
      cout <<"\n5. Change record in file";// Изменение записи в файле
      cout <<"\n0. Exit\n";//
      cin >> c;
    
  switch(c)
    {
      case 1: 
        cout << "Title data base : "; 
        cin >> file_name;
        k = make_file(file_name);
        if (k < 0 ) cout << "Can't make file";
      break;

      case 2: 
        cout << "file name data base ?"; 
        cin >> file_name;
        k = print_file(file_name);
        if(k==0) cout<<"Empty file\n";
        if(k<0) cout<<"Can't read file\n";
      break;

      case 3: 
        cout <<"file name data base ?"; 
        cin >> file_name;
        int nom; 
        cout << "Number ?"; 
        cin>>nom;
        k = del_file(file_name,nom);
        if(k<0) cout << "Can't read file";  
      break;

      case 4:
        cout << "file name data base ?";
        cin >> file_name;
        cout << "Number ?"; 
        cin>>nom;
        cout<< "New person: ";
        cin >> p1;
        k = add_file(file_name,nom,p1);
        if(k<0) cout << "Can't read file";
        if(k==0) k = add_end(file_name,p1);//
      break;

      case 5: 
        cout << "file name data base  ?";
        cin >> file_name;
        cout << "Number ?"; 
        cin >> nom;
        cout << "New person:";
        cin >> p2;
        k = change_file(file_name, nom, p2);
        if(k<0) cout<<"\nCan't read file";
        if(k==0) cout<<"\nNot such record";
      break;
    } // switch(c) 
  }//do
while(c!=0);
}


