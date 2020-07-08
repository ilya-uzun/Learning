#include <iostream>

using namespace std;

typedef std::string fulName;
typedef int  TexId;
typedef int jobClassification;


class Employee
{
public:
// открытай конструкторы и деструкторы
    Employee();
    Employee(
      fulName name,
      string address,
      string workPhone,
      string homePhon,
      TexId texIdNumber,
      jobClassification jobClass
    );
    virtual ~Employee();
// открытые методы
    fulName GetName() const;
    string GetAddress() const;
    string GetWorkPhone() const;
    string GetHomePhone() const;
    TexId GetTaxIdNumber() const;
    jobClassification GetjobClassification() const;
private:
};


int main ()
{

}
