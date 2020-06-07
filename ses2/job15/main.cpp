#include "Person.h"
// #include "File_work.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Manager.h"

using namespace std;
int main()
{ 
  Manager manager;    //Менеджер СУБД
  Person p, p1, p2;
  int k, c;
  char file_name[100];
  do
  { //Меню
      cout <<"\n1. Output hash table entries to the console";// вывода записей хэш-таблицы в консоль
      cout <<"\n2. Searching for an entry in a hash table";// поиска записи в хэш-таблице
      cout <<"\n3. Edit the entry in the hash table";// редактирования записи хэш-таблицы
      cout <<"\n4. deleting a hash table entry";// удаления записи хэш-таблицы
      cout <<"\n5. Squeak of collisions";// тестирования хэш-таблицы на коллизии
      cout <<"\n0. Exit\n";//
      cin >> c;
    
  switch(c)
    {
      case 1: 
        // cout << "Title data base : "; 
        // cin >> file_name;
        // k = make_file(file_name);
        // if (k < 0 ) cout << "Can't make file";
        manager.printHashPerson();
      break;

      case 2: 
        // cout << "file name data base ?"; 
        // cin >> file_name;
        // k = print_file(file_name);
        // if(k==0) cout<<"Empty file\n";
        // if(k<0) cout<<"Can't read file\n";
        manager.searchElement(); 
      break;

      case 3: 
        // cout <<"file name data base ?"; 
        // cin >> file_name;
        // int nom; 
        // cout << "Number ?"; 
        // cin>>nom;
        // k = del_file(file_name,nom);
        // if(k<0) cout << "Can't read file"; 
        manager.editElement();  
      break;

      case 4:
        // cout << "file name data base ?";
        // cin >> file_name;
        // cout << "Number ?"; 
        // cin>>nom;
        // cout<< "New person: ";
        // cin >> p1;
        // k = add_file(file_name,nom,p1);
        // if(k<0) cout << "Can't read file";
        // if(k==0) k = add_end(file_name,p1);//
        manager.removeElement();  
      break;

      case 5: 
        // cout << "file name data base  ?";
        // cin >> file_name;
        // cout << "Number ?"; 
        // cin >> nom;
        // cout << "New person:";
        // cin >> p2;
        // k = change_file(file_name, nom, p2);
        // if(k<0) cout<<"\nCan't read file";
        // if(k==0) cout<<"\nNot such record";
        manager.testCollisions(); 
      break;
    } // switch(c) 
  }//do
while(c!=0);
}


