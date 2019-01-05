#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "struct_def.h"
#include "function_s.h"

void start_file()
{

	FILE* fp;
	int i;
	int flag;

	if ((fp = fopen("tablica", "rb")) == NULL)
	{
		printf("Error open file!");
		exit(0);
	}

	while (1)
	{
		if (fread(&flag, sizeof(int), 1, fp) != 1)
		{
			printf("Error reading1");

			exit(4);
		}
		if (flag == -1)
			break;

		struct person* temp = (struct person*)malloc(sizeof(struct person));
		if (head == NULL)
		{
			head = temp;
			current = head;
			current->next = NULL;
		}
		else
		{
			current->next = temp;
			current = temp;
			current->next = NULL;
		}
		/*  if(fread(&j,sizeof(int),1,fp)!=1){
			  printf("error");
			  exit (19);
			  }*/
		if ((fread(temp->full_name, flag, 1, fp)) != 1) {
			printf("error");
			exit(20);
		}
		if ((fread(&i, sizeof(char), 1, fp)) != 1) {
			printf("error");
			exit(21);
		}
		if ((fread(temp->faculty, i, 1, fp)) != 1) {
			printf("error");
			exit(22);
		}
		if ((fread(&i, sizeof(char), 1, fp)) != 1) {
			printf("error");
			exit(23);
		}
		if ((fread(temp->major, i, 1, fp)) != 1) {
			printf("error");
			exit(24);
		}
		if ((fread(&i, sizeof(char), 1, fp)) != 1) {
			printf("error");
			exit(25);
		}
		if ((fread(&temp->group, sizeof(int), 1, fp) != 1)) {
			printf("error");
			exit(26);
		}
		if ((fread(&temp->study_year, sizeof(int), 1, fp) != 1)) {
			printf("error");
			exit(27);
		}
		if ((fread(&temp->fac_num, sizeof(int), 1, fp) != 1)) {
			printf("error");
			exit(28);
		}
	}
	fclose(fp);
}
void add_student()
{

	struct person* temp;
	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	struct person* new_element;
	new_element = (struct person*) malloc(sizeof(struct person));
	printf("Въведете ново име: ");
	scanf("%s", new_element->full_name);
	printf("Въведете новият факултет: ");
	scanf("%s", new_element->faculty);
	printf("Въведете новата специалност: ");
	scanf("%s", &new_element->major);
	printf("Въведете новата група: ");
	scanf("%d", &new_element->group);
	printf("Въведете новият курс (1-4): ");
	scanf("%d", &new_element->study_year);
	printf("Въведете новият факултетен номер: ");
	scanf("%d", &new_element->fac_num);

	new_element->next = NULL;
	temp->next = new_element;
	printf("\nВъвеждането на нов студент : УСПЕШНО!\n\n");
}
void search_student_by_faculty_number()
{
	char* arr;
	int flag = 0;
	arr = (char*)malloc(20);
	printf("Въведете факултетният номер : \n \n");
	gets(arr);
	struct person* temp;
	temp = (struct person*)malloc(sizeof(struct person));
	temp = head;
	while (temp != NULL)
	{
		if (!(strcmp(&temp->full_name, arr))) {
			printf("Цялото име е: %s  Факултетът е: %d  Специалността е: %s   Групата е: %d  Курсът е: %d  Факултетният номер е: %d\n \n", temp->full_name, temp->faculty, temp->major, temp->group, temp->study_year, temp->fac_num);
			flag = 1;
		}
		temp = temp->next;
	}
	if (flag == 0) printf("Can't find brand - %s \n \n", arr);
}
void del_student_by_faculty_name()
{
	struct person* prev_item = head;
	struct person* curr_item = head;
	int f = 0;
	char* arr;
	arr = (char*)malloc(20);
	printf("Въведете факултетният номер на студента : \n");
	gets(arr);
	while (curr_item != NULL)
	{
		if (strcmp(curr_item->fac_num, arr) == 0)
		{
			if (curr_item == head)
			{
				head = head->next;
				prev_item = head;
				f = 1;
			}
			else
				prev_item->next = curr_item->next;
			free(curr_item);
			curr_item = prev_item;
		}
		prev_item = curr_item;
		if (f == 0)
			curr_item = curr_item->next;
		f = 0;
	}
}
void list_student_sort_alph()
{
	struct person* temp;
	double sr = 0;
	int br = 0;
	temp = head;
	char* arr;
	arr = (char*)malloc(20);
	printf("Въведете групата която искате да се изведе: \n");
	gets(arr);

	while (temp != NULL) {
		sr = sr + temp->study_year;
		br++;
		temp = temp->next;
	}
	sr = sr / br;
	printf("tova e greshno > %d are :\n", sr);
	temp = head;
	while (temp != NULL) {
		if (temp->fac_num > sr)
			if (strcmp(temp->full_name, arr) == 0)
				printf("Цялото име е: %s  Факултетът е: %d  Специалността е: %s   Групата е: %d  Курсът е: %d  Факултетният номер е: %d\n \n", temp->full_name, temp->faculty, temp->major, temp->group, temp->study_year, temp->fac_num);
		temp = temp->next;
	}
}
void end_of_program() {
	FILE* fp;
	int flag = -1;
	if ((fp = fopen("tablica", "wb")) == NULL) {
		printf("Error open file!");
		exit(0);
	}
	struct person* temp;
	temp = head;
	int j;
	int i;
	int k;
	int t;
	while (temp != NULL) {
		j = strlen(temp->fac_num); j++;
		i = strlen(temp->faculty); i++;
		k = strlen(temp->full_name); k++;
		t = strlen(temp->major); t++;

		if (fwrite(&j, sizeof(int), 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		if (fwrite(temp->fac_num, j, 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		if (fwrite(&i, sizeof(int), 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		if (fwrite(temp->faculty, i, 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		if (fwrite(temp->major, t, 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		if (fwrite(&temp->group, sizeof(int), 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		if (fwrite(&k, sizeof(int), 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		if (fwrite(temp->full_name, k, 1, fp) != 1) {
			printf("Error");
			exit(1);
		}
		if (fwrite(&temp->study_year, sizeof(int), 1, fp) != 1) {
			printf("Error");
			exit(1);
		}

		temp = temp->next;
	}
	if (fwrite(&flag, sizeof(int), 1, fp) != 1) {
		printf("Error");
		exit(1);
	}
	fclose(fp);
}