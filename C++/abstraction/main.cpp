#include <iostream>

using namespace std;

class Employee
{
public:
// открытай конструкторы и деструкторы
    Employee();
    Employee(
      FulName name,
      String address,
      String workPhone,
      String homePhon,
      TexId taxIdNumber,
      jobClassification jobClass
    );
    virtual ~Employee();
// открытые методы
    FullName GetName() const;
    String GetAddress() const;
    String GetWorkPhone() const;
    String GetHomePhone() const;
    TaxId GetTaxIdNumber() const;
  jobClassification GetjobClassification() const;
private:
};


int main ()
{

}