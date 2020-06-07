#include "Person.h"
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
        manager.printHashPerson();
      break;

      case 2: 
        manager.searchElement(); 
      break;

      case 3:  
        manager.editElement();  
      break;

      case 4:
        manager.removeElement();  
      break;

      case 5: 
        manager.testCollisions(); 
      break;
    } // switch(c) 
  }//do
while(c!=0);
}


