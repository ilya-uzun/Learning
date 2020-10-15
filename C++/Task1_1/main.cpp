#include <fstream>
#include <string.h>//strcmp
#include <iostream>
#include "Man.h"

using namespace std;

const char filename[] = "dbase.txt";
int main()
 {
    const int maxn_record = 10;
    Man man [maxn_record];
    char buf[l_buf + 1];
    char name[l_name + 1];

    ifstream fin(filename);
    if (!fin) 
    {
        cout << "No file" << filename << endl; return 1;
    }

    int i = 0;
    while (fin.getline(buf, l_buf))
      {
        if (i >= maxn_record)
          {
             cout << "слишком длинный file"; return 1;
          }
        man[i].SetName(buf);
        man[i].SetBirthYear(buf);
        man[i].SetPay(buf);
        i++;
      }
    int n_record = i, n_man = 0;
    float mean_pay = 0;

    while (true)
    {
        cout << "Enter FIO and word end :";
        cin >> name;
        if (0 == strcmp(name, "end")) break;
        bool not_found = true;
        for (i = 0; i < n_record; ++i)
        {
            if (man[i].CompareName(name))
            {
                man[i].Print();
                n_man++;
                mean_pay += man[i].GetPay();
                not_found = false;
                break;
            }
        }
        if (not_found) cout << "Токого сотрудника нет" << endl;
    }
    if (n_man) cout << "Средний оклад: "<< mean_pay / n_man << endl;
    return 0;
 }
