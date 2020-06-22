# include<iostream>
using namespace std;

class Employee // класс работник
{
    public:
    virtual void goToWork() = 0 // =0 говорит о том что метод чисто виртуальный 
    {// метод иди работай
        cout << " Employee go work " << endl;
    }
};

class Manager : public Employee
{
        void goToWork()
    {
        cout << " Manager go work " << endl;
    }
};

class Developer : public Employee
{
        void goToWork()
    {
        cout << " Developer go work " << endl;
    }
};

class Designer : public Employee
{
        void goToWork()
    {
        cout << " Designer go work " << endl;
    }
};

int main()
{
    //сщздаём указатели
    Employee* empl;
    // выделяе память
    Manager* min = new Manager;
    Developer* dev = new Developer;
    Designer* des = new Designer;

    empl = des;
    // если не сделать goToWork() virtual тщ будет  вызыватся метод ародительского класса
    // 
    //empl -> goToWork();
    empl = min;
    //empl -> goToWork();
    empl = dev;
    //empl -> goToWork();
    // использоанеи массивов
    // акк virtual  class облехчае кд
    Employee* mas[3]={min, dev, des};
    // mas[0] = min;
    // mas[1] = dev;
    // mas[2] = des;
    for(int i=0; i<3; i++)
    {
        mas[i]->goToWork();
    }
    return 0;
}