#include "Dialog.h"
//конструктор
Dialog::Dialog(void):Vector()
{
EndState = 0;
}
//деструктор
Dialog::~Dialog(void){}
//получение события
void Dialog::GetEvent(TEvent &event)
{
    std::string OpInt = "+-/sqamh"; //строка содержит коды операций
    std::string s;
    std::string param;
    char code;
    std::cout << '>';
    std::cin >> s; 
    code = s[0];//первый символ команды
    if(OpInt.find(code) >= 0)//является ли символ кодом операции
    {
    event.what = evMessage;
        switch(code)
        {
            case 'm': event.command=cmMake; break;//создать группу, требуется создать в первую очередь иначе ошибка Segmentation fault 
            case '+': event.command=cmAdd; break;//добавить объект в группу
            case '-': event.command=cmDel; break;//удалить объект из группы
            case 'a': event.command=cmAverageAge; break;//средний возраст группы
            case 's': event.command=cmShow; break;//просмотр группы
            case '/': event.command=cmGet; break; // показать возраст
            case 'q': event.command=cmQuit; break; //конец работы
            case 'h': event.command=cmHelp; break; //помощь
        }
//выделяем параметры команды, если они есть
        if(s.length()>1)
        {
            param = s.substr(1,s.length()-1);
            int A = atoi(param.c_str());//преобразуем парметр в число
            event.a = A;//записываем в сообщение
        }
    }
    else event.what = evNothing;//пустое событие
}

int Dialog::Execute()
    { TEvent event;
    do{
        EndState = 0;
        GetEvent(event); //получить событие
        HandleEvent(event); //обработать событие
      }
    while(!Valid());
     return EndState;
    }
int Dialog::Valid()
{   
    if (EndState == 0) return 0;
    else return 1;
}

void Dialog::ClearEvent(TEvent& event)
{
    event.what= evNothing;// пустое событие
}
void Dialog::EndExec()
{
    EndState = 1;
}
//обработчик событий
void Dialog::HandleEvent(TEvent& event)
{
  if( event.what == evMessage)
  {
    switch( event.command )
    {
    case cmMake://создание группы
        size = event.a; //размер группы
        beg = new Object*[size];//выделяем память под массив указателей
        cur = 0; //текущая позиция
        ClearEvent(event);//очищаем событие
    break;
    case cmAdd://добавление
        Add();
        ClearEvent( event ); 
    break;
    case cmDel:Del(); //удаление
         ClearEvent( event ); 
    break;
    case cmAverageAge:AverageAge(); //просмотр
        ClearEvent( event ); 
    break;
    case cmShow:Show(); //просмотр
        ClearEvent( event );
    break;
    case cmQuit:EndExec(); //выход
         ClearEvent( event ); //очищаем событие
    break;
    case cmHelp: //выход
         std::cout << "(m) - create group" << std::endl;
         std::cout << "(+) - add an object to a group" << std::endl;
         std::cout << "(-) - delete an item from a group" << std::endl;
         std::cout << "(a) - average age of the group" << std::endl;
         std::cout << "(s) - viewing a group" << std::endl;
         std::cout << "(/) - Show age" << std::endl;
         std::cout << "(q) - end" << std::endl;
         std::cout << "(h) - help" << std::endl;
         //ClearEvent( event );
    break;
    default:Vector::HandleEvent(event);
    };
  };
 }