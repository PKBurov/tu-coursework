#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"


node * make_lst(node * head, FILE *f)
{
	node * p;
	do{
		p = (node *)malloc(sizeof(node));
		if (p == NULL) { printf("Грешка при заделяне на памет!"); exit(1); }
		p->next = NULL;
		if (!fread(&(p->st), sizeof(STD), 1, f)){
			free(p);
			break;
		}
		p->next = head;
		head = p;
	} while (1);
	return head;
}
node * add(node * head)
{
	int len;
	node *neww = NULL;
	neww = (node *)malloc(sizeof(node));

	printf("Факултетен номер на студента (№), за да прекратите въвеждането си, въведете символа '*':\n");
	do {
		scanf("%9s", neww->st.faculty_number);
		len = strlen(neww->st.faculty_number);
		if (!strcmp(neww->st.faculty_number, "*"))break;
	} while (len != 9);
	printf("Първото име на студента:");
	scanf("%19s", neww->st.student_first_name);
	printf("Презимето на студента:");
	scanf("%19s", neww->st.student_sur_name);
	printf("Фамилното име на студента:");
	scanf("%19s", neww->st.student_familly_name);
	printf("Име на факултета в които студента се обучава:");
	scanf("%19s", neww->st.faculty);
	printf("Име на специалност в която се обучава:");
	scanf("%19s", neww->st.major);
	printf("Ноемра на групата на студента:");
	scanf("%d", &(neww->st.group));
	printf("Година на обучение на студента (курс) :");
	scanf("%d", &(neww->st.year));
	neww->next = head;
	return neww;
}
node * search(node * crnt, char *t)
{
	node * prev = NULL;
	node * head = crnt;
	while (crnt != NULL)
	{
		if (!strcmp(crnt->st.faculty_number, t))break;
		prev = crnt;
		crnt = crnt->next;
	}
	if (crnt == NULL) return 1;

	if (prev == NULL)head = crnt->next;
	else delete(crnt, prev);

	return head;
}
node * free_m(node *crnt){
	node* next;
	printf("\nПаметта е освободена!\n");
	while (crnt){
		next = crnt->next; free(crnt); crnt = next;
	}
	return NULL;
}
node **make_ar(node *head)
{
	node** ps;
	node *crnt; int number = 0; node **p;
	for (crnt = head; crnt; crnt = crnt->next)  // преброяване на възлите
	number++; // добавяне на последниявъзел
	number++;
	ps = (node **)malloc(number * sizeof(node*)); // създаване на масив от указатели към структури
	if (ps == NULL)
	{
		printf("No memory!\n"); exit(1);
	}
	for (p = ps, crnt = head; crnt; crnt = crnt->next) // прехвърляне на възлите в масива
		*p++ = crnt;
	*p = NULL;
	return ps;
}

void search_list(node * crnt, char *t)
{

	while (crnt != NULL)
	{
		if (!strcmp(crnt->st.student_familly_name, t))break;
		crnt = crnt->next;
	}
	if (crnt == NULL)printf("Не намерен");
	else printf(" Първо име на студента: %s / Презиме на студента: %s / Фамилно име на студента: %s / Факултетен номер: %s / Факултет: %s / Група: %d / Специалност: %s / Курс : %d  \n \n", 
		crnt->st.student_first_name, crnt->st.student_sur_name,
		crnt->st.student_familly_name, crnt->st.faculty_number,
		crnt->st.faculty, crnt->st.group, 
		crnt->st.major, crnt->st.year);
	system("pause");
	return;
}
void prt(node *crnt) { // отпечатване на списъка
	printf("\nthe list is:\n");
	while (crnt) {
		printf(" Първо име на студента: %s / Презиме на студента: %s / Фамилно име на студента: %s / Факултетен номер: %s / Факултет: %s / Група: %d / Специалност: %s / Курс : %d  \n \n",
			crnt->st.student_first_name, crnt->st.student_sur_name,
			crnt->st.student_familly_name, crnt->st.faculty_number,
			crnt->st.faculty, crnt->st.group, 
			crnt->st.major, crnt->st.year);

		crnt = crnt->next;
	}
}
void delete(node * crnt, node * prev)
{
	prev->next = crnt->next;
	free(crnt);
	return;
}
void sort(struct node *start, int group)
{
	struct node** array_nodes = make_ar(start);
	int count = 0;
	while (start != NULL)
	{
		count++;
		start = start->next;
	}

	for (int i = 0; i < count; i++)
	{
		for (int j = i; j < count - 1; j++)
		{
			if (strcmp(array_nodes[i], array_nodes[j]) < 0)
			{
				node* t = array_nodes[i];
				array_nodes[i] = array_nodes[j];
				array_nodes[j] = t;
			}
		}
	}

	for (int i = 0; i < count; i++)
	{
		if (array_nodes[i]->st.group == group)
		{
			printf(" Първо име на студента: %s / Презиме на студента: %s / Фамилно име на студента: %s / Факултетен номер: %s / Факултет: %s / Група: %d / Специалност: %s / Курс : %d  \n \n",
				array_nodes[i]->st.student_first_name, array_nodes[i]->st.student_sur_name, 
				array_nodes[i]->st.student_familly_name, array_nodes[i]->st.faculty_number, 
				array_nodes[i]->st.faculty, array_nodes[i]->st.group, 
				array_nodes[i]->st.major, array_nodes[i]->st.year);

		}
	}
}