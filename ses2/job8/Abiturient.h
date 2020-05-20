#pragma once
#include "Person.h"
class Abiturient : public Person
{
public:
    Abiturient(void);
public: 
    ~Abiturient(void);
    void Show();
    void Input();
    Abiturient(std::string, int, int);
    Abiturient(const Abiturient & );
    int Get_Person_ID(){return person_ID;}
    void Set_Person_ID(int);
    Abiturient& operator=(const Abiturient&);
protected:
    int person_ID;
};