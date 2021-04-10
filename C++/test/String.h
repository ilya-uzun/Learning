//#ifndef __STRING_H_
//#define __STRING_H

#include <cstring>
#include <ostream>

class String{

private:
  char* s;

public:
  String (char*);
  ~String();
  void Dump(std::ostream& os);
};

String::String(char* str) : s (NULL)
{
  if (str == NULL){
    s = new char[1];
    *s = '\0';
  }
  else {
    s = new char [strlen(str)+1];
    strcpy(s,str);
  }
}

String::~String(){
  delete s;
}

void String::Dump(std::ostream& os){
  os << "\"" << s << "\"";
}
//#endif // __STRING_H_
