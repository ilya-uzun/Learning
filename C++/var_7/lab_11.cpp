﻿#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdarg>

using namespace std;

class MyList {                                       //Список MyList
    int x, count_;
    MyList* Head, * Tail, * Next, * Prev;
public:
    MyList() :count_(0), Head(NULL), Tail(NULL) {};     //Инициализация с помощью конструктора по умолчанию
    /*ДОБАВЛЕНИЕ ЭЛЕМЕНТА В СПИСОК*/
    void Add(int x){
        MyList* temp = new MyList;
        temp->x = x;
        temp->Next = NULL;
        count_++;
        if (!Head) {
            temp->Prev = NULL;
            Head = temp;
            Tail = Head;
        }
        else {
            temp->Prev = Tail;                  
            Tail->Next = temp;                
            Tail = temp;                        
        }
    }
    /*ПОКАЗЫВАЕТ СПИСОК НА ЭКРАНЕ*/
    void Show(){
        MyList* t = Head;
        while (t) {
            cout << t->x << " ";
            t = t->Next;
        }
        cout << "\n\n";
    }
    /*ФУНКЦИЯ УДАЛЕНИЯ  ЭЛЕМЕНТА ДВУСВЯЗНОГО СПИСКА*/
    void Del(int x){ //Функция принимает целочисленный параметр, обозначающий номер удаляемого элемента
     //удаляем первый элемент
        if ((x == 1) and (Head->Next)) {                     
            MyList* temp = Head;	                        //Указываем, что нам нужно начало списка
            Head = Head->Next;	                            
            Head->Prev = NULL;	                            //Делаем так, чтоб предыдущий началу элемент был пустым
            delete temp;		                            //Удаляем удаляемое начало
            count_--;		                                //Обязательно уменьшаем счетчик
            return;		                                    //И выходим из функции
        }
        else if ((x == 1) and (Head == Tail)) {           

            Head->Next = NULL;	                            //обнуляем все что нужно
            Head = NULL;
            delete Head;		                            //Удаляем указатель на начало
            count_ = 0;		                                //обозначаем, что в списке ноль элементов
            return;			                                //выходим из функции
        }

        // удаляемый элемент является последним элементом списка
         if (x == count_) {
            MyList* temp = Tail;	                            //Указываем, что нам нужен конец
            Tail = Tail->Prev;	                                
            Tail->Next = NULL;	                                //Обозначаем, что впереди  пусто
            delete temp;	                                    //Очищаем память 
            count_--;		                                    //Обязательно уменьшаем счетчик элементов
            return;		                                        //И выходим из функции
            }

        //удаляемый элемент лежит где-то в середине списка
        MyList* temp = Head, * temp2;                        //temp-Удаляемый элемент, temp2 нужен, чтобы не потерять данные

        cout<<count_<<"\n";
        for (int i = 0; i < x - 1; i++) temp = temp->Next;  //Идем к адресу удаляемого элемента

        temp2 = temp;	                                //Временно запоминаем адрес удаляемого элемента
        temp2->Prev->Next = temp->Next;	                //Записываем данные, что следующий за перед сейчас удаляемым элементом - это следующий от удаляемого
        temp2->Next->Prev = temp->Prev;                 //а предыдущий для следующего - это предыдущий для удаляемого
        delete temp;                                    //теперь смело можно освободить память, удалив адрес на начало удаляемого элемента
        count_--;                                        //Обязательно уменьшаем число элементов в списке.
    }
    /*ФУНКЦИЯ УДАЛЕНИЯ ДВУСВЯЗНОГО СПИСКА*/
    void DelAll(){
        while (Head) {
        Tail = Head->Next;
        delete Head;
        Head = Tail;       
        }
    }
    /*ФУНКЦИЯ ЗАПИСТЬ СПИСКА В ФАЙЛ*/
    void WriteFile (const char* filename) {
            ofstream fout(filename, ios::out);
            MyList* temp = Head;
            
            if (!fout.is_open()){
                cout << "Не удалось открыть файл." << '\n';
            return;
            }

            while (temp != nullptr)
            {
                fout << temp->x << ' ';
                temp = temp->Next;
            } 
           
                fout << '\n';
                fout.close();
        } 

    /*ФУНКЦИЯ ЧТЕНИЕ СПИСКА ИЗ ФАЙЛ*/
    void ReadFile (const char* filename) {
            ifstream fout(filename);
            MyList* temp = new MyList;
            
            if (!fout.is_open()){
                cout << "Не удалось открыть файл." << '\n';
            return;
            }
        cout << "файл открыть файл для чтения ." << '\n';
            int n = 0;
            while (!fout.eof()) {
                n++;  // считаем количество циклов  
                cout << n << '\n';
            }
            
            while (n != 0) {
                int in_temp = 0;
                fout>>in_temp;
                temp->Add(in_temp);
                if (!fout.eof()) temp->Show();
            }       
            fout.close();
            delete temp;
    }  
    /*ДЕСТРУКТОР ДЛЯ КОРРЕКТНОГО ВЫСВОБОЖДЕНИЯ ПАМЯТИ*/                               
    ~MyList(){
        while (Head) {
        Tail = Head->Next;
        delete Head;
        Head = Tail;
        }
    }
};

int main() {
    MyList List1;
    List1.Add(10);
    List1.Add(20);
    List1.Add(30);
    List1.Add(40);
    List1.Add(50);
    List1.Show();  // вывод в консоль
    List1.Del(1);  //обозначаем какой элемент удаляем
    List1.Show();   // вывод в консоль
    List1.Add(1000);// обозначаем какой элемент добавляем в конец
    List1.Show();   // вывод в консоль

    const char filename[15] = "myList.txt";        // создаем переменую хронящею 
	cout << "Записываем  в файл..." << '\n';
    List1.WriteFile(filename);

    List1.Show();  // вывод в консоль
    List1.DelAll(); // удаляем все элементы
    List1.Show();   // вывод в консоль
    cout << "Список пуст" << '\n';
    List1.ReadFile(filename);
    List1.Show();
}

//     1. Создание списка.
//     2. Добавление элемента в список (в соответствии со своим вариантом).
//     3. Удаление элемента из списка (в соответствии со своим вариантом).
//     4. Печать списка.

//     5. Запись списка в файл.
//     6. Уничтожение списка.
//     7. Восстановление списка из файла.

    // 1. Написать функцию для создания списка. Функция может создавать пустой список, а затем добавлять в него элементы.
    // 2. Написать функцию для печати списка. Функция должна предусматривать вывод сообщения, если список пустой.
    // 3. Написать функции для удаления и добавления элементов списка в соответствии со своим вариантом.
    // 4. Выполнить изменения в списке и печать списка после каждого изменения.
    // 5. Написать функцию для записи списка в файл.
    // 6. Написать функцию для уничтожения списка.
    // 7. Записать список в файл, уничтожить его и выполнить печать (при печати должно быть выдано сообщение "Список пустой").
    // 8. Написать функцию для восстановления списка из файла.
    // 9. Восстановить список и распечатать его.
    // 10. Уничтожить список.

// вар 3
// Записи в линейном списке содержат ключевое поле типа int. 
// Сформировать однонаправленный список. Удалить из него К элементов, начиная с заданного номера, 
// добавить элемент перед элементом с заданным ключом;

// вар 7
// Сформировать двунаправленный список. 
// Удалить из него первый элемент, добавить элемент в конец списка.

