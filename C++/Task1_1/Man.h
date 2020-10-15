#ifndef MAN_H
#define MAN_H

//глобальные переменные
const int l_name = 30;
const int l_year = 5;
const int l_pay = 10;
const int l_buf = l_name + l_year + l_pay;

class Man
{
public:
    Man(int LName = 30);
    ~Man();
    bool CompareName(const char*) const;
    int GetBirthTear() const { return birth_year;}
    float GetPay() const {return pay;}
    char* GetName() const {return pName;}// метод возвращает *pName
    void Print() const;
    void SetBirthYear(const char*);
    void SetName(const char*);
    void SetPay(const char*);
private:
    char* pName;
    int birth_year;
    float pay;
};
#endif // MAN_H
