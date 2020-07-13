#include "classmath.h"

// консруктор без параметров
ClassMath::ClassMath(void)
{
    number1 = 0;
    number2 = 0;
}
//деструктор
ClassMath::~ClassMath(void){}

//Конструктор копирования
ClassMath::ClassMath(const ClassMath& classmath)
{
    number1 = classmath.number1;
    number2 = classmath.number2;
}
//модификаторы
int ClassMath::set_number1 (int n)
{
    number1 = n;
    return number1;
}
int ClassMath::set_number2 (int n)
{
    number1 = n;
    return number2;
}

//метод сложения
int summe_number (int n1, int n2)
{
    int summe = 0;
    summe = n1 + n2;
    return summe;
}
