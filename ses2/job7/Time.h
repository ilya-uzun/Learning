#include <iostream>

class Time
{
public:
Time(void);
Time(int, int);
Time(const Time&);
Time&operator=(const Time&);
Time operator+(Time k);
//перегруженные операции ввода-вывода
friend std::ostream& operator<< (std::ostream& out, const Time&);
friend std::istream& operator>> (std::istream& in, Time&);
public:
virtual ~Time(void){};
private:
int min,sec;
};