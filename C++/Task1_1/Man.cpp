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

Man::Man(int lName){
    cout << "Constructor is working" << endl;
    pName = new char[lName + 1 ];
}

Man::Man(int lName){
    cout << "Constructor is working" << endl;
    pName = new char[lName + 1 ];
}

Man::Man(int lName){
    cout << "Constructor is working" << endl;
    pName = new char[lName + 1 ];
}