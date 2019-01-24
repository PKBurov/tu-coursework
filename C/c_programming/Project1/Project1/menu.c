#include <stdio.h>
#include <stdlib.h>

int menu(char* t[])
{
	int k, i = 1;
	char ch;

	printf("\n%s\n", t[0]);
	for (i; (t[i]); i++)
		printf("\n<%d> - %s", i, t[i]);
	printf("\n\nИзбор : ");

	do
	{
		ch = _getch();
		k = ch - '0';
	} while (k <= 0 || k > i);
	printf("%c\n", ch);
	return ch - '0';
}