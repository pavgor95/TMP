#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <string.h>
#include <locale>
struct String
{
	char stroka[64];
};
void print(String *s, int n, FILE *pFile) // Печать массива (на экран или в файл)
{
	for (int i = 0; i<n; i++)
		fprintf(pFile, "%s\n", s[i].stroka);
}
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	String *pString1;
	String *pString2;
	FILE *pFile1;
	FILE *pFile2;
	pFile1 = fopen("file1", "rt");
	pFile2 = fopen("file2", "rt");
	if (pFile1 == 0)
	{
		printf("Error!! File not found");
		system("pause");
		return 0;
	}
	if (pFile2 == 0)
	{
		printf("Error!! File not found");
		system("pause");
		return 0;
	}
	char Str1[256], Str2[256];
	int n1 = 0, n2 = 0; // Число объектов
	while (!feof(pFile1)) // Считаем число строк в файле
	{
		if (fgets(Str1, 255, pFile1))	n1++;
	}
	while (!feof(pFile2)) // Считаем число строк в файле
	{
		if (fgets(Str2, 255, pFile2))	n2++;
	}
	pString1 = new String[n1];
	pString2 = new String[n2];
	rewind(pFile1);
	rewind(pFile2);
	for (int i = 0; i<n1; i++)
	{
		fscanf(pFile1, "%s", pString1[i].stroka);
	}
	for (int i = 0; i<n2; i++)
	{
		fscanf(pFile2, "%s", pString2[i].stroka);
	}
	printf("file1: \n"); print(pString1, n1, stdout);
	printf("file2: \n"); print(pString2, n2, stdout);
	printf("\n\n");
	for (int i = 0; i<n1; i++)
	{
		for (int j = 0; j<n2; j++)
		{
			if (strcmp(pString1[i].stroka, pString2[j].stroka) == 0) break;
			else if ((strcmp(pString1[i].stroka, pString2[j].stroka) != 0) && ((j + 1) == n2))
			{
				printf("file1: %s\n", pString1[i].stroka); break;
			}
		}
	}
	for (int i = 0; i<n2; i++)
	{
		for (int j = 0; j<n1; j++)
		{
			if (strcmp(pString2[i].stroka, pString1[j].stroka) == 0) break;
			else if ((strcmp(pString2[i].stroka, pString1[j].stroka) != 0) && ((j + 1) == n1))
			{
				printf("file2: %s\n", pString2[i].stroka); break;
			}
		}
	}
	system("pause");
	return 0;
}
