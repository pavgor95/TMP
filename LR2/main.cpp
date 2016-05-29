#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	string str;
	ifstream file("text.txt");
	getline(file, str, '\0');
	file.close();
	int size = str.length();
	int i = 0;

	while (i<size)
	{
		if ((str[i] == '/') && (str[i + 1] == '*') && (str[i + 2] == '*'))
		{
			i += 3;
			while (str[i] != '\\')
			{
				i++;
			}

			while ((str[i] != ' ') && (str[i] != '\n'))
			{
				i++;
			}
			i++;

			while ((str[i] != '*') || (str[i + 1] != '/'))
			{
				if (str[i] == '\n');
				else cout << str[i];
				i++;
			}
			cout << endl;
			i++;
		}
		i++;
	}
	system("pause");
	return 0;
}