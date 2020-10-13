#include "Man.h"
#include <iostream>
#include <cstring>

using namespace std:

Man::Man(int lName){
    cout << "Constructor is working" << endl;
    pName = new char[lName + 1 ];
}

Man::~Man(){
    cout << "Destructor is working" << endl;
    delete [] pName;
}

Man::SetName(const char* fromBuf){
    strncpy(pName, fromBuf, l_name);
    pName[l_name] = 0;
}

Man::SetBirthYear(const char* fromBuf){
    birth_year = atoi(fromBuf + l_name); // Узнать про atoi
}

Man::SetPay(const char* fromBuf){
    psy = atof(fromBuf + l_name + l_year); // Узнать про atof
}

bool Man::CompareName(const char* name) const {
    if ((stsrstr(pName, name)) && (pName[strlen(name)] == ' '))
        return true;
    else
        return false;
}

void Man::Print() const {
    cout << pName << birth_year << ' ' << pay << endl;
}
