#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include"header.h"
#include<malloc.h>
int main()
{
	NODE *head = NULL, *newE = NULL, *crnt = NULL;

	SetConsoleOutputCP(1251);
	do
	{
		newE = (NODE*)malloc(sizeof(NODE));
		if (newE == NULL)
		{
			printf("Не се заделя памет!");
			exit(1);
		}
		printf("\nВъведете име на поредния студент: ");
		scanf("%s", newE->s.name);                          //proverka
		if (!strcmp(newE->s.name,"*"))
		break;
		printf("\nВъведете номер на поредния студент: ");
		scanf("%d", &newE->s.fn);
		if (head == NULL)
		{
			newE->next = NULL;
			head = newE;
        }

	} while (1);
	printf("\nСъдържание на списъка:");
	crnt = head;

	while (crnt != NULL)
	{
		printf("\n Име: %s", crnt->s.name);
		printf("\n Fak number: %d", crnt->s.fn);
		crnt = crnt->next;
	}

	system("pause");

	return 0;
}