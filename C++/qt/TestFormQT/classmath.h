#ifndef CLASSMATH_H
#define CLASSMATH_H

class ClassMath
{
public:
    ClassMath(void);
    virtual ~ ClassMath(void);
    ClassMath(int, int); // конструктор c парамметрами
    ClassMath(const ClassMath&); // конструктор копирования

    int get_number1(){return number1;} //селекторы
    int get_number2(){return number2;}

    int set_number1(int); //модификаторы
    int set_number2(int);

    int summe_number (int, int); //метод сложения
private:
    int number1;
    int number2;
};

#endif // CLASSMATH_H
