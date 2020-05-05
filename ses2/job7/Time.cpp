#include "Time.h"
Time::Time(void)
{
min=sec=0;
}
Time::Time(int M, int S)
{
min=M;sec=S;
}
Time::Time(const Time&t)
{
min=t.min;
sec=t.sec;
}
Time&Time::operator =(const Time &t)
{
min=t.min;
sec=t.sec;
return*this;
}
Time Time::operator+(Time k)
{
int t=min*60+sec;
int kt=k.min*60+k.sec;
t+=kt;
Time temp(t/60,t%60);
return temp;
}
std::ostream&operator<<(std::ostream&out, const Time&t)
{
out<<t.min<<" : "<<t.sec;
return out;
}
std::istream&operator>>(std::istream&in,Time&t)
{
std::cout<<"\nmin?"; in>>t.min;
std::cout<<"\nsec?";in>>t.sec;
return in;
}