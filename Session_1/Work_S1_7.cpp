#include <cstdio>
using namespace std;


bool glas(const char& c)
{
	switch (c)
  {
		case 'a':
		case 'e':
		case 'o':
		case 'i':
		case 'u':
		case 'A':
		case 'E':
		case 'O':
		case 'I':
		case 'U': return true;
		default: return false;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	const int size = 257;
	char str[size];

	cout << " Введите слова не более 255:\n";
	fgets(str, size, stdin);

	cout << "\nСлова не содержащие гласные:\n";
	for (int i = 0; i < size; i++)
  {
		int count = 0;
		int temp = i;

		while (str[i] != ' ' && str[i] != '\0')
    {
			if (glas(str[i]))
				count++;
			i++;
		}

		if (count == 0)
    {
			for (int j = temp; j < i; j++) cout << str[j];

			if (str[i] == '\0')
				break;
			else
      cout << str[i];
     }

     while (str[i + 1] == ' ') i++;
   }
cout << endl;
system("pause");
return 0;
}
